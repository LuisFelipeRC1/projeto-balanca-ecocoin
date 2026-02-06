#pragma once

#include "../core/FonteDePeso.h"
#include <HX711.h>

class FonteDePesoHX711 : public FonteDePeso
{
public:
    explicit FonteDePesoHX711(
        int pinDout,
        int pinSck,
        float fatorCalibracao,
        int tamanhoJanela = 8
    );

    double obterPesoEmKg() override;

private:
    HX711 _hx711;
    float _fatorCalibracao;
    int _tamanhoJanela;
    float _janela[16];
    int _indice;
    int _preenchidos;
    double _ultimoPesoKg;
};
