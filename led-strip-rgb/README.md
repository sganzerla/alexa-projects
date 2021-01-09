# :high_brightness: led-strip-rgb

[Voltar](https://github.com/sganzerla/alexa-projects)

Este projeto utiliza uma fita de led rgb (não endereçados) e transforma em um dispositivo IOT que pode ligar e desligar as cores sendo controlado pelos comandos de voz da Alexa.

 - | - | -
:----------------------------------------------------: | :----------------------------------------------------:| :----------------------------------------------------:
![20210108_222602](https://user-images.githubusercontent.com/22710963/104080178-5471f280-5205-11eb-8fc3-07cf7b281fc6.jpg) | ![20210108_222625](https://user-images.githubusercontent.com/22710963/104080207-7b302900-5205-11eb-8b55-0308c238aa8f.jpg) | ![20210108_222657](https://user-images.githubusercontent.com/22710963/104080210-7e2b1980-5205-11eb-81b8-a670612dec7f.jpg)

<a id="index"></a>

## :card_index: Índice de Requisitos

- [Hardware](#hardware)
- [Arduino IDE](#ide)
- [Sinric Pro](#sinric)
- [Alexa](#alexa)

## :bulb: Como reproduzir/usar

- [Código Fonte](#code)
- [Circuito](#circuit)
- [Como Usar](#use)
  
<a id="hardware"></a>

## Hardware

[Voltar início](#index)

Item | Imagem | Item | Imagem
:------------------------: | :------------------------: | :------------------------: | :------------------------: |  
 1 Protoboard pequena (Somente para prototipagem) | ![image](https://user-images.githubusercontent.com/22710963/77499362-a8574a80-6e30-11ea-9744-a15c3206fd50.png) | Cabos de conexão (Somente para prototipagem) | ![image](https://user-images.githubusercontent.com/22710963/77499606-5662f480-6e31-11ea-96fd-9e268dceb50f.png)
 1 NodeMCU ESP8266 |  ![image](https://user-images.githubusercontent.com/22710963/79626592-9e5ef980-8107-11ea-8245-9ef23642a350.png) | 1m de fita de led rgb | ![image](https://user-images.githubusercontent.com/22710963/103602181-1a91ab00-4eea-11eb-9c78-c7e2ffe70b61.png)

<a id="ide"></a>

## IDE Arduino

[Voltar início](#index)

Instruções com as bibliotecas p/ subir o firmware na placa.
### Tutorial para configurar IDE Arduino no VSCode

1. Baixar a IDE Arduino na página oficial
2. Descompactar dentro da pasta `/opt` (somente Ubuntu)
3. Dar permissão de escrita na pasta `/opt` (somente Ubuntu)
4. Instalar o plugin Arduino no VSCode feito pela Microsoft
5. Configurar o path da extensão do Arduino no VSCode `/opt/nome-pasta/` (Ubuntu) e `local instalado` (Windows)
6. Reinstalar plugin Arduino no VSCode
7. Conceder permissão de escrita na porta USB `sudo usermod a+rw /dev/tty/USB0` (somente Ubuntu)

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

O Sinric Pro é um serviço de Cloud (nuvem) para dispositivos inteligentes, onde ele suporta uma série de dispositivos inteligentes que podemos criar e integrar a ele (até 3 gratuitamente). Neste projeto cada cor da fita vai ser um dispositivo diferente (RED, GREEN e BLUE)

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
5. Criar um grupo e adicionar os dispositivos criados para manter organizado os itens

Agora os dispositivos podem ser controlados através do microfone no aplicativo no celular, por um controle Fire Stick, um Echo Dot, etc...

<a id="code"></a>

## Código Fonte

[Voltar início](#index)

0. Código fonte está disponível [aqui](code/code.ino).
1. Preencher `WIFI_SSID` e `WIFI_PASS` com o nome da rede e senha wifi 2.4Ghz respectivamente
2. Preencher `APP_KEY` e `APP_SECRET`  com as credenciais obtidas em [Credenciais](https://portal.sinric.pro/credential/list)
3. Preencher `Lan_ID` o ID gerado para cada dispositivo pelo [Sinric](https://portal.sinric.pro/device/list)
4. Alterar (ou não) o GPIO da placa `ǸodeMCU`
5. Enviar o firmware para a placa definindo `Show board config` (no rodapé do VSCode) como Generic ESP8266, selecionando porta USB da placa e conceder permissão de escrita na porta USB `sudo chmod a+rw /dev/tty/USB0` (somente Ubuntu)

<a id="circuit"></a>

## Circuito

[Voltar início](#index)

Circuito de prototipação

[image](resources/RGBLED.png)

<a id="use"></a>

## Como Usar

[Voltar início](#index)

No aplicativo Alexa ou no controle da Fire Stick TV com o comando de voz:

"- Alexa, ligue luz vermelha / Alexa ligue luz verde"

O comando deve ser de acordo com o nome do dispositivo cadastrado no Sinric Pro.

## Referência

[Automação Residencial com Alexa (Amazon) e NodeMCU](https://blog.eletrogate.com/automacao-residencial-com-alexa-amazon-e-nodemcu/)
