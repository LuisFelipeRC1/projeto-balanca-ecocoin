#include "FonteDePesoComFiltro.h"

FonteDePesoComFiltro::FonteDePesoComFiltro(double pesoFixo)
    : pesoFixo(pesoFixo)
{

}
double FonteDePesoComFiltro::obterPesoEmKg()
{
    if (pesoFixo < 0) {
        return 0.0;
    }
    return pesoFixo;
    
}