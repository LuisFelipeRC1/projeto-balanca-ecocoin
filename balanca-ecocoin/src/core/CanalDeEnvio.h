#pragma once

class CanalDeEnvio
{
public:
    virtual ~CanalDeEnvio() = default;
    // "=0" siginifica que o método é virtual puro e deve ser implementado pelas classes derivadas
    virtual void enviar(double pesoEmKg, double ecoCoins) = 0;
};
