#include <Arduino.h>

#include "core/SistemaEcoCoin.h"

#include "infra/FonteDePesoHX711.h"
#include "infra/ConversorEcoCoinSimples.h"
#include "infra/CanalDeEnvioFake.h"
#include "infra/CanalDeEnvioHttpSimulado.h"

constexpr int PIN_HX711_DOUT = 4;
constexpr int PIN_HX711_SCK  = 5;
constexpr float FATOR_CALIBRACAO = 2280.0f;
constexpr double TAXA_ECOCOIN = 2.0;
constexpr unsigned long INTERVALO_LEITURA_MS = 1000;
constexpr int TAMANHO_JANELA_FILTRO = 8;
constexpr const char* ENDPOINT_SIMULADO = "https://localhost/api/eco";

FonteDePesoHX711 fontePeso(PIN_HX711_DOUT, PIN_HX711_SCK, FATOR_CALIBRACAO, TAMANHO_JANELA_FILTRO);
ConversorEcoCoinSimples conversor(TAXA_ECOCOIN);
// Troque para CanalDeEnvioFake se quiser somente serial simples
CanalDeEnvioHttpSimulado canalHttp(ENDPOINT_SIMULADO);
SistemaEcoCoin sistema(fontePeso, conversor, canalHttp);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    sistema.executarCiclo();
    delay(INTERVALO_LEITURA_MS);
}
