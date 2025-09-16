#include <stdio.h>
#include "pico/stdlib.h"

// === BIBLIOTECAS DA PASTA LIB ===
#include "hcSR04.h" 
#include "sg90.h"

// === DEFINIÇÕES DE PINOS ===
#define TRIGGER 16 // Pino trigger do sensor ultrassônico
#define ECHO 17 // Pino echo do sensor ultrassônico




// ========================================================================
// PROTÓTIPOS DAS FUNÇÕES
// ========================================================================
void setup();

int main() {
    setup();



    uint64_t distance;
    while (1) {
        distance = getCm(TRIGGER, ECHO);
        if (distance == 0) {
            printf("Fora de alcance\n");
        } else {
            printf("Distância: %llu cm\n", distance);
            if (distance < 15) {
                set_angle(CENTO_OITENTA_GRAUS); // Fecha a cancela
            } else {
                set_angle(NOVENTA_GRAUS); // Abre a cancela
                sleep_ms(1500);
            }
        }
        sleep_ms(500);
    }
}


// ========================================================================
// FUNÇÕES DE INICIALIZAÇÃO
// ========================================================================
/**
 * @brief Inicializa todos os periféricos e sensores do sistema
 */
void setup() {
    stdio_init_all();
    setupUltrasonicPins(TRIGGER, ECHO);
    setup_SG90();
}
