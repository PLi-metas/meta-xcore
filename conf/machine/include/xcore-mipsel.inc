TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"
require conf/machine/include/tune-mips32.inc

KERNEL_IMAGETYPE = "vmlinux.gz"
KERNEL_CONSOLE = "ttyS0,115200n8"

require conf/machine/include/xcore-oem.inc

MTD_KERNEL = "mtd2"
MTD_ROOTFS = "mtd3"

ROOTFS_FILE = "rootfs.bin"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

require conf/machine/include/soc-family.inc

MACHINE_FEATURES += "textlcd videoenhancement"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    xcore-dvb-modules-${MACHINE} \
    "

IMAGE_FSTYPES ?= "ubi"

IMAGE_CMD_ubi_prepend = "\
    rm -rf ${IMAGE_ROOTFS}/boot/*; \
    rm -rf ${IMAGE_ROOTFS}/tmp/*; \
    "

IMAGEDIR = "${MACHINE}"
