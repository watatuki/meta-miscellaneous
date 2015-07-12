SUMMARY = "Takao Fonts are a community developed derivatives of IPA Fonts."
DESCRIPTION = "Takao Fonts are a community developed derivatives of IPA Fonts."

HOMEPAGE = "https://launchpad.net/takao-fonts"
SECTION = "User Interface/X"

LICENSE = "IPA"
LIC_FILES_CHKSUM = "file://IPA_Font_License_Agreement_v1.0.txt;md5=6cd3351ba979cf9db1fad644e8221276"

SRC_URI = "https://launchpad.net/takao-fonts/trunk/15.03/+download/TakaoFonts_00303.01.zip"

SRC_URI[md5sum] = "5e4a043195a500f8e762d0a893b635f0"
SRC_URI[sha256sum] = "9b356dc7bbdd4c1c5d880724176651b8e3bffe885274262f6ffd0cc712e479c9"

S = "${WORKDIR}/TakaoFonts_00303.01"

do_install() {
    install -m 0755 -d ${D}/${datadir}/fonts
    install -m 0644 -p ${S}/*.ttf ${D}/${datadir}/fonts/
}

FILES_${PN} += "${datadir}/fonts/*.ttf"
