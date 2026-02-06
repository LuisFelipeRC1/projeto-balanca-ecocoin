#include "CanalDeEnvioFake.h"
#include <Arduino.h>

void CanalDeEnvioFake::enviar(double pesoEmKg, double ecoCoins)
{
    Serial.printf("Peso (kg): %.3f | EcoCoins: %.3f\n", pesoEmKg, ecoCoins);
}
