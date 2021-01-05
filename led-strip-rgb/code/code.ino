#include <ESP8266WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID "Theo_2.4Ghz"
#define WIFI_PASS ""

#define APP_KEY ""
#define APP_SECRET ""

// obter o id dos dispositivos em https://portal.sinric.pro/device/list
#define BLUE_ID ""
#define BLUE_Pin 14 // GPIO D5
#define RED_ID ""
#define RED_Pin 12 // GPIO D6
#define GREEN_ID ""
#define GREEN_Pin 13 // GPIO D7

#define BAUD_RATE 9600 

void setupWiFi();
void setupSinricPro();
bool BlueState(const String &deviceId, bool &state);
bool RedState(const String &deviceId, bool &state);
bool GreenState(const String &deviceId, bool &state);

// main setup function
void setup()
{
    Serial.begin(BAUD_RATE);
    Serial.printf("\r\n\r\n");
    setupWiFi();
    setupSinricPro();
    pinMode(BLUE_Pin, OUTPUT);
    pinMode(RED_Pin, OUTPUT);
    pinMode(GREEN_Pin, OUTPUT);
}

void loop()
{
    SinricPro.handle();
}

bool BlueState(const String &deviceId, bool &state)
{
    state = !state;
    digitalWrite(BLUE_Pin, state);
    return true;
}

bool RedState(const String &deviceId, bool &state)
{
    state = !state;
    digitalWrite(RED_Pin, state);
    return true;
}

bool GreenState(const String &deviceId, bool &state)
{
    state = !state;
    digitalWrite(GREEN_Pin, state);
    return true;
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
    SinricProSwitch &mySwitchB = SinricPro[BLUE_ID];
    mySwitchB.onPowerState(BlueState);

    SinricProSwitch &mySwitchR = SinricPro[RED_ID];
    mySwitchR.onPowerState(RedState);

    SinricProSwitch &mySwitchG = SinricPro[GREEN_ID];
    mySwitchG.onPowerState(GreenState);

    // setup SinricPro
    SinricPro.onConnected([]() { Serial.printf("Conectado a nuvem SinricPro\r\n"); });
    SinricPro.onDisconnected([]() { Serial.printf("Desconectado a nuvem SinricPro\r\n"); });
    SinricPro.begin(APP_KEY, APP_SECRET);
}