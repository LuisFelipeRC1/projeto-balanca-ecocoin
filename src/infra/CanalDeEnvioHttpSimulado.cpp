#include "CanalDeEnvioHttpSimulado.h"

CanalDeEnvioHttpSimulado::CanalDeEnvioHttpSimulado(const char *endpoint)
    : _endpoint(endpoint)
{
}

void CanalDeEnvioHttpSimulado::enviar(double pesoEmKg, double ecoCoins)
{
    // Simula um POST HTTPS imprimindo um payload JSON.
    Serial.print("[HTTP SIM] POST ");
    Serial.println(_endpoint);
    Serial.print("Body: {\"pesoKg\": ");
    Serial.print(pesoEmKg, 3);
    Serial.print(", \"ecoCoins\": ");
    Serial.print(ecoCoins, 3);
    Serial.println("}");
}
