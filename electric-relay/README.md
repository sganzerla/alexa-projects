# :electric_plug: electric-relay

Este projeto cria um dispositivo IOT que pode ser controlado pelos comandos de voz da Alexa, para ligar dois relés elétricos um para ligar uma lâmpada e outro para ligar um ventilador.

<a id="index"></a>

## :card_index: Requisitos

- [Hardware Eletrônicos e Elétricos](#hardware)
- [Arduino IDE com biblioteca p/ subir o firmware na placa](#ide)
- [Conta Sinric Pro](#sinric)
- [Alexa (App Alexa no Android ou IOS, Controle Amazon Fire Stick, Amazon Echo Dot)](#alexa)

<a id="hardware"></a>

## Hardware Eletrônicos

[Voltar ínicio](#index)

Item | Imagem | Item | Imagem
:------------------------: | :------------------------: | :------------------------: | :------------------------: |  
 1 Protoboard pequena (Somente para prototipagem) | ![image](https://user-images.githubusercontent.com/22710963/77499362-a8574a80-6e30-11ea-9744-a15c3206fd50.png) | 4 Cabos de conexão (Somente para prototipagem) | ![image](https://user-images.githubusercontent.com/22710963/77499606-5662f480-6e31-11ea-96fd-9e268dceb50f.png)
 2 LED 5V  (Somente para prototipagem)| ![image](https://user-images.githubusercontent.com/22710963/103470252-f64d9700-4d4e-11eb-908e-9c8fcf4fcd8c.png) | NodeMCU ESP8266 |  ![image](https://user-images.githubusercontent.com/22710963/79626592-9e5ef980-8107-11ea-8245-9ef23642a350.png)
 Relé SPDT 2 canais | ![image](https://user-images.githubusercontent.com/22710963/103469260-4c1b4280-4d41-11eb-90bb-0120b21ff696.png) | 1 tomada macho, 2 tomadas fêmeas e 2 metros de fio p/ fazer uma extensão  |  ![image](https://user-images.githubusercontent.com/22710963/103470387-8fc97880-4d50-11eb-9ab1-98e7a7c6170b.png)

<a id="ide"></a>

## IDE Arduino

[Voltar ínicio](#index)

Tutorial para configurar IDE Arduino no VSCode

1. Baixar a IDE Arduino na página oficial
2. Descompactar dentro da pasta `/opt` (somente Ubuntu)
3. Dar permissão de escrita na pasta `/opt` (somente Ubuntu)
4. Instalar o plugin Arduino no VSCode feito pela Microsoft
5. Configurar o path da extensão do Arduino no VSCode `/opt/arduino-x/` (Ubuntu) e `local instalado` (Windows)
6. Reinstalar plugin Arduino no VSCode
7. Conceder permissão de escrita na porta USB `sudo a+rw /dev/tty/USB0` (somente Ubuntu)



## Referência

[Automação Residencial com Alexa (Amazon) e NodeMCU](https://blog.eletrogate.com/automacao-residencial-com-alexa-amazon-e-nodemcu/)
