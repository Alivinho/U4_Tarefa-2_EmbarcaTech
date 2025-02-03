#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED_PIN 13
#define LED_YELLOW_PIN 12
#define LED_GREEN_PIN 11

// Variável para controle do estado dos LEDS
int statusLed = 0;

// Protótipos das Funções Utilizadas
void initLeds();
bool temporizador_callback(struct repeating_timer *t);

int main()
{
    stdio_init_all();

    // Inicia os LEDS
    initLeds();

    // Configuração do temporizador periódico
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, temporizador_callback, NULL, &timer);

    gpio_put(LED_RED_PIN, 1);

    while (true) {
        printf("Semáforo ativo: Estado %d\n", statusLed);
        sleep_ms(1000);
    }
}

//Função para Inicializar os LEDS
void initLeds(){
    gpio_init(LED_RED_PIN);
    gpio_init(LED_YELLOW_PIN);
    gpio_init(LED_GREEN_PIN);
    
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
}

bool temporizador_callback(struct repeating_timer *t){
    gpio_put(LED_RED_PIN, 0);
    gpio_put(LED_YELLOW_PIN, 0);
    gpio_put(LED_GREEN_PIN, 0);

    if (statusLed == 0) {
        gpio_put(LED_RED_PIN, 1); // Próximo: amarelo
        gpio_put(LED_GREEN_PIN, 1);
        statusLed = 1;
    } else if (statusLed == 1) {
        gpio_put(LED_GREEN_PIN, 1); // Próximo: verde
        statusLed = 2;
    } else {
        gpio_put(LED_RED_PIN, 1); // Volta para vermelho
        statusLed = 0;
    }

    return true; 
    
}
