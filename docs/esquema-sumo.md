# Esquema Elétrico — Robô SUMÔ

> **Status:** aguardando print do Tinkercad (Responsável: Pessoa 1)
> Exportar do Tinkercad Circuits como imagem e salvar aqui como `esquema-sumo.png`.

## Lista de conexões (resumo)

```
                          ┌──────────────────┐
   6×AA (9V) ── chave ──> │ VIN        5V   ├────> Pino 5V do Uno
   GND pilhas ──────────> │ GND        GND  ├────> GND do Uno (JUNTAR!)
                          │  L298N          │
                          │ IN1 IN2 ENA     ├──> D5, D6, D3(PWM)
                          │ IN3 IN4 ENB     ├──> D9, D10, D11(PWM)
                          │ OUT1/2          ├──> Motor esquerdo
                          │ OUT3/4          ├──> Motor direito
                          └──────────────────┘

   Uno A4 (SDA) ──────> SDA do TCA9548A
   Uno A5 (SCL) ──────> SCL do TCA9548A
   TCA9548A CH0 ──────> VL53L0X (oponente)  [Vin, GND, SDA, SCL]
   TCA9548A CH1 ──────> VL53L0X (reserva)   [opcional]
   TCA9548A VCC/GND ──> 5V/GND do Uno

   Uno D2  ──> TRIG do HC-SR04 (borda, apontado p/ baixo)
   Uno D7  ──> ECHO do HC-SR04 (borda)
   5V/GND  ──> VCC/GND do HC-SR04

   Uno D12 ──> Botão start (outro lado no GND, INPUT_PULLUP)
```

## Regras de segurança

1. **Ground comum:** GND das pilhas + GND do Uno + GND dos sensores no mesmo barramento.
2. Power bank alimenta **apenas** sensores se houver ruído; motores nunca na power bank.
3. Ligar a bateria SÓ depois de conferir a polaridade na ponte H.
