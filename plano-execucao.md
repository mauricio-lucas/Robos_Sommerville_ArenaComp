# Plano de Execução — Robôs Sumô + Sobe-rampa (Gincana Universitária)

**Prazo:** 2 semanas · **Time:** 3–4 pessoas (iniciantes) · **Ferramenta de esquema:** Tinkercad Circuits
**Filosofia:** módulos simples, redundância permitida, pinos em constantes nomeadas no topo, ambos os robôs 100% autônomos.

---

## 1. Visão geral dos robôs

| | Robô Sumô | Robô Sobe-rampa |
|---|---|---|
| Função | Encontrar o oponente e empurrá-lo para fora; não cair da borda | Subir a rampa seguindo linha / trajeto |
| Sensores | 1× VL53L0X frontal (oponente, I2C via TCA9548A) + 1× HC-SR04 para baixo (borda) | 1× sensor IR TCRT5000 (linha) |
| Atuação | 2 motores DC com rodas + ponte H | 2 motores DC com rodas + ponte H |
| Controle | Arduino Uno | Arduino Uno |
| Alimentação | 6×AA (9V) p/ motores via ponte H; power bank 5V p/ lógica | idem |

## 2. Inventário atual (já temos)

- 2+ Arduino Uno (1 por robô + 1 backup/testes)
- Rodas ✔ · Pilhas AA ✔ · Kit de montagem ✔ · Lâmina/cantoneira ✔
- ~5× HC-SR04 (1 fica para detectar borda no sumô)
- 1× sensor infravermelho (TCRT5000 ou similar)
- 2× ponte H (L298N ou similar — confirmar modelo!)
- 1× power bank 5V 3A · 1× power bank 5V 2A
- 3× pilhas recarregáveis 2,4V · 1× pilha 3,7V
- Motores DC "pelados" (reserva)
- 1× ESP8266 (reserva) · 1× TCA9548A (multiplexador I2C, 8 canais)

### Já em encomenda (aguardando chegada)
- 2× VL53L0X (distância ToF, I2C) — sumô (principal) + reserva/teste
- 1× roda boba — estabilidade frontal da rampa
- 1× suporte 6× pilhas AA (9V) — alimentação dos motores via ponte H

## 3. Lista de compras (restante) — ORÇAMENTO

| # | Item | Qtd | Preço unit. (R$) | Subtotal |
|---|---|---|---|---|
| 1 | Kit motor TT 3–6V 200RPM + roda 68mm emborrachada *(só se as rodas atuais não forem compatíveis c/ eixo TT 5,4mm)* | 4 | 14,00 | 56,00 |
| 2 | Sensor IR TCRT5000 (seguidor de linha) | 2 | 8,00 | 16,00 |
| 3 | Pilhas AA recarregáveis extras | 8 | 8,00 | 64,00 |
| 4 | Jumpers/fios/chaves avulsos | 1 kit | 25,00 | 25,00 |
| | **TOTAL ESTIMADO** | | | **≈ R$ 161,00** |

**Reserva de contingência: +20% → orçar R$ 200,00** (ou ~R$ 105 se as rodas forem compatíveis com motor TT).
Fazer UM pedido único em uma loja (Casa da Robótica / Usinainfo / Saravati / Bit Maker) para pagar 1 frete.

### O que NÃO comprar
- Segunda ponte H (temos 2; L298N serve — só perde ~2V, compensável com 9V)
- Controladora melhor, Wi-Fi etc. — fora de escopo em 2 semanas

### Impressão 3D (carcaça)
- Modelos gratuitos: Thingiverse ("mini sumo chassis"), Printables (sumo 1kg 15×15; line follower chassis)
- Material: PETG p/ sumô, PLA serve p/ rampa; preenchimento 40–60%
- Enviar STL para impressão até o **dia 3** no máximo

## 4. Tabela de pinos (base — ajustar na montagem)

| Sinal | Uno | Função |
|---|---|---|
| PWMA / PWMB | D3 / D11 | PWM motores (pontes H) |
| AIN1/AIN2, BIN1/BIN2 | D5, D6, D9, D10 | Direção |
| SDA / SCL (TCA9548A) | A4 / A5 | Barramento I2C principal |
| TCA9548A CH0 | — | VL53L0X oponente (endereço 0x29 isolado no canal) |
| TCA9548A CH1 | — | VL53L0X reserva/2º sensor |
| TRIG / ECHO (HC-SR04 borda) | D2 / D7 | Sumô: detectar borda da arena |
| Sensor IR (saída analógica) | A0 | Rampa: linha |
| Pino livre | D8, D12, A1–A3 | Botão de start, LEDs etc. |

**Nota (TCA9548A):** cada VL53L0X fica isolado no seu canal (endereço fixo 0x29 — sem o mux haveria conflito). Sem pino XSHUT; para trocar de sensor basta selecionar o canal no firmware (`Adafruit TCA9548A` + `Adafruit_VL53L0X`).

## 5. Cronograma (14 dias)

**Semana 1 — comprar, testar, programar**
- **D1–D2:** pedido único dos materiais (⚠️ dia 1, inegociável); escolher os 2 STLs; esquemas no Tinkercad; definir responsáveis.
- **D3–D5:** testes em bancada enquanto o material chega (usar Uno de reserva):
  - Teste A: Uno + ponte H + 1 motor girando nos 2 sentidos e com PWM
  - Teste B: Uno + HC-SR04 lendo distância (Serial Monitor)
  - Teste C: Uno + TCRT5000 detectando linha preta/branca
- **D6–D7:** firmware básico dos dois robôs (movimentação + lógica simples).

**Semana 2 — montar, calibrar, ensaiar**
- **D8–D9:** integração mecânica: carcaça, motores/rodas, sensores, organização dos fios.
- **D10–D11:** calibração em condições reais (arena de sumô / rampa real).
- **D12–D13:** ensaio geral + ajustes finos + kit de reparo.
- **D14:** margem para imprevistos.

## 6. Divisão da equipe (3–4 pessoas)
- **Pessoa 1 — Eletrônica/esquemas:** Tinkercad, solda, alimentação, testes de bancada.
- **Pessoa 2 — Firmware sumô:** lógica de busca/ataque/borda.
- **Pessoa 3 — Firmware rampa:** seguidor de linha + calibração.
- **Pessoa 4 (ou todos) — Mecânica/impressão + documentação:** STLs, montagem, fotos, `docs/`.

## 7. Riscos e planos B

| Risco | Mitigação |
|---|---|
| Material atrasar | Verificar pronta-entrega; plano C: rodas improvisadas p/ testar firmware |
| Rodas atuais incompatíveis com eixo de motor TT | Conferir furo 5,4mm c/ rebaixos ANTES de pedir; se incompatível, pedir kit motor+roda |
| L298N derruba tensão (motores fracos) | 9V (6×AA) na ponte H compensa; se insuficiente, TB6612 custa ~R$ 15 |
| HC-SR04 com ruído perto de motores | Filtrar leituras (média de 3) e montar afastado dos motores |
| VL53L0X não chega / falha | Plano B: usar HC-SR04 como sensor de oponente |
| Power bank desligando (corrente) | Power bank SÓ na lógica; motores sempre nas pilhas AA |
| I2C do VL53L0X conflita com pinos da ponte H | I2C é fixo em A4/A5 no Uno — reservar esses pinos desde o início |
| Conflito de endereço entre VL53L0X | Resolvido: TCA9548A isola cada sensor num canal próprio |

## 8. Checklist para o dia da gincana
- [ ] Robôs carregados na noite anterior
- [ ] Cabo USB de cada Uno + notebook com IDE e códigos finais
- [ ] Kit de reparo (jumpers, sensor reserva, fita, chave, parafusos)
- [ ] Cópia dos códigos no Google Drive/pendrive
- [ ] Documentação `docs/` pronta (se a gincana avaliar relatório)
