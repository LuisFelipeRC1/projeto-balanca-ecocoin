#pragma once

#include "../core/CanalDeEnvio.h"
#include <Arduino.h>

class CanalDeEnvioHttpSimulado : public CanalDeEnvio
{
public:
    explicit CanalDeEnvioHttpSimulado(const char *endpoint);
    void enviar(double pesoEmKg, double ecoCoins) override;

private:
    const char *_endpoint;
};
