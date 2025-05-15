// Copyright 2023 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define AUDIO_INIT_DELAY
#define AUDIO_PIN A10
#define AUDIO_PWM_DRIVER PWMD1
#define AUDIO_PWM_CHANNEL 3
#define AUDIO_PWM_PAL_MODE 1

#define TEMPO_DEFAULT 100
#define STARTUP_SONG SONG(STARTUP_SOUND)

#define BASE_LAYER 0
#define NUM_LAYER 1
#define QWERTY_LAYER 5

#define I2C1_SCL_PIN A13
#define I2C1_SDA_PIN A14
