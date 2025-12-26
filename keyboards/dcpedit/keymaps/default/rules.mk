VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes

CONSOLE_ENABLE = no
ENCODER_MAP_ENABLE = yes

QMK_SETTINGS = yes

TAP_DANCE_ENABLE = yes
LTO_ENABLE = yes
COMBO_ENABLE = yes
MACRO_ENABLE = yes
DYNAMIC_MACRO_ENABLE = no
KEY_OVERRIDE_ENABLE = no
NKRO_ENABLE = no
MOUSEKEY_ENABLE = no


CAPS_WORD_ENABLE = yes

# AUDIO_DRIVER = pwm_hardware
# AUDIO_ENABLE = yes

VPATH += keyboards/gboards

SRC += custom_keycodes.c
SRC += capsword.c
SRC += tapping.c
