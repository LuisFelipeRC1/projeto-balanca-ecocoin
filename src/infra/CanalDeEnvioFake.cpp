#include "CanalDeEnvioFake.h"
#include <Arduino.h>

void CanalDeEnvioFake::enviar(double pesoEmKg, double ecoCoins)
{
    Serial.print("Peso (kg): ");
    Serial.print(pesoEmKg, 3);
    Serial.print(" | EcoCoins: ");
    Serial.println(ecoCoins, 3);
}
