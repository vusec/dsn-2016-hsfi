#include <pass.h>

#include <BinaryFunction.h>
#include <Dereference.h>
#include <Immediate.h>
#include <InstructionAST.h>

#include <elfio/elfio.hpp>

#include "../../include/edfi/unconditionalize/ucpatch.h"

PASS_ONCE();

#define unconditionalizePassLog(M) (errs() << "UnconditionalizePass: " << M << "\n")
#define unconditionalizePassDbg(M) DEBUG(dbgs() << "UnconditionalizePass [DEBUG]: " << M << "\n")

namespace {

  typedef uint32_t targetptr_t; /* this should not be hardcoded */

  enum patchmode {
    mode_unknown,
    mode_nop,
    mode_unconditional,
  };

  struct patchloc {
    long bb_index;
    enum patchmode mode;
    unsigned long cmp_addr;
    size_t cmp_size;
    unsigned long jmp_addr;
    size_t jmp_size;
    bool found;
  };

  struct patchbyte {
    ELFIO::Elf64_Off offset;
    long bb_index;
    unsigned char value_orig;
    unsigned char value_new;
  };

  bool compare_patchbyte_offset(const struct patchbyte &first, const struct patchbyte &second) {
    return first.offset < second.offset;
  }

  int compare_patchbyte_bbindex_int(const struct patchbyte &first, const struct patchbyte &second) {
    if (first.bb_index < second.bb_index) return -1;
    if (first.bb_index > second.bb_index) return 1;
    if (first.offset < second.offset) return -1;
    if (first.offset > second.offset) return 1;
    return 0;
  }

  bool compare_patchbyte_bbindex(const struct patchbyte &first, const struct patchbyte &second) {
    return compare_patchbyte_bbindex_int(first, second) < 0;
  }

  bool compare_patchloc_bbindex(const struct patchloc &first, const struct patchloc &second) {
    return first.bb_index < second.bb_index;
  }

  class UnconditionalizePass : public ModulePass {

  private:

    static std::string instructionCategoryName(Dyninst::InstructionAPI::InsnCategory cat) {
      switch (cat) {
      case Dyninst::InstructionAPI::c_CallInsn: return "c_CallInsn";
      case Dyninst::InstructionAPI::c_ReturnInsn: return "c_ReturnInsn";
      case Dyninst::InstructionAPI::c_BranchInsn: return "c_BranchInsn";
      case Dyninst::InstructionAPI::c_CompareInsn: return "c_CompareInsn";
      case Dyninst::InstructionAPI::c_NoCategory: return "c_NoCategory";
      default: return "???";
      }
    }

    bool evalConstantExpressionBinary(Dyninst::InstructionAPI::BinaryFunction &expression, unsigned long ip, unsigned long &value) {
      std::vector<Dyninst::InstructionAPI::Expression::Ptr> children;
      unsigned long value1, value2;

      assert((expression.isAdd() ? 1 : 0) + (expression.isMultiply() ? 1 : 0) == 1);

      expression.getChildren(children);
      assert(children.size() == 2);

      if (!evalConstantExpression(*children[0], ip, value1) ||
          !evalConstantExpression(*children[1], ip, value2)) {
	  value = 0;
	  return false;
      }

      if (expression.isAdd()) {
	  value = value1 + value2;
      } else {
	  value = value1 * value2;
      }
      return true;
    }

    bool evalConstantExpressionImmediate(Dyninst::InstructionAPI::Immediate &expression, unsigned long &value) {
      value = expression.eval().convert<unsigned long>();
      return true;
    }

    bool evalConstantExpressionRegister(Dyninst::InstructionAPI::RegisterAST &expression, unsigned long ip, unsigned long &value) {
      if (expression.getID() == Dyninst::x86::eip || expression.getID() == Dyninst::x86_64::rip) {
          value = ip;
          return true;
      }

      value = 0;
      return false;
    }

    bool evalConstantExpression(Dyninst::InstructionAPI::InstructionAST &expression, unsigned long ip, unsigned long &value) {
      Dyninst::InstructionAPI::BinaryFunction *binary;
      Dyninst::InstructionAPI::Immediate *immediate;
      Dyninst::InstructionAPI::RegisterAST *reg;

      binary = dynamic_cast<Dyninst::InstructionAPI::BinaryFunction *>(&expression);
      if (binary) return evalConstantExpressionBinary(*binary, ip, value);

      immediate = dynamic_cast<Dyninst::InstructionAPI::Immediate *>(&expression);
      if (immediate) return evalConstantExpressionImmediate(*immediate, value);

      reg = dynamic_cast<Dyninst::InstructionAPI::RegisterAST *>(&expression);
      if (reg) return evalConstantExpressionRegister(*reg, ip, value);

      value = 0;
      return false;
    }

    bool evalConstantExpressionOrPtr(Dyninst::InstructionAPI::InstructionAST &expression, unsigned long ip, bool &is_pointer, unsigned long &value) {
      std::vector<Dyninst::InstructionAPI::Expression::Ptr> children;
      Dyninst::InstructionAPI::Dereference *dereference;

      dereference = dynamic_cast<Dyninst::InstructionAPI::Dereference *>(&expression);
      if (dereference) {
          is_pointer = true;
	  dereference->getChildren(children);
	  assert(children.size() == 1);
          return evalConstantExpression(*children[0], ip, value);
      } else {
          is_pointer = false;
          return evalConstantExpression(expression, ip, value);
      }
    }

    bool instructionIsBasicBlockTest(Dyninst::InstructionAPI::Instruction::Ptr instruction, unsigned long ip, BPatch_variableExpr *var_inject_bb, long &bb_index) {
      unsigned long immediate = -1;
      bool immediate_found = false;
      bool is_pointer;
      std::vector<Dyninst::InstructionAPI::Operand>::iterator it;
      std::vector<Dyninst::InstructionAPI::Operand> operands;
      bool other_found = false;
      unsigned long value;
      bool var_found = false;

      instruction->getOperands(operands);
      for (it = operands.begin(); it != operands.end(); ++it) {
          if (!evalConstantExpressionOrPtr(*it->getValue(), ip + instruction->size(), is_pointer, value)) {
	      other_found = true;
	  } else if (!is_pointer) {
	      if (immediate_found) {
	          unconditionalizePassLog("Warning: Instruction with multiple immediate operands found at 0x" << std::hex << ip << std::dec << ": " << instruction->format());
		  continue;
	      }
	      if ((targetptr_t) value == (targetptr_t) (ptrdiff_t) var_inject_bb->getBaseAddr()) {
	          unconditionalizePassLog("Warning: Instruction that does not dereference pointer to edfi_inject_bb found at 0x" << std::hex << ip << std::dec << ": " << instruction->format());
		  continue;
	      }
	      immediate = value;
	      immediate_found = true;
	  } else if ((targetptr_t) value == (targetptr_t) (ptrdiff_t) var_inject_bb->getBaseAddr()) {
	      if (var_found) {
	          unconditionalizePassLog("Warning: Instruction with multiple references to edfi_inject_bb found at 0x" << std::hex << ip << std::dec << ": " << instruction->format());
		  continue;
	      }
	      if (it->isWritten()) {
	          unconditionalizePassLog("Warning: Instruction writing edfi_inject_bb found at 0x" << std::hex << ip << std::dec << ": " << instruction->format());
		  continue;
	      }
	      var_found = true;
	  } else {
	      other_found = true;
	  }
      }
      if (!var_found) return false;
      if (!immediate_found) {
	  unconditionalizePassLog("Warning: Instruction reading edfi_inject_bb without immediate operand found at 0x" << std::hex << ip << std::dec << ": " << instruction->format());
	  return false;
      }
      if (other_found) {
	  unconditionalizePassLog("Warning: Instruction reading edfi_inject_bb with unexpected additional operand found at 0x" << std::hex << ip << std::dec << ": " << instruction->format());
	  return false;
      }
      if (instruction->getCategory() != Dyninst::InstructionAPI::c_CompareInsn) {
	  unconditionalizePassLog("Warning: Instruction reading edfi_inject_bb with unexpected category found at 0x" << std::hex << ip << std::dec << ": " << instruction->format());
	  return false;
      }
      if (instruction->getOperation().getID() != e_cmp) {
	  unconditionalizePassLog("Warning: Instruction reading edfi_inject_bb with unexpected operation found at 0x" << std::hex << ip << std::dec << ": " << instruction->format());
	  return false;
      }
      bb_index = immediate;
      return true;
    }

    static bool instructionWritesRegister(
      Dyninst::InstructionAPI::Instruction::Ptr instruction,
      Dyninst::MachRegister reg) {
      std::set<Dyninst::InstructionAPI::RegisterAST::Ptr>::iterator it;
      std::set<Dyninst::InstructionAPI::RegisterAST::Ptr> regsWritten;

      instruction->getWriteSet(regsWritten);
      for (it = regsWritten.begin(); it != regsWritten.end(); ++it) {
          if ((*it)->getID() == reg) return true;
      }
      return false;
    }

    void remove_duplicate_patchlocs(std::list<struct patchloc> &patchlocs) {
      std::list<struct patchloc>::iterator it, itnext;

      patchlocs.sort(compare_patchloc_bbindex);
      it = patchlocs.begin();
      while (it != patchlocs.end()) {
	  itnext = it;
	  itnext++;
	  if (itnext != patchlocs.end() && it->bb_index == itnext->bb_index) {
              if (it->cmp_addr != itnext->cmp_addr ||
	          it->cmp_size != itnext->cmp_size ||
	          it->jmp_addr != itnext->jmp_addr ||
	          it->jmp_size != itnext->jmp_size) {
	          unconditionalizePassLog("Warning: basic block " << it->bb_index <<
		      " found twice, at addresses 0x" << std::hex << it->cmp_addr <<
		      " and 0x" << itnext->cmp_addr << std::dec);
	      }
              unconditionalizePassDbg("Removing duplicate basic block " << it->bb_index <<
	          " found multiple times at 0x" << std::hex << it->cmp_addr << std::dec);
	      patchlocs.erase(it);
	  }
          it = itnext;
      }
    }

    const void *get_elf_data(ELFIO::elfio &reader, unsigned long addrfrom, unsigned long addrto) {
      int secidx;
      ELFIO::section *section;

      assert(addrfrom <= addrto);
      for (secidx = 0; secidx < reader.sections.size(); secidx++) {
	  section = reader.sections[secidx];
          if (addrfrom >= section->get_address() &&
	      addrto < section->get_address() + section->get_size()) {
	      return section->get_data() + addrfrom - section->get_address();
	  }
      }
      unconditionalizePassLog("Warning: Address range 0x" << std::hex << addrfrom << " to 0x" << addrto << std::dec << " not found in ELF file sections");
      return NULL;
    }

    bool get_elf_instructions(ELFIO::elfio &reader, BPatch_basicBlock *bb,
      unsigned long addrfrom, unsigned long addrto,
      std::vector<Dyninst::InstructionAPI::Instruction::Ptr> &instructions) {
      const void *data = get_elf_data(reader, addrfrom, addrto);
      if (!data) return false;

      bb->getInstructions(instructions, data);
      return true;
    }

    void dumpInstructions(std::vector<Dyninst::InstructionAPI::Instruction::Ptr> &instructions, unsigned long addr) {
      Dyninst::InstructionAPI::Instruction::Ptr instruction;
      std::vector<Dyninst::InstructionAPI::Instruction::Ptr>::iterator it;

      for (it = instructions.begin(); it != instructions.end(); ++it) {
           instruction = *it;
           unconditionalizePassLog("Dump: 0x" << std::hex << addr << std::dec << ": " << instruction->format());
	   addr += instruction->size();
      }
    }

    void runOnBasicBlock(ELFIO::elfio &reader, BPatch_basicBlock *bb, BPatch_variableExpr *var_inject_bb, std::list<struct patchloc> &patchlocs) {
      unsigned long addr = bb->getStartAddress();
      unsigned long addrStart = addr;
      long bb_index = -1;
      Dyninst::InstructionAPI::Instruction::Ptr instruction;
      std::vector<Dyninst::InstructionAPI::Instruction::Ptr> instructions;
      std::vector<Dyninst::InstructionAPI::Instruction::Ptr>::iterator it;
      struct patchloc patchloc;
      unsigned long readAddr;

      get_elf_instructions(reader, bb, addr, bb->getEndAddress(), instructions);
      memset(&patchloc, 0, sizeof(patchloc));
      for (it = instructions.begin(); it != instructions.end(); ++it) {
           instruction = *it;
	   addr += instruction->size();
	   if (!instruction->isValid()) {
               unconditionalizePassLog("Warning: Invalid instruction at 0x" << std::hex << (addr - instruction->size()) << std::dec);
	       dumpInstructions(instructions, addrStart);
               return;
	   }
	   if (!instruction->isLegalInsn()) {
               unconditionalizePassLog("Warning: Illegal instruction at 0x" << std::hex << (addr - instruction->size()) << std::dec);
	       dumpInstructions(instructions, addrStart);
               return;
	   }

	   if (instructionIsBasicBlockTest(instruction, addr - instruction->size(), var_inject_bb, bb_index)) {
	       patchloc.cmp_addr = addr - instruction->size();
	       patchloc.cmp_size = instruction->size();
	       continue;
	   }
	   if (bb_index < 0) continue;
           if (instruction->getCategory() != Dyninst::InstructionAPI::c_BranchInsn) {
	       if (instructionWritesRegister(instruction, Dyninst::x86::zf)) {
	           unconditionalizePassLog("Warning: Instruction reading edfi_inject_bb followed by ZF-modifying instruction at 0x" << std::hex << (addr - instruction->size()) << std::dec << ": " << instruction->format());
	       }
	       continue;
           }
           switch (instruction->getOperation().getID()) {
           case e_jnz:
               patchloc.mode = mode_unconditional;
               break;
           case e_jz:
               patchloc.mode = mode_nop;
               break;
           default:
	       unconditionalizePassLog("Warning: Instruction reading edfi_inject_bb followed by unexpected type of branch instruction at 0x" << std::hex << (addr - instruction->size()) << std::dec << ": " << instruction->format());
	       dumpInstructions(instructions, addrStart);
	       continue;
           }
	   if (it + 1 != instructions.end()) {
               unconditionalizePassLog("Warning: Branch before end of basic block " << bb_index << " at 0x" << std::hex << (addr - instruction->size()) << std::dec << ": " << instruction->format() << "; next: " << (*(it + 1))->format());
	       dumpInstructions(instructions, addrStart);
	       return;
	   }
	   patchloc.bb_index = bb_index;
	   patchloc.jmp_addr = addr - instruction->size();
	   patchloc.jmp_size = instruction->size();
	   patchlocs.push_back(patchloc);
           unconditionalizePassDbg("Need to patch jump at 0x" << std::hex << (addr - instruction->size()) << std::dec << ": " << instruction->format());
           memset(&patchloc, 0, sizeof(patchloc));
	   return;
      }
      if (bb_index >= 0) {
          unconditionalizePassLog("Warning: No branch at end of basic block " << bb_index << " at 0x" << std::hex << (addr - instruction->size()) << std::dec);
	  dumpInstructions(instructions, addrStart);
          return;
      }
    }

    void runOnFunction(ELFIO::elfio &reader, BPatch_function *function, BPatch_variableExpr *var_inject_bb, std::list<struct patchloc> &patchlocs) {
      std::set<BPatch_basicBlock*> bbs;
      BPatch_flowGraph *cfg;
      std::set<BPatch_basicBlock*>::iterator it;

      unconditionalizePassDbg("Processing function " + function->getName());
      cfg = function->getCFG();
      if (!cfg) {
          unconditionalizePassLog("Warning: Function " + function->getName() + " has no CFG");
	  return;
      }

      cfg->getAllBasicBlocks(bbs);
      for (it = bbs.begin(); it != bbs.end(); ++it) {
           runOnBasicBlock(reader, *it, var_inject_bb, patchlocs);
      }
    }

    unsigned char multibyte_nop(size_t index, size_t size) {
      size_t nop_count, nop_index, nop_size;

      /* Intel® 64 and IA-32 Architectures Software Developer’s Manual */
      /* Volume 2, Table-9. Recommended Multi-Byte Sequence of NOP Instruction */
      static unsigned char nop1[] = { 0x90 };
      static unsigned char nop2[] = { 0x66, 0x90 };
      static unsigned char nop3[] = { 0x0f, 0x1f, 0x00 };
      static unsigned char nop4[] = { 0x0f, 0x1f, 0x40, 0x00 };
      static unsigned char nop5[] = { 0x0f, 0x1f, 0x44, 0x00, 0x00 };
      static unsigned char nop6[] = { 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00 };
      static unsigned char nop7[] = { 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00 };
      static unsigned char nop8[] = { 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
      static unsigned char nop9[] = { 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
      static unsigned char *nop[] = { nop1, nop2, nop3, nop4, nop5, nop6, nop7, nop8, nop9 };

      assert(size > 0);
      assert(index < size);

      if (size > 9) {
          nop_count = (size + 8) / 9;
	  nop_size = (size + nop_count - 1) / nop_count;
	  nop_index = index / nop_size;
	  index = index % nop_size;
	  if (nop_index + 1 == nop_count) {
              size -= nop_index * nop_size;
	  } else {
              size = nop_size;
	  }
      }

      return nop[size - 1][index];
    }

    void patch_add_byte(
      std::vector<struct patchbyte> &patchbytes,
      ELFIO::section *section,
      const char *data,
      size_t offset,
      long bb_index,
      unsigned char value_new) {
      struct patchbyte patchbyte = {
          section->get_offset() + offset,
	  bb_index,
	  data[offset],
	  value_new,
      };
      patchbytes.push_back(patchbyte);
    }

    void patch_add_nop(
      std::vector<struct patchbyte> &patchbytes,
      ELFIO::section *section,
      const char *data,
      size_t offset,
      long bb_index,
      size_t size) {
      int i;

      for (i = 0; i < size; i++) {
          patch_add_byte(
	      patchbytes,
	      section,
	      data,
	      offset + i,
              bb_index,
              multibyte_nop(i, size));
      }
    }

    void buildPatch(
      std::vector<struct patchbyte> &patchbytesgolden,
      std::vector<struct patchbyte> &patchbytesfaulty,
      std::list<struct patchloc> &patchlocs,
      ELFIO::elfio &reader) {
      uint32_t bb_index;
      size_t cmp_offset;
      const char *data;
      std::list<struct patchloc>::iterator it;
      size_t jmp_offset;
      int secidx;
      ELFIO::section *section;
      ELFIO::Elf_Xword size;

      for (secidx = 0; secidx < reader.sections.size(); secidx++) {
	  section = reader.sections[secidx];
          unconditionalizePassDbg("section " << secidx << " "
		"name=" << section->get_name() <<
		", esz=0x" << std::hex << section->get_entry_size() <<
		", addr=0x" << std::hex << section->get_address() <<
		", sz=0x" << section->get_size() << std::dec);
	  data = NULL;
          for (it = patchlocs.begin(); it != patchlocs.end(); ++it) {
	       size = section->get_size();

	       /* verify both instructions fit within the section */
               if (it->cmp_addr < section->get_address()) continue;
	       cmp_offset = it->cmp_addr - section->get_address();
	       if (cmp_offset + it->cmp_size > size) continue;

               if (it->jmp_addr < section->get_address()) continue;
	       jmp_offset = it->jmp_addr - section->get_address();
	       if (jmp_offset + it->jmp_size > size) continue;

	       /* mark as found */
	       it->found = true;

	       /* obtain a copy of the segment data */
	       if (!data) data = section->get_data();

	       /* check whether the CMP opcode is as expected */
	       if (data[cmp_offset] == (char) 0x81 && data[cmp_offset + 1] == (char) 0x3d) {
		   /* CMP Ev, Iz */
		   assert(it->cmp_size == 10);
		   bb_index = *(uint32_t *) (data + cmp_offset + 6);
	       } else if (data[cmp_offset] == (char) 0x83 && data[cmp_offset + 1] == (char) 0x3d) {
		   /* CMP Ev, Ib */
		   assert(it->cmp_size == 7);
		   bb_index = *(int8_t *) (data + cmp_offset + 6);
	       } else {
                   unconditionalizePassLog("Warning: unrecognized CMP instruction at 0x" << std::hex << it->cmp_addr << std::dec);
		   continue;
	       }
	       assert(bb_index == it->bb_index);

	       /* make Jcc unconditional */
	       if (it->mode == mode_unconditional &&
                   data[jmp_offset] == (char) 0x75) {
		   /* golden: JNZ rel8 -> JMP rel8 */
		   assert(it->jmp_size == 2);
                   patch_add_byte(patchbytesgolden, section, data, jmp_offset, it->bb_index, 0xeb);
		   /* faulty: JNZ rel8 -> NOP */
	           patch_add_nop(patchbytesfaulty, section, data, jmp_offset, it->bb_index, it->jmp_size);
	       } else if (it->mode == mode_nop &&
                   data[jmp_offset] == (char) 0x74) {
		   /* golden: JZ rel8 -> NOP */
		   assert(it->jmp_size == 2);
	           patch_add_nop(patchbytesgolden, section, data, jmp_offset, it->bb_index, it->jmp_size);
		   /* faulty: JZ rel8 -> JMP rel8 */
                   patch_add_byte(patchbytesfaulty, section, data, jmp_offset, it->bb_index, 0xeb);
	       } else if (it->mode == mode_unconditional &&
                   data[jmp_offset] == (char) 0x0f &&
                   data[jmp_offset + 1] == (char) 0x85) {
		   /* golden: JNZ rel32 -> NOP; JMP rel32 */
		   assert(it->jmp_size == 6);
                   patch_add_byte(patchbytesgolden, section, data, jmp_offset, it->bb_index, 0x90);
                   patch_add_byte(patchbytesgolden, section, data, jmp_offset + 1, it->bb_index, 0xe9);
		   /* faulty: JNZ rel32 -> NOP; JMP rel32 */
	           patch_add_nop(patchbytesfaulty, section, data, jmp_offset, it->bb_index, it->jmp_size);
	       } else if (it->mode == mode_nop &&
                   data[jmp_offset] == (char) 0x0f &&
                   data[jmp_offset + 1] == (char) 0x84) {
		   /* golden: JZ rel32 -> NOP */
		   assert(it->jmp_size == 6);
	           patch_add_nop(patchbytesgolden, section, data, jmp_offset, it->bb_index, it->jmp_size);
		   /* faulty: JZ rel32 -> NOP; JMP rel32 */
                   patch_add_byte(patchbytesfaulty, section, data, jmp_offset, it->bb_index, 0x90);
                   patch_add_byte(patchbytesfaulty, section, data, jmp_offset + 1, it->bb_index, 0xe9);
	       } else {
                   unconditionalizePassLog("Warning: unrecognized JMP instruction at 0x" << std::hex << it->jmp_addr << std::dec);
		   break;
	       }

	       /* golden&faulty: NOP out compare (let's hope flags are not relied on) */
	       patch_add_nop(patchbytesgolden, section, data, cmp_offset, it->bb_index, it->cmp_size);
	       patch_add_nop(patchbytesfaulty, section, data, cmp_offset, it->bb_index, it->cmp_size);
          }
      }

      for (it = patchlocs.begin(); it != patchlocs.end(); ++it) {
          if (it->found) continue;
          unconditionalizePassLog("Warning: instructions at 0x" << std::hex << it->cmp_addr << " and 0x" << it->jmp_addr << std::dec << " not found in any section");
      }
    }

    void storePatch(std::vector<struct patchbyte> &patchbytesgolden,
      std::vector<struct patchbyte> &patchbytesfaulty,
      std::string pathout) {
      uint32_t bbcount, bbcountgolden, bbcountfaulty;
      long bb_index;
      struct ucpatch_byte byte;
      int indexf, indexg, writebytes;
      struct ucpatch_location location;
      uint32_t offset;
      struct patchbyte patchbyte;
      std::string pathpatch = pathout + ".ucpatch";
      int which;

      unconditionalizePassDbg("Saving patch: " << pathpatch);
      std::ofstream file_out(pathpatch.c_str(), std::ios::out | std::ios::trunc | std::ios::binary);

      std::sort(patchbytesgolden.begin(), patchbytesgolden.end(), compare_patchbyte_bbindex);
      std::sort(patchbytesfaulty.begin(), patchbytesfaulty.end(), compare_patchbyte_bbindex);

      /* write bbcount (may be an underestimate, includes only patched bbs) */
      bbcountgolden = (patchbytesgolden.size() > 0) ? (patchbytesgolden[patchbytesgolden.size() - 1].bb_index + 1) : 0;
      bbcountfaulty = (patchbytesfaulty.size() > 0) ? (patchbytesfaulty[patchbytesfaulty.size() - 1].bb_index + 1) : 0;
      bbcount = (bbcountgolden > bbcountfaulty) ? bbcountgolden : bbcountfaulty;
      file_out.write((char *) &bbcount, sizeof(bbcount));

      /* write locations */
      memset(&location, 0, sizeof(location));
      memset(&byte, 0, sizeof(byte));
      for (writebytes = 0; writebytes <= 1; writebytes++) {
	  bb_index = -1;
          indexg = 0;
          indexf = 0;
          offset = sizeof(bbcount) + sizeof(location) * bbcount;
	  for (;;) {
              /* which of the two has the next patch byte? */
	      if (indexg < patchbytesgolden.size()) {
	          if (indexf < patchbytesfaulty.size()) {
	              which = compare_patchbyte_bbindex_int(patchbytesgolden[indexg], patchbytesfaulty[indexf]);
	          } else {
                      which = -1;
	          }
	      } else {
	          if (indexf < patchbytesfaulty.size()) {
	              which = 1;
	          } else {
		      break;
	          }
	      }

              /* write location */
	      patchbyte = (which > 0) ? patchbytesfaulty[indexf] : patchbytesgolden[indexg];
	      assert(bb_index <= patchbyte.bb_index);
	      while (bb_index < patchbyte.bb_index) {
	          location.count = offset - location.offset;
                  if (!writebytes && bb_index >= 0) file_out.write((char *) &location, sizeof(location));
		  location.offset = offset;
		  bb_index++;
              }

              /* write bytes */
	      if (writebytes) {
                  byte.offset = patchbyte.offset;
                  byte.value_orig = patchbyte.value_orig;
                  byte.value_golden = (which <= 0) ? patchbytesgolden[indexg].value_new : patchbyte.value_orig;
                  byte.value_faulty = (which >= 0) ? patchbytesfaulty[indexf].value_new : patchbyte.value_orig;
                  file_out.write((char *) &byte, sizeof(byte));
	      }

	      if (which <= 0) indexg++;
	      if (which >= 0) indexf++;
	      offset += sizeof(byte);
	  }
          location.count = offset - location.offset;
          if (!writebytes && bb_index >= 0) file_out.write((char *) &location, sizeof(location));
      }
    }

    void applyPatch(std::string path, std::string pathout,
      std::vector<struct patchbyte> &patchbytes) {
      int c;
      ELFIO::Elf64_Off file_offset = 0;
      int patchbyte_index = 0;

      unconditionalizePassDbg("Saving patched ELF file: " << pathout);
      std::ifstream file_in(path.c_str(), std::ios::in | std::ios::binary);
      std::ofstream file_out(pathout.c_str(), std::ios::out | std::ios::trunc | std::ios::binary);

      std::sort(patchbytes.begin(), patchbytes.end(), compare_patchbyte_offset);

      while ((c = file_in.get()) != EOF) {
	  /* apply patch is it is applicable to the current byte */
	  if (patchbyte_index < patchbytes.size() && patchbytes[patchbyte_index].offset == file_offset) {
              assert(c == patchbytes[patchbyte_index].value_orig);
	      c = patchbytes[patchbyte_index].value_new;
	      patchbyte_index++;
	      assert(patchbyte_index >= patchbytes.size() || patchbytes[patchbyte_index].offset > file_offset);
	  }
	  /* copy the (possibly changed) byte to the output file */
          file_out.put(c);
	  file_offset++;
      }
    }

    bool updateImage(ELFIO::elfio &reader, std::string path, std::string pathout,
      std::list<struct patchloc> &patchlocs) {
      std::vector<struct patchbyte> patchbytesfaulty;
      std::vector<struct patchbyte> patchbytesgolden;

      unconditionalizePassDbg("Number of patch locations found: " << patchlocs.size());

      buildPatch(patchbytesgolden, patchbytesfaulty, patchlocs, reader);
      storePatch(patchbytesgolden, patchbytesfaulty, pathout);
      applyPatch(path, pathout, patchbytesgolden);

      return true;
    }

  public:
    static char ID;
    UnconditionalizePass() : ModulePass(ID) {}

    virtual bool runOnModule(void *M) {
      unconditionalizePassLog("ERROR: framework invoked wrong UnconditionalizePass::runOnModule overload");
      return false;
    }

    virtual bool runOnModule(void *M, std::string path, std::string pathout,
      bool &outputWritten) {
      BPatch_addressSpace *as = (BPatch_addressSpace*) M;
      std::vector<BPatch_function *> *functions;
      std::vector<BPatch_function *>::iterator it;
      BPatch_image *image;
      BPatch_binaryEdit *binEdit = dynamic_cast<BPatch_binaryEdit*>(as);
      bool isBinEdit = binEdit != NULL;
      std::list<struct patchloc> patchlocs;
      ELFIO::elfio reader;
      BPatch_variableExpr *var_inject_bb;

      if (!isBinEdit) {
          unconditionalizePassLog("ERROR: Binary edit not supported by Unconditionalize Pass");
	  return false;
      }
      unconditionalizePassLog("Running (binary)...");
      unconditionalizePassDbg("Debug mode enabled!");

      unconditionalizePassDbg("Finding edfi_inject_bb variable");
      image = as->getImage();
      var_inject_bb = image->findVariable("edfi_inject_bb");
      if (!var_inject_bb) {
          unconditionalizePassLog("ERROR: Global variable edfi_inject_bb does not exist, did you use the -fault-unconditionalize EDFI option?");
          return false;
      }
      unconditionalizePassDbg("edfi_inject_bb=0x" << hex << (unsigned long) var_inject_bb->getBaseAddr() << dec);

      unconditionalizePassDbg("Loading ELF file for patching: " << path);
      if (!reader.load(path)) {
          unconditionalizePassLog("ERROR: Cannot open ELF file " << path);
	  return false;
      }

      unconditionalizePassDbg("Processing functions");
      functions = image->getProcedures(true);
      for (it = functions->begin(); it != functions->end(); ++it) {
           runOnFunction(reader, *it, var_inject_bb, patchlocs);
      }
      remove_duplicate_patchlocs(patchlocs);

      if (!updateImage(reader, path, pathout, patchlocs)) return false;

      outputWritten = true;
      return true;
    }
  };

}

char UnconditionalizePass::ID = 0;
RegisterPass<UnconditionalizePass> MP("unconditionalize", "Unconditionalize Pass");

