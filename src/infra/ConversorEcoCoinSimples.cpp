#include "ConversorEcoCoinSimples.h"

ConversorEcoCoinSimples::ConversorEcoCoinSimples(double taxa)
    : _taxa(taxa)
{
}

double ConversorEcoCoinSimples::converter(double pesoEmKg)
{
    if (pesoEmKg <= 0.0 || _taxa <= 0.0)
    {
        return 0.0;
    }

    return pesoEmKg * _taxa;
}
