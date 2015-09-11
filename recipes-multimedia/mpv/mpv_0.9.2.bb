DESCRIPTION = "Open Source multimedia player."
SECTION = "multimedia"
HOMEPAGE = "http://www.mplayerhq.hu/"
DEPENDS = "libav alsa-lib libass jpeg libxv jack2 libxinerama"

REQUIRED_DISTRO_FEATURES = "x11"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://LICENSE;md5=91f1cb870c1cc2d31351a4d2595441cb"

SRC_URI = "https://github.com/mpv-player/mpv/archive/v${PV}.tar.gz"

SRC_URI[md5sum] = "ed1384e703f7032e531731842e4da4f7"
SRC_URI[sha256sum] = "c0148f55dbd17705f49bb496d0ce374419de62e1b17195d91409d7727cbd4751"

PR = "r0"

FILES_${PN} += "/usr/etc/mpv/ /usr/share/icons/hicolor/*/*"
CONFFILES_${PN} += "/usr/etc/mpv/*"

inherit waf pkgconfig

do_configure_prepend () {
	./bootstrap.py
}

EXTRA_OECONF = " --enable-x11 --disable-sdl1 --disable-sdl2 --disable-wayland --disable-win32 \
				--enable-gl \
				--disable-rsound --disable-sndio --disable-openal \
				--enable-libass --enable-jack --disable-pulse \
				--disable-dvdread --disable-dvdnav --disable-dvb --disable-dvbin --disable-jpeg --disable-direct3d \
				--disable-tv --disable-tv-v4l2 --disable-libv4l2 --disable-pvr --disable-audio-input --disable-lua \
				"
