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
DYNAMIC_MACRO_ENABLE = yes
KEY_OVERRIDE_ENABLE = no

CAPS_WORD_ENABLE = yes

AUDIO_DRIVER = pwm_hardware
AUDIO_ENABLE = no

SRC += custom_keycodes.c
SRC += capsword.c

# note that the order is important here
SRC += qmk-vim/src/process_func.c
SRC += qmk-vim/src/numbered_actions.c
SRC += qmk-vim/src/motions.c
SRC += qmk-vim/src/actions.c
SRC += qmk-vim/src/modes.c
SRC += qmk-vim/src/vim.c
