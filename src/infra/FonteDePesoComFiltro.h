#pragma once

#include "../core/FonteDePeso.h"

class FonteDePesoComFiltro : public FonteDePeso
{
public:
    explicit FonteDePesoComFiltro(FonteDePeso& fonteBase, int tamanhoJanela = 8);
    double obterPesoEmKg() override;

private:
    FonteDePeso& _fonteBase;
    int _tamanhoJanela;
    double _janela[16];
    int _indice;
    int _preenchidos;
};
