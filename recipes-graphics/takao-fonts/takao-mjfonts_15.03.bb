SUMMARY = "Takao Fonts are a community developed derivatives of IPA Fonts."
DESCRIPTION = "Takao Fonts are a community developed derivatives of IPA Fonts."

HOMEPAGE = "https://launchpad.net/takao-fonts"
SECTION = "User Interface/X"

LICENSE = "IPA"
LIC_FILES_CHKSUM = "file://IPA_Font_License_Agreement_v1.0.txt;md5=6cd3351ba979cf9db1fad644e8221276"

SRC_URI = "https://launchpad.net/takao-fonts/trunk/15.03/+download/TakaoMjFonts_00301.01.zip"

SRC_URI[md5sum] = "4ae95516de8bb8202059fc4740cf36c9"
SRC_URI[sha256sum] = "6729e8207853a2d6ea8189fb138789152b81e9612ef8989acc2f363fd5322ee1"

S = "${WORKDIR}/TakaoMjFonts_00301.01"

do_install() {
    install -m 0755 -d ${D}/${datadir}/fonts
    install -m 0644 -p ${S}/*.ttf ${D}/${datadir}/fonts/
}

FILES_${PN} += "${datadir}/fonts/*.ttf"
