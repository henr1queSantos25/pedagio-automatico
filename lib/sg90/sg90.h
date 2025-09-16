#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 8
#define ZERO_GRAUS 500  // Pulso para ~0 graus
#define NOVENTA_GRAUS 1500 // Pulso para ~90 graus
#define CENTO_OITENTA_GRAUS 2500 // Pulso para ~180 graus

// === ASSINATURA DAS FUNÇÕES ===
void setup_SG90();
void set_angle(uint16_t pulse_width);