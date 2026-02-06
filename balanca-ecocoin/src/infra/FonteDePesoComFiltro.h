#include "../core/FonteDePeso.h"
#pragma once

class FonteDePesoComFiltro : public FonteDePeso
{
    public:
        explicit FonteDePesoComFiltro(double pesoFixo);

        double obterPesoEmKg() override;
    private:
        double pesoFixo;

};
