# 🌱 Projeto Ciclo Verde — Balança Inteligente com EcoCoins

## 📌 Descrição do Projeto

O **Projeto Ciclo Verde** tem como objetivo incentivar a destinação correta de resíduos orgânicos em feiras e mercados por meio de um sistema de recompensas chamado **EcoCoins**.

A solução consiste em uma **balança inteligente**, capaz de:

- Medir o peso de resíduos orgânicos doados;
- Converter esse peso em EcoCoins;
- Enviar essas informações para um sistema externo de controle.

Cada quilograma de resíduo doado gera uma quantidade proporcional de EcoCoins, que podem ser utilizados em ações futuras definidas pelo projeto (benefícios, descontos, programas ambientais, etc.).

---

## 🎯 Objetivo

- Incentivar práticas sustentáveis;
- Reduzir o descarte inadequado de resíduos orgânicos;
- Promover educação ambiental por meio de recompensas;
- Desenvolver um sistema embarcado funcional e modular.

---

## ⚙️ Funcionamento do Sistema

O funcionamento do sistema ocorre em ciclos simples:

1. O sistema realiza a leitura do peso do resíduo orgânico utilizando uma célula de carga;
2. O valor obtido é convertido em EcoCoins, com base em uma taxa de conversão definida;
3. O peso e o valor de EcoCoins gerados são enviados para um sistema externo  
   (ex.: exibição no console, serial, ou outro meio de comunicação).

Esse fluxo pode ser executado repetidamente sempre que uma nova doação for realizada.

---

## 🧱 Estrutura do Projeto

```text
src/
├── core/
│   ├── FonteDePeso.h
│   ├── ConversorEcoCoin.h
│   ├── CanalDeEnvio.h
│   └── SistemaEcoCoin.h / .cpp
│
├── infra/
│   ├── FonteDePesoFake.*
│   ├── FonteDePesoHX711.*
│   ├── ConversorEcoCoinSimples.*
│   └── CanalDeEnvioFake.*
│
└── main.cpp
```

---

## 🔌 Hardware Utilizado

1. Placa: ESP32 ou Arduino Uno
2. Sensor de peso: HX711 + célula de carga
3. Comunicação: Serial (no estágio atual)

---

## ▶️ Como Executar

1. Abra o projeto no PlatformIO (VS Code);
2. Conecte a placa (ESP32 ou Arduino);
3. Verifique os pinos configurados para o HX711;
4. Compile e envie o código para a placa;
5.Acompanhe a saída pelo monitor serial (ou console, no modo fake).7

---

## 🧪 Testes Sem Hardware

O projeto permite execução sem hardware real utilizando implementações simuladas (Fake), o que facilita testes e validação do funcionamento do sistema antes da integração física.

---

📚 Considerações Finais

Este projeto demonstra uma solução prática e funcional para incentivar a sustentabilidade por meio de tecnologia embarcada, permitindo fácil adaptação e expansão conforme novas necessidades do Projeto Ciclo Verde.




