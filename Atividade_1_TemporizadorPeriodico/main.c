#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED_PIN 13
#define LED_YELLOW_PIN 12
#define LED_GREEN_PIN 11

void initLeds();

int main()
{
    stdio_init_all();

    // Configuração do temporizador periódico
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, temporizador_callback, NULL, &timer);

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

bool temporizador_callback(struct repeating_timer *t){
    
}
