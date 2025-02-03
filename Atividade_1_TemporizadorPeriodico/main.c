#include <stdio.h>
#include "pico/stdlib.h"

#define LED_RED_PIN 13
#define LED_YELLOW_PIN 12
#define LED_GREEN_PIN 11

void initLeds();

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

//Função para Inicializar os LEDS
void initLeds(){
    gpio_init(LED_RED_PIN);
    gpio_init(LED_YELLOW_PIN);
    gpio_init(LED_GREEN_PIN);
    
    gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);
    gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
}
