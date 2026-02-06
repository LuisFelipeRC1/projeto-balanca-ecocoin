#include "SistemaEcoCoin.h"

SistemaEcoCoin::SistemaEcoCoin(
    FonteDePeso& fonteDePeso,
    ConversorEcoCoin& conversor,
    CanalDeEnvio& canal
)
    : _fonteDePeso(fonteDePeso),
      _conversor(conversor),
      _canal(canal)
{
}

void SistemaEcoCoin::executarCiclo()
{
    double peso = _fonteDePeso.obterPesoEmKg();
    double ecoCoins = _conversor.converter(peso);
    _canal.enviar(peso, ecoCoins);
}
