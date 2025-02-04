#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_RED_PIN 13
#define LED_BLUE_PIN 12
#define LED_GREEN_PIN 11
#define BUTTON_A_PIN 5

// Variáveis de controlr
volatile bool sistema_ativo = false;
volatile uint32_t ultimo_tempo = 0;


// Protótipos das funções utilizadas
void setup();
void botao_irq_handler(uint gpio, uint32_t events);
int64_t desligar_leds_callback(alarm_id_t id, void *user_data);

int main() {
    stdio_init_all();

    // Função para inicialização dos componentes - LED e Botão 
    setup();

    // Função para Rotina de Interrupção do Botão 
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &botao_irq_handler);
    
    while (1) {
         if (sistema_ativo) {
            printf("Sistema ativo: LEDs em processo de desligamento.");
        } else {
            printf("Sistema inativo: Aguardando acionamento do botão.");
        }
        sleep_ms(1000);
    }
}

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

void botao_irq_handler(uint gpio, uint32_t events) {
    uint32_t tempo_atual = to_ms_since_boot(get_absolute_time());
    if (tempo_atual - ultimo_tempo < 200) return;
    ultimo_tempo = tempo_atual;
    
    if (!sistema_ativo) {
        sistema_ativo = true;
        gpio_put(LED_GREEN_PIN, 1);
        gpio_put(LED_BLUE_PIN, 1);
        gpio_put(LED_RED_PIN, 1);
       
        add_alarm_in_ms(3000, desligar_leds_callback, NULL, false);
    }
}

int64_t desligar_leds_callback(alarm_id_t id, void *user_data) {
    static int estado = 0;
    
    if (estado == 0) {
        gpio_put(LED_GREEN_PIN, 0);
        
        estado++;
        add_alarm_in_ms(3000, desligar_leds_callback, NULL, false);
    } else if (estado == 1) {
        gpio_put(LED_BLUE_PIN, 0);
        estado++;
        add_alarm_in_ms(3000, desligar_leds_callback, NULL, false);
    } else {
        gpio_put(LED_RED_PIN, 0);
        sistema_ativo = false;
        estado = 0;
    }
    return 0;
}