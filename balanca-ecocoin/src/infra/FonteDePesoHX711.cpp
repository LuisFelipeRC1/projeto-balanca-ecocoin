#include "FonteDePesoHX711.h"

FonteDePesoHX711::FonteDePesoHX711(
    int pinDout,
    int pinSck,
    float fatorCalibracao,
    int tamanhoJanela)
    : _fatorCalibracao(fatorCalibracao),
      _tamanhoJanela(tamanhoJanela > 0 && tamanhoJanela <= 16 ? tamanhoJanela : 8),
      _indice(0),
      _preenchidos(0),
      _ultimoPesoKg(0.0)
{
    _hx711.begin(pinDout, pinSck);
    _hx711.set_scale(_fatorCalibracao);
    _hx711.tare();
    for (int i = 0; i < 16; ++i)
    {
        _janela[i] = 0.0f;
    }
}

double FonteDePesoHX711::obterPesoEmKg()
{
    if (!_hx711.is_ready())
    {
        return _ultimoPesoKg; // mantém último valor válido
    }

    // HX711 normalmente retorna em gramas
    float pesoEmGramas = _hx711.get_units(5);

    // descarta leituras negativas
    if (pesoEmGramas < 0)
    {
        pesoEmGramas = 0;
    }

    _janela[_indice] = pesoEmGramas;
    _indice = (_indice + 1) % _tamanhoJanela;
    if (_preenchidos < _tamanhoJanela)
    {
        _preenchidos++;
    }

    float soma = 0.0f;
    for (int i = 0; i < _preenchidos; ++i)
    {
        soma += _janela[i];
    }
    float mediaGramas = soma / _preenchidos;

    // converte para kg
    _ultimoPesoKg = mediaGramas / 1000.0;
    return _ultimoPesoKg;
}
