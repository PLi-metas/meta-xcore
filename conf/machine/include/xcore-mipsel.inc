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

SOC_FAMILY = "bcm7358"
require conf/machine/include/soc-family.inc

PREFERRED_VERSION_linux-xcore = "4.0.2"

MACHINE_FEATURES += "ci textlcd videoenhancement blindscan-dvbs singlecore no-cl-svr 7segment"

IMAGE_FSTYPES ?= "ubi"

UBI_VOLNAME = "rootfs"
MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

IMAGE_CMD_ubi_prepend = "\
    rm -rf ${IMAGE_ROOTFS}/boot/*; \
    rm -rf ${IMAGE_ROOTFS}/tmp/*; \
    "
