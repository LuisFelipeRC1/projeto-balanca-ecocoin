#include "ConversorEcoCoinSimples.h"

ConversorEcoCoinSimples::ConversorEcoCoinSimples(double taxa)
    : _taxa(taxa)
{
}

double ConversorEcoCoinSimples::converter(double pesoEmKg)
{
    return pesoEmKg * _taxa;
}
