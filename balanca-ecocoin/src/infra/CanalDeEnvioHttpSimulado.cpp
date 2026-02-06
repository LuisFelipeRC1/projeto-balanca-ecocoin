#include "CanalDeEnvioHttpSimulado.h"

CanalDeEnvioHttpSimulado::CanalDeEnvioHttpSimulado(const char *endpoint)
    : _endpoint(endpoint)
{
}

void CanalDeEnvioHttpSimulado::enviar(double pesoEmKg, double ecoCoins)
{
    // Simula um POST HTTPS imprimindo um payload JSON
    Serial.printf(
        "[HTTP SIM] POST %s\n"
        "Body: {\"pesoKg\": %.3f, \"ecoCoins\": %.3f}\n",
        _endpoint,
        pesoEmKg,
        ecoCoins);
}
