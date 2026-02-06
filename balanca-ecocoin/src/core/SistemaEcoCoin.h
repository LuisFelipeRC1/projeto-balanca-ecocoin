#pragma once

#include "FonteDePeso.h"
#include "ConversorEcoCoin.h"
#include "CanalDeEnvio.h"

class SistemaEcoCoin
{
public:
    SistemaEcoCoin(
        FonteDePeso& fonteDePeso,
        ConversorEcoCoin& conversor,
        CanalDeEnvio& canal
    );

    void executarCiclo();

private:
    FonteDePeso& _fonteDePeso;
    ConversorEcoCoin& _conversor;
    CanalDeEnvio& _canal;
};
