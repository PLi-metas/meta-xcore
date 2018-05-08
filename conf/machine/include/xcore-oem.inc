# We know about rtc
include conf/machine/include/build-extras.inc

KERNEL_FILE = "kernel.bin"

DVBPROVIDER = "kernel"
DVBSKYPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += " \
    kernel-module-cdfs \
    ${@bb.utils.contains('MACHINE_FEATURES', 'v3d', 'xcore-v3ddriver-${MACHINE}', '',d)} \
    "

MACHINE_EXTRA_RRECOMMENDS += " \
    gstreamer1.0-plugin-dvbmediasink \
    gstreamer1.0-libav \
    "

include conf/machine/include/autoload-filesystems.inc

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "xcore-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "xcore-blindscan-utils"

PREFERRED_PROVIDER_virtual/kernel = "linux-xcore"

MACHINE_FEATURES += "alsa 3dtv switchoff hdmicec omb boxmodel"
#MACHINE_FEATURES += "bootsplash"

BOOTLOGO_FILENAME = "splash.bin"
