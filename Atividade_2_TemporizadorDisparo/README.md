# Controle de LEDs com Temporização de Um Disparo (One Shot) - Raspberry Pi Pico

Este repositório contém um código para controle de LEDs em um Raspberry Pi Pico utilizando um botão como acionador e temporizadores para desligamento sequencial dos LEDs.

## Estrutura do Código

O código está organizado da seguinte maneira:

- **Definição de Pinos:**
  - LED vermelho: GPIO 13
  - LED azul: GPIO 12
  - LED verde: GPIO 11
  - Botão: GPIO 5

- **Inicialização dos Componentes:**
  - A função `setup()` configura os LEDs como saída e o botão como entrada com pull-up ativado.

- **Loop Principal:**
  - Monitora o estado do sistema e imprime mensagens sobre sua condição atual.

- **Interrupção do Botão:**
  - A função `botao_irq_handler()` é chamada quando o botão é pressionado, ativando os LEDs.
  - Um temporizador é acionado para desligar os LEDs sequencialmente a cada 3 segundos.

- **Desligamento Sequencial:**
  - A função `desligar_leds_callback()` apaga os LEDs um por um com um intervalo de 3 segundos entre cada apagamento.

## Funcionamento

1. O sistema inicia inativo, aguardando o acionamento do botão.
2. Quando o botão é pressionado:
   - Todos os LEDs acendem simultaneamente.
   - Um temporizador é acionado para iniciar o desligamento progressivo dos LEDs.
3. O desligamento ocorre na seguinte ordem, com intervalos de 3 segundos:
   - LED verde apaga primeiro.
   - LED azul apaga em seguida.
   - LED vermelho apaga por último.
4. Após o desligamento completo, o sistema volta ao estado inativo, aguardando nova interação.

## Como Utilizar

### Pré-requisitos

- Um Raspberry Pi Pico.
- LEDs conectados aos pinos GPIO correspondentes com resistores adequados.
- Um botão conectado ao GPIO 5 com pull-up ativado.
- Ambiente de desenvolvimento configurado para compilar e carregar códigos no Raspberry Pi Pico.

### Passos para Compilar e Executar

1. Clone este repositório:
   ```sh
   git clone https://github.com/seu_usuario/seu_repositorio.git
   ```
2. Acesse o diretório do projeto:
   ```sh
   cd seu_repositorio
   ```
3. Compile o código e carregue-o no Raspberry Pi Pico.
4. Pressione o botão para ativar os LEDs e observe o desligamento sequencial.
5. Acompanhe as mensagens no terminal para visualizar o processo em tempo real.

## Dependências

Este código utiliza as seguintes bibliotecas:
- `pico/stdlib.h` - Para funções básicas de entrada e saída.
- `hardware/gpio.h` - Para manipulação dos pinos GPIO.
- `hardware/timer.h` - Para configuração de temporizadores e alarmes.
