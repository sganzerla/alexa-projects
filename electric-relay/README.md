# :electric_plug: electric-relay

Este projeto cria um dispositivo IOT que pode ser controlado pelos comandos de voz da Alexa, para ligar dois relés elétricos um para ligar uma lâmpada e outro para ligar um ventilador.

## :card_index: Requisitos

- [Hardware Eletrônicos](#eletronico)
- [Material Elétricos](#eletrico)
- [Arduino IDE com biblioteca p/ subir o firmware na placa](#ide)
- [Conta Sinric Pro](#sinric)
- [Alexa (App Alexa no Android ou IOS, Controle Amazon Fire Stick, Amazon Echo Dot)](#alexa)

<a id="eletronico"></a>

## Hardware Eletrônicos

### a) 1 Protoboard pequena (Somente para prototipagem)

![image](https://user-images.githubusercontent.com/22710963/77499362-a8574a80-6e30-11ea-9744-a15c3206fd50.png)

### b) 4 Cabos de conexão (Somente para prototipagem)

![image](https://user-images.githubusercontent.com/22710963/77499606-5662f480-6e31-11ea-96fd-9e268dceb50f.png)

### c) 2 LED 5V  (Somente para prototipagem)

Corrente em placas NodeMCU é 3v então não é necessário utilizar um resistor de 220ohms.

![image](https://user-images.githubusercontent.com/22710963/79626643-001f6380-8108-11ea-8705-a3e44ed63dce.png)

### d) NodeMCU ESP8266

![image](https://user-images.githubusercontent.com/22710963/79626592-9e5ef980-8107-11ea-8245-9ef23642a350.png)

### f) Relé SPDT 2 canais

Não possui lado de polaridade fixo.

![image](https://user-images.githubusercontent.com/22710963/103469260-4c1b4280-4d41-11eb-90bb-0120b21ff696.png)

## Referência

[Automação Residencial com Alexa (Amazon) e NodeMCU](https://blog.eletrogate.com/automacao-residencial-com-alexa-amazon-e-nodemcu/)
