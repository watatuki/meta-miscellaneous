SUMMARY = "A complete, cross-platform solution to record, convert and stream audio and video."
HOMEPAGE = "http://libav.org/"
SECTION = "libs"
LICENSE = "GPLv2+"

# Provides ffmpeg compat, see http://libav.org/about.html
PROVIDES = "ffmpeg"

ARM_INSTRUCTION_SET = "arm"

DEPENDS = "virtual/libsdl zlib libogg libvorbis libtheora yasm-native"

INC_PR = "r0"

inherit autotools pkgconfig

B = "${S}/build.${HOST_SYS}.${TARGET_SYS}"

FULL_OPTIMIZATION = "-Ofast"
BUILD_OPTIMIZATION = "${FULL_OPTIMIZATION}"

EXTRA_FFCONF ?= ""

PACKAGECONFIG ??= "bzip2 "
PACKAGECONFIG[jack] = "--enable-indev=jack,--disable-indev=jack,jack"
PACKAGECONFIG[bzip2] = "--enable-bzlib,--disable-bzlib,bzip2"
PACKAGECONFIG[schroedinger] = "--enable-libschroedinger,--disable-libschroedinger,schroedinger"
PACKAGECONFIG[gsm] = "--enable-libgsm,--disable-libgsm,libgsm"
PACKAGECONFIG[vpx] = "--enable-libvpx,--disable-libvpx,libvpx"
PACKAGECONFIG[mp3lame] = "--enable-libmp3lame,--disable-libmp3lame,lame"
PACKAGECONFIG[faac] = "--enable-libfaac,--disable-libfaac,faac"

EXTRA_OECONF = " \
    --enable-shared \
    --enable-pic \
    --enable-pthreads \
    --enable-avfilter \
    --disable-libx264 \
    \
    --cross-prefix=${TARGET_PREFIX} \
    --prefix=${prefix} \
    \
    --enable-avserver \
    --enable-avplay \
    --enable-libtheora  \
    --enable-libvorbis \
    --arch=${TARGET_ARCH} \
    --target-os="linux" \
    --enable-cross-compile \
    --extra-cflags="${TARGET_CFLAGS} ${HOST_CC_ARCH}${TOOLCHAIN_OPTIONS}" \
    --extra-ldflags="${TARGET_LDFLAGS}" \
    --sysroot="${STAGING_DIR_TARGET}" \
    --enable-hardcoded-tables \
    ${EXTRA_FFCONF} \
"

do_configure() {
    # We don't have TARGET_PREFIX-pkgconfig
    sed -i '/pkg_config_default="${cross_prefix}${pkg_config_default}"/d' ${S}/configure
    mkdir -p ${B}
    cd ${B}
    ${S}/configure ${EXTRA_OECONF}
    sed -i -e s:Os:O4:g ${B}/config.h
}

do_install_append() {
    install -m 0644 ${S}/libavfilter/*.h ${D}${includedir}/libavfilter/
}

FFMPEG_LIBS = "libavcodec libavdevice libavformat \
               libavutil libpostproc libswscale libavfilter"

PACKAGES += "${PN}-vhook-dbg ${PN}-vhook ffmpeg-x264-presets"

RSUGGESTS_${PN} = "mplayer"
FILES_${PN} = "${bindir}"
FILES_${PN}-dev = "${includedir}/${PN}"

FILES_${PN}-vhook = "${libdir}/vhook"
FILES_${PN}-vhook-dbg += "${libdir}/vhook/.debug"

FILES_ffmpeg-x264-presets = "${datadir}/*.avpreset"

LEAD_SONAME = "libavcodec.so"

FILES_${PN}-dev = "${includedir}"

python populate_packages_prepend() {
    av_libdir = d.expand('${libdir}')
    av_pkgconfig = d.expand('${libdir}/pkgconfig')

    # Runtime package
    do_split_packages(d, av_libdir, '^lib(.*)\.so\..*',
                      output_pattern='lib%s',
                      description='libav %s library',
                      extra_depends='',
                      prepend=True,
                      allow_links=True)

    # Development packages (-dev, -staticdev)
    do_split_packages(d, av_libdir, '^lib(.*)\.so$',
                      output_pattern='lib%s-dev',
                      description='libav %s development package',
                      extra_depends='${PN}-dev',
                      prepend=True,
                      allow_links=True)
    do_split_packages(d, av_pkgconfig, '^lib(.*)\.pc$',
                      output_pattern='lib%s-dev',
                      description='libav %s development package',
                      extra_depends='${PN}-dev',
                      prepend=True)
    do_split_packages(d, av_libdir, '^lib(.*)\.a$',
                      output_pattern='lib%s-staticdev',
                      description='libav %s development package - static library',
                      extra_depends='${PN}-dev',
                      prepend=True,
                      allow_links=True)

    if d.getVar('TARGET_ARCH', True) == 'i586':
        # libav can't be build with -fPIC for 32-bit x86
        pkgs = d.getVar('PACKAGES', True).split()
        for pkg in pkgs:
            d.appendVar('INSANE_SKIP_%s' % pkg, ' textrel')
}

PACKAGES_DYNAMIC += "^lib(av(codec|device|filter|format|util)|postproc|swscale).*"
