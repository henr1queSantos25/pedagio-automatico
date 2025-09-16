#include "sg90.h"

// ========================================================================
// FUNÇÕES DO SERVOMOTOR SG90
// ========================================================================
/**
 *  @brief Configura o pino do servomotor SG90 para operação PWM
 */
void setup_SG90() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f);
    pwm_config_set_wrap(&config, 19999);
    pwm_init(slice_num, &config, true);
}

/**
 *  @brief Define o ângulo do servomotor SG90 através da largura do pulso
 *  @param pulse_width Largura do pulso em microssegundos (500 a 2500)
 */
void set_angle(uint16_t pulse_width) {
    if (pulse_width < ZERO_GRAUS || pulse_width > CENTO_OITENTA_GRAUS) {
        return; 
    }
    pwm_set_gpio_level(SERVO_PIN, pulse_width);
}