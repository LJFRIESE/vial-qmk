VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes

DEFERRED_EXEC_ENABLE = yes
QMK_SETTINGS = yes

LTO_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
MACRO_ENABLE = yes
CAPS_WORD_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes


AUDIO_DRIVER = pwm_hardware
AUDIO_ENABLE = no

SRC += custom_keycodes.c
SRC += led.c
SRC += capsword.c

# note that the order is important here
SRC += qmk-vim/src/mac_mode.c
SRC += qmk-vim/src/process_func.c
SRC += qmk-vim/src/numbered_actions.c
SRC += qmk-vim/src/motions.c
SRC += qmk-vim/src/actions.c
SRC += qmk-vim/src/modes.c
SRC += qmk-vim/src/vim.c
