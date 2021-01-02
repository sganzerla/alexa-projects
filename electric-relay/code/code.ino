#include <ESP8266WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID "xx"
#define WIFI_PASS "xx"

#define APP_KEY "xx"
#define APP_SECRET "xx"

// obter o id dos dispositos em https://portal.sinric.pro/device/list
#define Lan_ID "xx"
#define Lan_Pin 12 // GPIO D6
#define Fan_ID "xx"
#define Fan_Pin 14 // GPIO D5

#define BAUD_RATE 9600 // Se precisar, pode trocar o baud rate

void setupWiFi();
void setupSinricPro();
bool LanState(const String &deviceId, bool &state);
bool FanState(const String &deviceId, bool &state);

// main setup function
void setup()
{
    Serial.begin(BAUD_RATE);
    Serial.printf("\r\n\r\n");
    setupWiFi();
    setupSinricPro();
    pinMode(Lan_Pin, OUTPUT);
    pinMode(Fan_Pin, OUTPUT);
}

void loop()
{
    SinricPro.handle();
}

bool LanState(const String &deviceId, bool &state)
{
    Serial.printf("A lampada foi %s\r\n", state ? "ligada" : "desligada");
    digitalWrite(Lan_Pin, state);
    return true; // request handled properly
}

bool FanState(const String &deviceId, bool &state)
{
    Serial.printf("O ventilador foi %s\r\n", state ? "ligado" : "desligado");
    digitalWrite(Fan_Pin, state);
    return true; // request handled properly
}

// setup das conexões Wifi
void setupWiFi()
{
    Serial.printf("\r\n[Wifi]: Conectando...");
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.printf(".");
        delay(250);
    }

    Serial.printf("Conectado!\r\n[WiFi]: Endereço de IP e %s\r\n", WiFi.localIP().toString().c_str());
}

// setup das funções para o SinricPro
void setupSinricPro()
{
    // add devices and callbacks to SinricPro
    SinricProSwitch &mySwitch2 = SinricPro[Lan_ID];
    mySwitch2.onPowerState(LanState);

    SinricProSwitch &mySwitch4 = SinricPro[Fan_ID];
    mySwitch4.onPowerState(FanState);

    // setup SinricPro
    SinricPro.onConnected([]() { Serial.printf("Conectado a nuvem SinricPro\r\n"); });
    SinricPro.onDisconnected([]() { Serial.printf("Desconectado a nuvem SinricPro\r\n"); });
    SinricPro.begin(APP_KEY, APP_SECRET);
}