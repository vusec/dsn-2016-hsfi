#!/usr/bin/python

import os
import subprocess
import sys

def match_modulename(file, modulename):
	if file == modulename: return True
	return file.startswith("mod") and file.endswith("_" + modulename)

def find_module(moduledir, modulename):
	modulepaths = list()
	for file in os.listdir(moduledir):
		if match_modulename(file, modulename):
			modulepaths.append(os.path.join(moduledir, file))

	return modulepaths

def fault_inject_in_file(patchpath, modulepath, ucpatchpath, bbindex):
	returnCode = subprocess.call([patchpath, "-f", bbindex, ucpatchpath, modulepath])
	if returnCode != 0:
		exit("invocation of %s on %s failed with exit code %s" % (patchpath, modulepath, returnCode))

def fault_inject(patchpath, moduledir, ucpatchdir, modulename, bbindex):
	modulepaths = find_module(moduledir, modulename)
	if len(modulepaths) < 1:
		sys.stderr.write("warning: module %s not found in %s" % (moduledir, modulename))

	for modulepath in modulepaths:
		fault_inject_in_file(patchpath, modulepath, os.path.join(ucpatchdir, modulename + ".ucpatch"), bbindex)

def faults_inject(patchpath, moduledir, ucpatchdir, faultspec):
	faultspec = faultspec.split("@", 1)[0] # remove source location after "@"
	parts = faultspec.split(":")
	if len(parts) % 2 != 0: sys.exit("odd number of faultspec entries")
	for i in range(0, len(parts), 2):
		fault_inject(patchpath, moduledir, ucpatchdir, parts[i], parts[i + 1])

def usage():
	sys.stdout.write("usage:\n")
	sys.stdout.write("  %s faultspec moduledir ucpatchdir\n", (sys.argv[0]))
	sys.stdout.write("\n")
	sys.stdout.write("faultspec consists of a list of modulename:bbindex pairs separated by colons.\n")
	sys.stdout.write("moduledir contains the module binaries. ucpatchdir contains the binary patch\n")
	sys.stdout.write("files for the module binaries.\n")
	sys.exit(2)

def main():
	if len(sys.argv) != 4: usage()

	patchpath = os.path.join(os.path.dirname(sys.argv[0]), "unconditionalize-patch")
	if not os.path.isfile(patchpath):
		sys.stderr.write("patch utility not found, did you build it? (looked in %s)\n" % (patchpath))
		sys.exit(1)

	faults_inject(patchpath, sys.argv[2], sys.argv[3], sys.argv[1])

main()
