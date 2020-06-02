# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

BOX_BRAND = "xcore"

KERNEL_FILE = "kernel.bin"

DVBPROVIDER = "kernel"
DVBSKYPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    xcore-dvb-modules-${MACHINE} \
    kernel-module-extrawlan-rt8723bs \
    firmware-rtl8723bs \
"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "\
    ${@bb.utils.contains('MACHINE_FEATURES', 'v3d', 'xcore-v3ddriver-${MACHINE}', '',d)} \
    kernel-module-hci-uart \
    "

MACHINE_EXTRA_RRECOMMENDS += "\
    gstreamer1.0-plugin-dvbmediasink \
    gstreamer1.0-libav \
    "

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "xcore-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "xcore-blindscan-utils"

PREFERRED_PROVIDER_virtual/kernel = "linux-xcore"

MACHINE_FEATURES += "alsa 3dtv switchoff hdmicec"

BOOTLOGO_FILENAME = "splash.bin"

KERNEL_MODULE_AUTOLOAD += "\
	r8723bs \
	hci_uart \
	xfs \
	"
