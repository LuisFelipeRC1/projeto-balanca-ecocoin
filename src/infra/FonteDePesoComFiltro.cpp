#include "FonteDePesoComFiltro.h"

FonteDePesoComFiltro::FonteDePesoComFiltro(FonteDePeso& fonteBase, int tamanhoJanela)
    : _fonteBase(fonteBase),
      _tamanhoJanela(tamanhoJanela > 0 && tamanhoJanela <= 16 ? tamanhoJanela : 8),
      _indice(0),
      _preenchidos(0)
{
    for (int i = 0; i < 16; ++i)
    {
        _janela[i] = 0.0;
    }
}

double FonteDePesoComFiltro::obterPesoEmKg()
{
    double peso = _fonteBase.obterPesoEmKg();
    if (peso < 0.0)
    {
        peso = 0.0;
    }

    _janela[_indice] = peso;
    _indice = (_indice + 1) % _tamanhoJanela;
    if (_preenchidos < _tamanhoJanela)
    {
        _preenchidos++;
    }

    double soma = 0.0;
    for (int i = 0; i < _preenchidos; ++i)
    {
        soma += _janela[i];
    }
    return soma / _preenchidos;
}
