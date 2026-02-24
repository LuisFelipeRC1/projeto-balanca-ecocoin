#include "FonteDePesoHX711.h"

FonteDePesoHX711::FonteDePesoHX711(
    int pinDout,
    int pinSck,
    float fatorCalibracao,
    int tamanhoJanela)
    : _pinDout(pinDout),
      _pinSck(pinSck),
      _fatorCalibracao(fatorCalibracao),
      _tamanhoJanela(tamanhoJanela > 0 && tamanhoJanela <= 16 ? tamanhoJanela : 8),
      _indice(0),
      _preenchidos(0),
      _ultimoPesoKg(0.0),
      _inicializado(false)
{
    for (int i = 0; i < 16; ++i)
    {
        _janela[i] = 0.0f;
    }
}

void FonteDePesoHX711::inicializar()
{
    if (_inicializado)
    {
        return;
    }

    _hx711.begin(_pinDout, _pinSck);
    _hx711.set_scale(_fatorCalibracao);
    _hx711.tare();
    _inicializado = true;
}

double FonteDePesoHX711::obterPesoEmKg()
{
    if (!_inicializado)
    {
        inicializar();
    }

    if (!_hx711.is_ready())
    {
        // Keep last stable value when sensor is unavailable.
        return _ultimoPesoKg;
    }

    // HX711 get_units usually returns grams.
    float pesoEmGramas = _hx711.get_units(5);

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
    const float mediaGramas = soma / _preenchidos;

    _ultimoPesoKg = mediaGramas / 1000.0;
    return _ultimoPesoKg;
}
