require libav9.inc

LIC_FILES_CHKSUM = "file://COPYING.GPLv2;md5=b234ee4d69f5fce4486a80fdaf4a4263 \
                    file://COPYING.GPLv3;md5=d32239bcb673463ab874e80d47fae504 \
                    file://COPYING.LGPLv2.1;md5=bd7a443320af8c812e4c18d1b79df004 \
                    file://COPYING.LGPLv3;md5=e6a600fd5e1d9cbde2d983680233ad02"

SRC_URI = "https://libav.org/releases/libav-${PV}.tar.xz"

SRC_URI[md5sum] = "75e838068a75fb88e1b4ea0546bc16f0"
SRC_URI[sha256sum] = "0875e835da683eef1a7bac75e1884634194149d7479d1538ba9fbe1614d066d7"

S = "${WORKDIR}/libav-${PV}"

do_install_append () {
    rm -R ${D}/usr/include
    rm -R ${D}/usr/lib/pkgconfig
    rm ${D}/usr/lib/libavcodec.a
    rm ${D}/usr/lib/libavcodec.so
    rm ${D}/usr/lib/libavdevice.a
    rm ${D}/usr/lib/libavdevice.so
    rm ${D}/usr/lib/libavfilter.a
    rm ${D}/usr/lib/libavfilter.so
    rm ${D}/usr/lib/libavformat.a
    rm ${D}/usr/lib/libavformat.so
    rm ${D}/usr/lib/libavresample.a
    rm ${D}/usr/lib/libavresample.so
    rm ${D}/usr/lib/libavutil.a
    rm ${D}/usr/lib/libavutil.so
    rm ${D}/usr/lib/libswscale.a
    rm ${D}/usr/lib/libswscale.so
}

