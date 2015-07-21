DESCRIPTION = "Video player and streamer - davinci edition"
HOMEPAGE = "http://www.videolan.org"
SECTION = "multimedia"

LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

DEPENDS = "libssh2 gnutls dbus dbus-glib libxml2 libtool mesa libfribidi \
           libxinerama libxpm xcb-util-keysyms libidn qt4-x11-free \
           libmad faad2 libvpx libdvbpsi liba52 flac libpng jpeg libmtp \
           taglib libvorbis libogg libass libav \
           alsa-lib jack2 libsamplerate0 \
"

SRC_URI = "http://download.videolan.org/pub/videolan/${BPN}/${PV}/${BP}.tar.xz"

inherit autotools gettext pkgconfig distro_features_check

B = "${S}"

# depends on libxinerama libxpm xcb-util-keysyms
REQUIRED_DISTRO_FEATURES = "x11"

ARM_INSTRUCTION_SET = "arm"

EXTRA_OECONF += "\
    ac_cv_path_MOC=${STAGING_BINDIR_NATIVE}/moc4 \
    ac_cv_path_RCC=${STAGING_BINDIR_NATIVE}/rcc4 \
    ac_cv_path_UIC=${STAGING_BINDIR_NATIVE}/uic4 \
"

#Optional Features and Packages and Optimization options: 
EXTRA_OECONF += "\
    --without-contrib \
    --without-kde-solid \
    --enable-run-as-root \
    --disable-lua \
"
#Interface plugins:
EXTRA_OECONF += "\
    --enable-qt \
    --enable-skins2 \
    --disable-libtar \
    --disable-macosx \
    --disable-minimal-macosx \
    --disable-macosx-dialog-provider \
    --disable-ncurses \
    --disable-lirc \
"

#Service Discovery plugins:
EXTRA_OECONF += "\
    --disable-bonjour \
    --enable-udev \
    --enable-mtp \
    --disable-upnp \
"
#Misc options:
EXTRA_OECONF += "\
    --enable-libxml2 \
    --disable-libgcrypt \
    --enable-gnutls \
    --enable-taglib \
    --disable-update-check \
    --disable-growl \
    --disable-notify \
"

#Input plugins:
EXTRA_OECONF += "\
    --disable-live555 \
    --disable-dc1394 \
    --disable-dv1394 \
    --disable-linsys \
    --disable-dvdread \
    --disable-dvdnav \
    --disable-bluray \
    --disable-opencv \
    --disable-smbclient \
    --enable-sftp \
    --disable-v4l2 \
    --disable-decklink \
    --disable-gnomevfs \
    --disable-vcdx \
    --disable-vcd \
    --disable-libcddb \
    --disable-screen \
    --disable-vnc \
    --disable-freerdp \
    --enable-realrtsp \
    --disable-macosx-eyetv \
    --disable-macosx-qtkit \
    --disable-macosx-avfoundation \
    --disable-asdcp \
"
#Mux/Demux plugins:
EXTRA_OECONF += "\
    --enable-dvbpsi \
    --disable-gme \
    --disable-sid \
    --enable-ogg \
    --enable-mux_ogg \
    --disable-shout \
    --disable-mkv \
    --disable-mod \
    --disable-mpc \
"

#Codec plugins:
# auto  -libva -dxva2 -kate -tiger -zvbi -telx
EXTRA_OECONF += "\
    --disable-wma-fixed \
    --disable-shine \
    --disable-omxil \
    --disable-omxil-vout \
    --disable-rpi-omxil \
    --disable-mmal-codec \
    --disable-crystalhd \
    --enable-mad \
    --disable-merge-ffmpeg \
    --disable-gst-decode \
    --enable-avcodec \
    --enable-vda \
    --enable-avformat \
    --enable-swscale \
    --disable-postproc \
    --enable-faad \
    --enable-vpx \
    --disable-twolame \
    --disable-fdkaac \
    --disable-quicktime \
    --enable-a52 \
    --disable-dca \
    --enable-flac \
    --disable-libmpeg2 \
    --enable-vorbis \
    --disable-tremor \
    --disable-speex \
    --disable-opus \
    --disable-theora \
    --disable-schroedinger \
    --enable-png \
    --enable-jpeg \
    --disable-x262 \
    --disable-x265 \
    --disable-x26410b \
    --disable-x264 \
    --disable-mfx \
    --disable-fluidsynth \
    --enable-libass \
"

#Video plugins:
EXTRA_OECONF += "\
    --enable-gles2 \
    --disable-gles1 \
    --with-x \
    --enable-xcb \
    --enable-xvideo \
    --disable-vdpau \
    --disable-sdl \
    --disable-sdl-image \
    --enable-freetype \
    --enable-fribidi \
    --enable-fontconfig \
    --disable-macosx-quartztext \
    --disable-svg \
    --disable-svgdec \
    --disable-android-surface \
    --disable-directx \
    --disable-directfb \
    --disable-aa \
    --disable-caca \
    --disable-kva \
    --disable-mmal-vout \
"
#Audio plugins:
EXTRA_OECONF += "\
    --disable-pulse \
    --enable-alsa \
    --disable-oss \
    --disable-sndio \
    --disable-wasapi \
    --disable-audioqueue \
    --enable-jack \
    --disable-opensles \
    --enable-samplerate  \
    --disable-kai \
    --disable-chromaprint \
"

#PACKAGECONFIG[opencv] = "--enable-opencv,--disable-opencv,opencv"

do_configure_prepend() {
    cp ${STAGING_DATADIR}/libtool/config.* ${S}/autotools/ || true
}

do_configure_append() {
    sed -i -e s:'$(MOC) $(DEFS) $(CPPFLAGS)':'$(MOC) $(DEFS)'\ -I${B}/include\ -DSYS_LINUX:g ${B}/modules/gui/qt4/Makefile
    sed -i -e s:'${top_builddir_slash}libtool':${TARGET_SYS}-libtool:g ${B}/doltlibtool
}

# This recipe packages vlc as a library as well, so qt4 dependencies
# can be avoided when only the library is installed.
PACKAGES =+ "libvlc"

LEAD_SONAME_libvlc = "libvlc.so.5"
FILES_libvlc = "${libdir}/lib*.so.*"

FILES_${PN} += "\
    ${bindir}/vlc \
    ${datadir}/applications \
    ${datadir}/vlc/ \
    ${datadir}/icons \
    ${datadir}/kde4/apps/solid/actions/* \
"

FILES_${PN}-dbg += "\
    ${libdir}/vlc/*/.debug \
    ${libdir}/vlc/plugins/*/.debug \
"

FILES_${PN}-staticdev += "\
    ${libdir}/vlc/plugins/*/*.a \
"
