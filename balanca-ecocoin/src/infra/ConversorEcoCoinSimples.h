#pragma once

#include "../core/ConversorEcoCoin.h"

class ConversorEcoCoinSimples : public ConversorEcoCoin
{
public:
    explicit ConversorEcoCoinSimples(double taxa);

    double converter(double pesoEmKg) override;

private:
    double _taxa;
};
