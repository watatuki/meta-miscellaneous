require ${BPN}.inc

# work around build failure

SRC_URI += "file://0001-enable-subdir-objects.patch \
            file://0002-glibc-does-not-provide-strlcpy.patch \
            file://0005-libpostproc-header-check.patch \
            file://0006-make-opencv-configurable.patch \
"

SRC_URI[md5sum] = "faeceb614bf3946e5f90ef0d1f51db45"
SRC_URI[sha256sum] = "5e0a27e248c47da723a696420aca3a4dd15cc3ed8cc81618d3f1dc8661b25517"
