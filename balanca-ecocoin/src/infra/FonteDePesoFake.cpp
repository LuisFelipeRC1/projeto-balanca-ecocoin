#include "FonteDePesoFake.h"

FonteDePesoFake::FonteDePesoFake(double pesoFixo)
    : _pesoFixo(pesoFixo)
{
}

double FonteDePesoFake::obterPesoEmKg()
{
    return _pesoFixo;
}
