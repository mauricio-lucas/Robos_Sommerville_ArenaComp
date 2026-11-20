# Esquema Elétrico — Robô SOBE-RAMPA

> **Status:** aguardando print do Tinkercad (Responsável: Pessoa 1)
> Exportar do Tinkercad Circuits como imagem e salvar aqui como `esquema-rampa.png`.

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

   Uno A0 ──> AO (saída analógica) do TCRT5000
   5V/GND ──> VCC/GND do TCRT5000

   Uno D12 ──> Botão start (outro lado no GND, INPUT_PULLUP)
```

## Regras de segurança

1. **Ground comum:** GND das pilhas + GND do Uno + GND do sensor no mesmo barramento.
2. Roda boba fixada na frente, tocando o chão (estabilidade na subida).
3. Sensor IR a ~5–10 mm do chão, na frente do robô, para ler a linha.
