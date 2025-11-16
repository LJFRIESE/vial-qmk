// tap_dance_config.h
#pragma once

typedef struct {
    uint8_t index;
    uint16_t tap;
    uint16_t hold;
    uint16_t double_tap;
    uint16_t tap_hold;
    uint16_t tapping_term;
} tap_dance_config_t;


// Declare external array and its length
extern const tap_dance_config_t tap_dance_configs[];
extern const size_t num_tap_dance_configs;

void initialize_tap_dance(void);

