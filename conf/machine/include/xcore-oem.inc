# We know about rtc
require conf/machine/include/build-extras.inc

BOX_BRAND = "xcore"

KERNEL_FILE = "kernel.bin"

DVBPROVIDER = "kernel"
DVBSKYPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    xcore-dvb-modules-${MACHINE} \
    rt8723bs \
    firmware-rtl8723bs \
"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "\
    kernel-module-cdfs \
    ${@bb.utils.contains('MACHINE_FEATURES', 'v3d', 'xcore-v3ddriver-${MACHINE}', '',d)} \
    kernel-module-hci-uart \
    "

MACHINE_EXTRA_RRECOMMENDS += "\
    gstreamer1.0-plugin-dvbmediasink \
    gstreamer1.0-libav \
    "

require conf/machine/include/autoload-filesystems.inc

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "xcore-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "xcore-blindscan-utils"

PREFERRED_PROVIDER_virtual/kernel = "linux-xcore"

MACHINE_FEATURES += "alsa 3dtv switchoff hdmicec"

BOOTLOGO_FILENAME = "splash.bin"

### 8723BS wireless/bluetooth ###
KERNEL_MODULE_AUTOLOAD += "r8723bs"
KERNEL_MODULE_AUTOLOAD += "hci_uart"
