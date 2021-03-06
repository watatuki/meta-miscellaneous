DESCRIPTION = "libass is a portable subtitle renderer for the ASS/SSA (Advanced Substation Alpha/Substation Alpha) subtitle format. It is mostly compatible with VSFilter."
HOMEPAGE = "https://github.com/libass/libass"
SECTION = "libs/multimedia"

LICENSE = "ISC"
LIC_FILES_CHKSUM = "file://COPYING;md5=8ae98663bac55afe5d989919d296f28a"

DEPENDS = "enca fontconfig freetype libpng fribidi glib-2.0"

INC_PR = "r1"

SRC_URI = "https://github.com/libass/libass/releases/download/0.12.3/libass-${PV}.tar.gz"

inherit autotools pkgconfig

PACKAGECONFIG ??= ""
PACKAGECONFIG[harfbuzz] = "--enable-harfbuzz,--disable-harfbuzz,harfbuzz"

EXTRA_OECONF = " \
    --enable-enca \
    --enable-fontconfig \
"

PACKAGES =+ "${PN}-tests"

FILES_${PN}-tests = " \
    ${libdir}/test/test \
"
