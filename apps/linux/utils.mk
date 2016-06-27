# Utils for building the llvmlinux
#######################################
#git utils

gitclone = [ -d ${2}/.git ] || (rm -rf ${2} && git clone ${1} ${2} ${3})
gitcheckout = (cd ${1} && git checkout ${2} && ([ -z "${3}" ] || git pull && git checkout ${3}))

#######################################
state	= @mkdir -p $(dir ${1}) && touch ${1} \
	  && $(call echo,State $(notdir ${1}) [DONE]) \
	  && ( [ -d $(dir ${1})${2} ] || rm -f $(dir ${1})${2} )

echo	= (echo ${seperator}; echo ${1}; echo ${seperator})

patch	= [ ! -d ${1} ] || (cd ${1} && if [ -e patches ] && $(call echo,Applying patches to ${1}) && quilt unapplied ; then quilt push -a ; else >/dev/null ; fi)
gitpoint	= cd ${1} && git commit -am "EDFI - Patches applied"
patches_dir = [ "`stat -c "%N" ${2}`" = "'${2}' -> '${1}'" ] || (rm -f ${2}; ln -sf ${1} ${2})

#######################################
llvmconfig = mkdir -p ${2} ${3} && \
	(cd ${2} && ${5}/configure --prefix=${3} --enable-targets=x86 --enable-bindings=none --disable-debug-symbols \
	--enable-optimized --enable-assertions --enable-jit $(BINUTILSINCLUDE))

