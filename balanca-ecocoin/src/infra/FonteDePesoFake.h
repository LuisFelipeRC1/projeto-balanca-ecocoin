#pragma once

#include "../core/FonteDePeso.h"

class FonteDePesoFake : public FonteDePeso
{
public:
    explicit FonteDePesoFake(double pesoFixo);

    double obterPesoEmKg() override;

    private:
        double _pesoFixo;
};
