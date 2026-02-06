#include <unity.h>

#include "core/SistemaEcoCoin.h"
#include "infra/ConversorEcoCoinSimples.h"
#include "infra/FonteDePesoFake.h"

class CanalDeEnvioMemoria : public CanalDeEnvio
{
public:
    void enviar(double pesoEmKg, double ecoCoins) override
    {
        ultimoPeso = pesoEmKg;
        ultimoEco = ecoCoins;
        chamadas++;
    }

    double ultimoPeso{0};
    double ultimoEco{0};
    int chamadas{0};
};

void test_conversor_simples()
{
    ConversorEcoCoinSimples conv(2.0);
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 3.0, conv.converter(1.5));
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 0.0, conv.converter(0.0));
}

void test_sistema_fluxo_basico()
{
    FonteDePesoFake fonte(1.2);
    ConversorEcoCoinSimples conv(2.0);
    CanalDeEnvioMemoria canal;
    SistemaEcoCoin sistema(fonte, conv, canal);

    sistema.executarCiclo();

    TEST_ASSERT_EQUAL(1, canal.chamadas);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, 1.2, canal.ultimoPeso);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, 2.4, canal.ultimoEco);
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_conversor_simples);
    RUN_TEST(test_sistema_fluxo_basico);
    return UNITY_END();
}
