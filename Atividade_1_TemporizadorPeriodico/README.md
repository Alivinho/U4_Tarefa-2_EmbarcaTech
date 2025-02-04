# Controle de LEDs com Temporizador - Raspberry Pi Pico

Este repositório contém um código para controle de LEDs em um Raspberry Pi Pico utilizando temporizadores periódicos. O código simula um sistema de sinalização luminosa, alternando entre três LEDs (vermelho, amarelo e verde) com um intervalo fixo de tempo.

## Estrutura do Código

O código está estruturado da seguinte forma:

- **Definição de Pinos:**
  - Os pinos GPIO 13, 12 e 11 são definidos para controlar os LEDs vermelho, amarelo e verde, respectivamente.
  
- **Inicialização dos LEDs:**
  - A função `initLeds()` configura os pinos como saída, garantindo que os LEDs possam ser acionados corretamente.

- **Loop Principal:**
  - O programa entra em um loop infinito onde exibe mensagens informativas sobre o estado do semáforo.
  - A cada segundo, é exibido no console o status atual do sistema, indicando se a passagem está proibida, se há necessidade de atenção ou se está permitida.

- **Temporizador:**
  - A função `temporizador_callback()` é acionada a cada 3 segundos por meio da API de temporizadores do Raspberry Pi Pico.
  - O estado dos LEDs é alternado seguindo uma lógica de semáforo: vermelho → amarelo → verde → vermelho.
  - Cada estado representa uma etapa do fluxo de controle de tráfego.

## Funcionamento

1. O programa inicia com o LED vermelho aceso, indicando que a passagem está proibida.
2. Após 3 segundos, o LED amarelo acende, representando um aviso de transição.
3. Depois de mais 3 segundos, o LED verde é acionado, permitindo a passagem.
4. Finalmente, após mais 3 segundos, o LED vermelho volta a acender, reiniciando o ciclo.
5. O ciclo se repete indefinidamente.
6. Durante a execução, mensagens são exibidas no terminal através do `printf()`, informando o estado atual.

## Como Utilizar

### Pré-requisitos

- Um Raspberry Pi Pico.
- LEDs conectados corretamente aos pinos GPIO 13, 12 e 11 com resistores adequados.
- Um ambiente de desenvolvimento configurado para compilar e carregar códigos no Raspberry Pi Pico.

### Passos para Compilar e Executar

1. Clone este repositório em seu ambiente de desenvolvimento:
   ```sh
   git clone https://github.com/seu_usuario/seu_repositorio.git
   ```
2. Acesse o diretório do projeto:
   ```sh
   cd seu_repositorio
   ```
3. Compile o código e carregue-o no Raspberry Pi Pico.
4. Conecte os LEDs e verifique seu funcionamento conforme o ciclo definido.
5. Acompanhe as mensagens no terminal para visualizar a transição entre os estados do semáforo.

