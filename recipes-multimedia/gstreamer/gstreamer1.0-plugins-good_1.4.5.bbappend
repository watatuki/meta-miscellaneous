# enable jack

PACKAGECONFIG_append = " jack2 "
PACKAGECONFIG[jack2]       = "--enable-jack,--disable-jack,jack2"

