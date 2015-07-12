SUMMARY = "Takao Fonts are a community developed derivatives of IPA Fonts."
DESCRIPTION = "Takao Fonts are a community developed derivatives of IPA Fonts."

HOMEPAGE = "https://launchpad.net/takao-fonts"
SECTION = "User Interface/X"

LICENSE = "IPA"
LIC_FILES_CHKSUM = "file://IPA_Font_License_Agreement_v1.0.txt;md5=6cd3351ba979cf9db1fad644e8221276"

SRC_URI = "https://launchpad.net/takao-fonts/trunk/15.03/+download/TakaoExFonts_00201.01.zip"

SRC_URI[md5sum] = "d7a6c3d85cbf6c1a567bf85de4c0e3c3"
SRC_URI[sha256sum] = "6af43928cb4d9943cbd5565079d1dfed60aef20badf4e99c3a1edc0e6a07d42b"

S = "${WORKDIR}/TakaoExFonts_00201.01"

do_install() {
    install -m 0755 -d ${D}/${datadir}/fonts
    install -m 0644 -p ${S}/*.ttf ${D}/${datadir}/fonts/
}

FILES_${PN} += "${datadir}/fonts/*.ttf"
