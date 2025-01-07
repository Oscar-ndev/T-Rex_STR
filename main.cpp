#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "driver/mcpwm.h"
#include "soc/mcpwm_periph.h"

#define PIN_SERVO1 14
#define PIN_SERVO2 12
#define PIN_ANALOG 33

#define SERVO_MIN_PULSEWIDTH 500
#define SERVO_MAX_PULSEWIDTH 2500
#define SERVO_MAX_ANGLE 180

static uint32_t angle_to_pulsewidth(int angle) {
    return SERVO_MIN_PULSEWIDTH + (angle * (SERVO_MAX_PULSEWIDTH - SERVO_MIN_PULSEWIDTH) / SERVO_MAX_ANGLE);
}

void app_main() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_5, ADC_ATTEN_DB_11);

    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, PIN_SERVO1);
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, PIN_SERVO2);

    mcpwm_config_t pwm_config;
    pwm_config.frequency = 50;
    pwm_config.cmpr_a = 0;
    pwm_config.cmpr_b = 0;
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);

    while (1) {
        int valor = adc1_get_raw(ADC1_CHANNEL_5);

        int angle1 = (valor < 690) ? 30 : 90;
        int angle2 = (valor < 690) ? 150 : 90;

        uint32_t pulsewidth1 = angle_to_pulsewidth(angle1);
        uint32_t pulsewidth2 = angle_to_pulsewidth(angle2);

        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, pulsewidth1);
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, pulsewidth2);

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
