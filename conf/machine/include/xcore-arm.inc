TARGET_ARCH = "arm"
DEFAULTTUNE = "cortexa15hf-neon-vfpv4"
require conf/machine/include/tune-cortexa15.inc

MTD_BOOTFS = "mmcblk1p1"

SOC_FAMILY = "bcm7439"
require conf/machine/include/soc-family.inc

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3 --with-h265 --with-vb6 --with-vb8 --with-vb9 --with-spark"

### 8723BS wireless/bluetooth ###
KERNEL_MODULE_AUTOLOAD += "r8723bs"
KERNEL_MODULE_AUTOLOAD += "hci_uart"

IMAGE_FSTYPES ?= "${@bb.utils.contains('MACHINE_FEATURES', 'emmc', 'xcore-emmc', 'ubi', d)}"

MACHINE_FEATURES += "videoenhancement inibt directfb textlcd dvb-c blindscan-tbs linuxwifi linux4extra ci mountboot"

KERNEL_IMAGETYPE = "zImage"
KERNEL_CONSOLE = "ttyS0,115200n8"

GLIBC_EXTRA_OECONF = "--with-tls --with-__thread"

require conf/machine/include/xcore-oem.inc

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "\
    kernel-module-hci-uart \
    "

MACHINE_EXTRA_RRECOMMENDS += "\
    firmware-rtl8723b \
    "

PREFERRED_VERSION_linux-xcore = "4.11"

IMAGE_CLASSES += "image_types_xcore"
IMAGE_ROOTFS_SIZE ?= "294912"

IMAGE_CMD_xcore-emmc_append = "\
    mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
    mv ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.emmc ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/emmc.img; \
    cd ${IMAGE_ROOTFS}; \
    tar -cvf ${DEPLOY_DIR_IMAGE}/rootfs.tar -C ${IMAGE_ROOTFS} .; \
    mv ${DEPLOY_DIR_IMAGE}/rootfs.tar ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
    bzip2 ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
    cp ${DEPLOY_DIR_IMAGE}/zImage ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
    echo ${IMAGE_VER_STRING} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
    echo "rename this file to 'force' to force an update without confirmation" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/noforce; \
    cd ${DEPLOY_DIR_IMAGE}; \
    zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.ext4; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.manifest; \
    rm -f ${DEPLOY_DIR_IMAGE}/.ext4; \
    rm -f ${DEPLOY_DIR_IMAGE}/.manifest; \
    rm -Rf ${IMAGEDIR}; \
    "

UBI_VOLNAME = "rootfs"

# new 2 GB Flash Model
MKUBIFS_ARGS = "-m 4096 -e 1040384 -c 2048 -F"
UBINIZE_ARGS = "-m 4096 -p 1024KiB"

IMAGE_CMD_ubi_prepend = "\
    rm -rf ${IMAGE_ROOTFS}/boot/*; \
    rm -rf ${IMAGE_ROOTFS}/tmp/*; \
    "

IMAGE_CMD_ubi_append = "\
    mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
    mv ${IMGDEPLOYDIR}/${IMAGE_NAME}.rootfs.ubi ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${ROOTFS_FILE}; \
    cp ${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGETYPE}-${MACHINE}.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
    echo ${IMAGE_VER_STRING} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
    echo "rename this file to 'force' to force an update without confirmation" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/noforce; \
    cd ${DEPLOY_DIR_IMAGE}; \
    zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.ubi; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.manifest; \
    rm -f ${DEPLOY_DIR_IMAGE}/.ubifs; \
    rm -f ${DEPLOY_DIR_IMAGE}/.manifest; \
    rm -Rf ${IMAGEDIR}; \
    "
