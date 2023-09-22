## BBAPPEND made by YJLEE,INNOWELL
## For locate application on /usr/local/bin

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " \
	file://iw-changeip_1.0_r0.out \
	file://nfs-test.txt \
	file://.bashrc \
    file://.bash_aliases \
    file://.profile \
"

# exec_prefix is /usr
do_install:append(){
	install -D -m0744 ${WORKDIR}/iw-changeip_1.0_r0.out  ${D}${exec_prefix}/local/bin/iw-changeip_1.0_r0.out
	
	install -D -m0744 ${WORKDIR}/.bashrc  ${D}/home/root/.bashrc
    install -D -m0744 ${WORKDIR}/.bash_aliases  ${D}/home/root/.bash_aliases
    install -D -m0744 ${WORKDIR}/.profile  ${D}/home/root/.profile

	#for nfs test
	install -D -m0744 ${WORKDIR}/nfs-test.txt ${D}/home/root/fpga/nfs-test.txt
}


FILES:${PN}:append = "\
	${exec_prefix}/local/bin/ \
	/home/root/fpga/ \
	/home/root \
"
