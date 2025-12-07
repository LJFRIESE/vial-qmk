COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
NKRO_ENABLE = yes           # Enable N-Key Rollover
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes

LTO_ENABLE = yes
VIAL_INSECURE = yes
VIA_ENABLE = yes

KEYCODE_STRING_ENABLE = no
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration

UNICODE_ENABLE = no
OLED_DRIVER_ENABLE = no
MIDI_ENABLE = no
BLUETOOTH_ENABLE = no
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

# project specific files
CUSTOM_MATRIX = lite
UART_DRIVER_REQUIRED = yes
SERIAL_DRIVER = vendor
SRC += matrix.c

