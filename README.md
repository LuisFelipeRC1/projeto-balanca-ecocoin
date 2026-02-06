🌱 Ciclo Verde: Balança Inteligente com EcoCoins
O Ciclo Verde é uma solução tecnológica voltada para a sustentabilidade urbana. O projeto utiliza sistemas embarcados para incentivar a destinação correta de resíduos orgânicos em feiras e mercados, transformando descarte em benefício através da moeda social EcoCoins.

🎯 Objetivos do Projeto
Incentivo Sustentável: Promover a economia circular em ambientes comerciais.

Redução de Impacto: Diminuir o descarte incorreto de resíduos orgânicos.

Gamificação Ambiental: Converter peso de resíduos em EcoCoins, uma moeda de troca para benefícios futuros.

Arquitetura Modular: Sistema funcional e extensível para diferentes hardwares.

⚙️ Funcionamento do Sistema
O fluxo de operação foi desenhado para ser simples e eficiente:

Pesagem: Uma célula de carga realiza a leitura do resíduo orgânico.

Processamento: O sistema converte o peso bruto em valor de EcoCoins via software.

Comunicação: Os dados (Peso + EcoCoins) são transmitidos via Serial para monitoramento ou sistemas externos.

🏗️ Estrutura de Pastas
O projeto utiliza uma separação de preocupações (Clean Architecture principles), permitindo testar a lógica sem depender do hardware físico.

Plaintext
src/
├── core/               # Lógica de negócio e interfaces (Abstração)
│   ├── FonteDePeso.h
│   ├── ConversorEcoCoin.h
│   ├── CanalDeEnvio.h
│   └── SistemaEcoCoin.h
├── infra/              # Implementações de drivers e sensores (Hardware)
│   ├── FonteDePesoHX711.cpp
│   ├── ConversorEcoCoinSimples.cpp
│   └── CanalDeEnvioFake.cpp
└── main.cpp            # Orquestrador do sistema
🔌 Hardware e Dependências
Componentes Suportados
Microcontroladores: ESP32 ou Arduino Uno.

Sensor: Célula de Carga com amplificador HX711.

Comunicação: Serial (padrão) / Preparado para expansão Wi-Fi.

Bibliotecas Necessárias
O gerenciamento é feito via PlatformIO. A principal dependência é:

Ini, TOML
lib_deps =
  bogde/HX711
▶️ Como Executar
Setup: Instale o VS Code com a extensão PlatformIO.

Clonagem:

Bash
git clone https://github.com/seu-usuario/ciclo-verde.git
Configuração: Ajuste os pinos do HX711 no arquivo de configuração ou main.cpp conforme sua montagem.

Upload: Conecte sua placa e clique em PlatformIO: Upload.

Simulação: Caso não possua o sensor físico, utilize a classe FonteDePesoFake na main.cpp para validar a lógica.

🚀 Evoluções Futuras
[ ] Conectividade: Integração com Wi-Fi/HTTP para envio de dados à nuvem.

[ ] Dashboard: Interface web para visualização do total de resíduos coletados.

[ ] Identificação: Implementação de leitores RFID para identificar doadores.

[ ] Persistência: Uso de EEPROM ou banco de dados para histórico de EcoCoins.

📚 Considerações Finais
Este projeto nasceu da união entre tecnologia e consciência ecológica. A arquitetura modular garante que o Ciclo Verde possa crescer de um simples protótipo para uma rede conectada de pontos de coleta.
