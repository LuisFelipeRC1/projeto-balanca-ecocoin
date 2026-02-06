#pragma once

#include "../core/CanalDeEnvio.h"

class CanalDeEnvioFake : public CanalDeEnvio
{
public:
    void enviar(double pesoEmKg, double ecoCoins) override;
};
