# Tabela de Pinos — Fonte da Verdade

> **Regra:** o que está aqui deve bater com o `config.h` de cada robô.
> Mudou na protoboard? Atualize aqui **e** no `config.h` na mesma hora.

## Comum aos dois robôs (motores via ponte H)

| Sinal | Pino Uno | Função |
|---|---|---|
| AIN1 | D5 | Motor esquerdo — direção |
| AIN2 | D6 | Motor esquerdo — direção |
| PWMA | D3 (PWM ~) | Motor esquerdo — velocidade |
| BIN1 | D9 | Motor direito — direção |
| BIN2 | D10 | Motor direito — direção |
| PWMB | D11 (PWM ~) | Motor direito — velocidade |
| BOTÃO START | D12 (INPUT_PULLUP) | Iniciar a prova |

## Alimentação

| Linha | Origem | Vai para |
|---|---|---|
| 9V (6×AA) | Suporte de pilhas → chave | VIN/12V da ponte H |
| 5V | Saída 5V da ponte H | Pino 5V do Uno (alimentação da lógica) |
| GND | Comum | GND da ponte H + GND do Uno (obrigatório juntar!) |
| 5V power bank | USB | Sensores (se precisar isolar da ponte H) |

⚠️ **Nunca** ligue motores na saída 5V da ponte H junto com o Uno — ruído derruba o Uno. A saída 5V do L298N aguenta só a lógica.

## Sumô (extras)

| Sinal | Pino Uno | Função |
|---|---|---|
| SDA | A4 | Barramento I2C → TCA9548A |
| SCL | A5 | Barramento I2C → TCA9548A |
| TCA9548A CH0 | (no mux) | VL53L0X oponente |
| TCA9548A CH1 | (no mux) | VL53L0X reserva |
| BORDA TRIG | D2 | HC-SR04 apontado para baixo |
| BORDA ECHO | D7 | HC-SR04 apontado para baixo |

## Rampa (extras)

| Sinal | Pino Uno | Função |
|---|---|---|
| IR LINHA (AO) | A0 | TCRT5000 — saída analógica |
