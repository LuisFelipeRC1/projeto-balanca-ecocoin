#pragma once


class ConversorEcoCoin {
    public:
        virtual ~ConversorEcoCoin() = default;
    
    virtual double converter(double pesoEmKg) = 0;
};