DESCRIPTION = "jack2 init script"
LICENSE = "MIT"

SECTION = "base"
PR = "r0"

SRC_URI = "file://MIT "
DEPENDS = "update-rc.d-native jack2"

S = "${WORKDIR}"

LIC_FILES_CHKSUM = "file://MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI_append_jetson-tk1-l4t = "file://jack2.sh"

inherit update-alternatives

do_install_append_jetson-tk1-l4t () {
	install -d ${D}${sysconfdir}/init.d
	install -d ${D}${sysconfdir}/rcS.d
	install -d ${D}${sysconfdir}/rc0.d
	install -d ${D}${sysconfdir}/rc1.d
	install -d ${D}${sysconfdir}/rc2.d
	install -d ${D}${sysconfdir}/rc3.d
	install -d ${D}${sysconfdir}/rc4.d
	install -d ${D}${sysconfdir}/rc5.d
	install -d ${D}${sysconfdir}/rc6.d
	
	install -m 0755    ${WORKDIR}/jack2.sh	${D}${sysconfdir}/init.d
	
	update-rc.d -r ${D} jack2.sh start 90 1 2 3 4 5 .
}
