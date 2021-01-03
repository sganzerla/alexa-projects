# :electric_plug: electric-relay

[Voltar](https://github.com/sganzerla/alexa-projects)

Este projeto cria um dispositivo IOT que pode ser controlado pelos comandos de voz da Alexa, para ligar dois relés elétricos um para ligar uma lâmpada e outro para ligar um ventilador.

<a id="index"></a>

## :card_index: Índice de Requisitos

- [Hardware Eletrônicos e Elétricos](#hardware)
- [Arduino IDE com biblioteca p/ subir o firmware na placa](#ide)
- [Conta Sinric Pro](#sinric)
- [Alexa (App Alexa no Android ou IOS, Controle Amazon Fire Stick, Amazon Echo Dot)](#alexa)

## :bulb: Como reproduzir/usar

- [Código Fonte](#code)
- [Circuito](#circuit)
- [Como Usar](#use)
  
<a id="hardware"></a>

## Hardware Eletrônicos

[Voltar início](#index)

Item | Imagem | Item | Imagem
:------------------------: | :------------------------: | :------------------------: | :------------------------: |  
 1 Protoboard pequena (Somente para prototipagem) | ![image](https://user-images.githubusercontent.com/22710963/77499362-a8574a80-6e30-11ea-9744-a15c3206fd50.png) | 4 Cabos de conexão (Somente para prototipagem) | ![image](https://user-images.githubusercontent.com/22710963/77499606-5662f480-6e31-11ea-96fd-9e268dceb50f.png)
 2 LED 5V  (Somente para prototipagem)| ![image](https://user-images.githubusercontent.com/22710963/103470252-f64d9700-4d4e-11eb-908e-9c8fcf4fcd8c.png) | NodeMCU ESP8266 |  ![image](https://user-images.githubusercontent.com/22710963/79626592-9e5ef980-8107-11ea-8245-9ef23642a350.png)
 Relé SPDT 2 canais | ![image](https://user-images.githubusercontent.com/22710963/103469260-4c1b4280-4d41-11eb-90bb-0120b21ff696.png) | 1 tomada macho, 2 tomadas fêmeas e 2 metros de fio p/ fazer uma extensão  |  ![image](https://user-images.githubusercontent.com/22710963/103470387-8fc97880-4d50-11eb-9ab1-98e7a7c6170b.png)

<a id="ide"></a>

## IDE Arduino

[Voltar início](#index)

### Tutorial para configurar IDE Arduino no VSCode

1. Baixar a IDE Arduino na página oficial
2. Descompactar dentro da pasta `/opt` (somente Ubuntu)
3. Dar permissão de escrita na pasta `/opt` (somente Ubuntu)
4. Instalar o plugin Arduino no VSCode feito pela Microsoft
5. Configurar o path da extensão do Arduino no VSCode `/opt/nome-pasta/` (Ubuntu) e `local instalado` (Windows)
6. Reinstalar plugin Arduino no VSCode
7. Conceder permissão de escrita na porta USB `sudo a+rw /dev/tty/USB0` (somente Ubuntu)

### Habilitar placas ESP8266 na IDE Arduino

1. Abrir IDE Arduino
2. Colar url dentro de preferências de gerenciadores de placas `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
3. Ir em gerenciadores de placas, procurar e instalar `esp8266 by Community`
4. Abrir VSCode com qualquer arquivo `.ino`
5. Clicar na aba `show board config` no rodapé e escolher `Generic ESP8266`

### Instalar biblioteca Sinric Pro

1. Abrir IDE Arduino
2. Ir em Gerenciar bibliotecas
3. Pesquisar e instalar `Sinric` de Boris Jaeger
4. Confirmar a instalação das dependências automaticamente: `ArduinoJson e WebSockets`

<a id="sinric"></a>

## Sinric Pro

[Voltar início](#index)

O Sinric Pro é um serviço de Cloud (nuvem) para dispositivos inteligentes, onde ele suporta uma série de dispositivos inteligentes que podemos criar e integrar a ele (até 3 gratuitamente)

1. Criar uma conta no [Sinric](https://portal.sinric.pro/register)
2. Cadastrar [dispositivos](https://portal.sinric.pro/device/list) com o nome que serão invocados pela Alexa
3. Preencher nome, descrição (pra facilitar a organização/identificação) e tipo switch (on/off)
4. Anotar o `ID` de cada dispositivo cadastrado para colocar no código fonte da placa
5. Anotar a chave e a credencial para colocar no código fonte da placa, obtidos na aba [Credenciais](https://portal.sinric.pro/credential/list)

<a id="alexa"></a>

## Alexa

[Voltar início](#index)

1. Instalar aplicativo Alexa e criar uma conta.
2. Abrir a aba `Dispositivos` no rodapé direito e ativar `Skils de casa inteligente`
3. Pesquisar, instalar e fazer login: `Sinric Pro`
4. Dentro do Sinric Pro clicar em `Descobrir dispositivos`
5. Criar um grupo e adicionar os dispositivos criados para manter organizado os items

Agora os dispositivos podem ser controlados através do microfone no aplicativo no celular, por um controle Fire Stick, um Echo Dot, etc...

<a id="code"></a>

## Código

[Voltar início](#index)

1. Preencher `WIFI_SSID` e `WIFI_PASS` com o nome da rede e senha wifi 2.4Ghz respectivamente
2. Preencher `APP_KEY` e `APP_SECRET`  com as credenciais obtidas em [Credenciais](https://portal.sinric.pro/credential/list)
3. Preencher `Lan_ID` o ID gerado para cada dispositivo pelo [Sinric](https://portal.sinric.pro/device/list)
4. Alterar (ou não) o GPIO da placa `ǸodeMCU`
5. Enviar o firmware para a placa definindo `Show board config` (no rodapé do VSCode) como Generic ESP8266, selecionando porta USB da placa e conceder permissão de escrita na porta USB `sudo a+rw /dev/tty/USB0` (somente Ubuntu)



<a id="circuit"></a>

## Circuito

[Voltar início](#index)


<a id="use"></a>

## Como Usar

[Voltar início](#index)

## Referência

[Automação Residencial com Alexa (Amazon) e NodeMCU](https://blog.eletrogate.com/automacao-residencial-com-alexa-amazon-e-nodemcu/)
