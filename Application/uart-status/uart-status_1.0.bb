DESCRIPTION = "To check UART OPEN or NOT_made by YJ"
SECTION = "innowell_application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://uart-status.c"

S = "${WORKDIR}"

do_compile() {
${CC} ${LDFLAGS} uart-status.c -o uart-status
}

do_install() {
install -d ${D}${bindir}
install -m 0755 uart-status ${D}${bindir}
}
