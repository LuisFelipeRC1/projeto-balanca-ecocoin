#include <unity.h>

#include "core/SistemaEcoCoin.h"
#include "infra/ConversorEcoCoinSimples.h"
#include "infra/FonteDePesoComFiltro.h"
#include "infra/FonteDePesoFake.h"

void setUp(void)
{
}

void tearDown(void)
{
}

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
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 0.0, conv.converter(-1.0));
}

void test_conversor_taxa_negativa()
{
    ConversorEcoCoinSimples conv(-2.0);
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 0.0, conv.converter(2.5));
}

class FonteSequencialFake : public FonteDePeso
{
public:
    explicit FonteSequencialFake(const double* leituras, int tamanho)
        : _leituras(leituras), _tamanho(tamanho), _indice(0)
    {
    }

    double obterPesoEmKg() override
    {
        if (_indice < _tamanho)
        {
            return _leituras[_indice++];
        }
        return _leituras[_tamanho - 1];
    }

private:
    const double* _leituras;
    int _tamanho;
    int _indice;
};

void test_fonte_com_filtro_media_movel()
{
    const double leituras[] = {1.0, 2.0, 3.0, 4.0};
    FonteSequencialFake fonteBase(leituras, 4);
    FonteDePesoComFiltro fonteFiltrada(fonteBase, 4);

    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 1.0, fonteFiltrada.obterPesoEmKg());
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 1.5, fonteFiltrada.obterPesoEmKg());
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 2.0, fonteFiltrada.obterPesoEmKg());
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 2.5, fonteFiltrada.obterPesoEmKg());
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
    RUN_TEST(test_conversor_taxa_negativa);
    RUN_TEST(test_fonte_com_filtro_media_movel);
    RUN_TEST(test_sistema_fluxo_basico);
    return UNITY_END();
}
