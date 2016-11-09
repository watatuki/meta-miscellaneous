SUMMARY = "The Flite+hts_engine is an English TTS System."
SECTION = "libs"
LICENSE = "BSD"

LIC_FILES_CHKSUM = "file://COPYING;md5=a1ab16abd1c593cab35c2987fd871678"

PR = "r0"

BBCLASSEXTEND = "native"
PROVIDES_append_class-native = " flite-native "

SRC_URI = "\
	http://downloads.sourceforge.net/hts-engine/flite%2Bhts_engine-${PV}.tar.gz \
	"

SRC_URI[md5sum] = "c2eed681c84c67684a071bbfdb30d7f0"
SRC_URI[sha256sum] = "8a8c3ecc186ef92eda150a4aa687d8638f4f42be52aa2971e72aa960d4fdc342"


DEPENDS = " hts-engine "

inherit autotools

S = "${WORKDIR}/flite+hts_engine-${PV}"
B = "${S}"


EXTRA_OECONF = " \
 --with-hts-engine-header-path=${PKG_CONFIG_SYSROOT_DIR}/usr/include \
 --with-hts-engine-library-path=${PKG_CONFIG_SYSROOT_DIR}/usr/lib \
"