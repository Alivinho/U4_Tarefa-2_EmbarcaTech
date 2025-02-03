#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define LED_RED_PIN 13
#define LED_BLUE_PIN 12
#define LED_GREEN_PIN 11

#define BUTTON_A_PIN 5



int main(){

    stdio_init_all();

    // Inicialização dos componentes (Leds e Botão)
    setup();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

// Função para inicializar o LED RGB e o Botão
void setup() {
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);

    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
}
