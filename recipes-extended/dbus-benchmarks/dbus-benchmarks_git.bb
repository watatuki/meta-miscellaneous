SUMMARY = "dbus-benchmarks "
DESCRIPTION = "dbus-benchmarks"
HOMEPAGE = "https://github.com/matthoosier/dbus-benchmarks"

LICENSE="ODbL-1.0"
LIC_FILES_CHKSUM="file:///${COMMON_LICENSE_DIR}/ODbL-1.0;md5=498d26a501c10739d57fca1c9d80bbc2"

DEPENDS = "libpng12 jpeg virtual/libx11 virtual/libgl "

SRC_URI = "git://github.com/matthoosier/dbus-benchmarks.git \
           file://waf \
           "

SRCREV = "a6e1801008e8f6dab4a55a78d3f74ad34b4972d6"

inherit waf pkgconfig

S = "${WORKDIR}/git"

do_configure_prepend() {
	rm ${WORKDIR}/git/waf
	cp ${WORKDIR}/waf ${WORKDIR}/git/
	chmod +x ${WORKDIR}/git/waf
}

