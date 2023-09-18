## BBAPPEND made by YJLEE,INNOWELL
## For locate application on /usr/local/bin

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " \
	file://iw-changeip_1.0_r0.out \
"

# exec_prefix is /usr
do_install:append(){
	install -D -m0744 ${WORKDIR}/iw-changeip_1.0_r0.out  ${D}${exec_prefix}/local/bin/iw-changeip_1.0_r0.out
}


FILES:${PN}:append = "\
	${exec_prefix}/local/bin/ \
"
