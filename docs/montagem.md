# Passo a passo de Montagem

> Fotos de cada etapa vão para `docs/fotos/`. Responsável: Pessoa 4.

## 1. Bancada (antes da carcaça)
1. Ponte H na protoboard/placa: conferir jumper de enable (se L298N, os jumpers ENA/ENB devem ser **removidos** para usar PWM nos pinos D3/D11).
2. Ligar 1 motor na OUT1/2, carregar `rampa.ino` no Uno de reserva e testar frente/ré/velocidade.
3. Testar HC-SR04 e TCRT5000 com o Serial Monitor (valores em `config.h`).

## 2. Mecânica
1. Fixar motores na carcaça (impressão 3D ou estrutura com cantoneira).
2. Encaixar rodas nos eixos dos motores TT (furo 5,4mm com rebaixos).
3. Rampa: fixar roda boba na frente; Sumô: fixar lâmina/cantoneira frontal baixa.
4. Fixar Uno + ponte H com fita dupla-face/parafusos.

## 3. Sensores
- **Sumô:** VL53L0X na frente, na horizontal, na altura do oponente. HC-SR04 de borda apontado para baixo, na lateral frontal.
- **Rampa:** TCRT5000 na frente, 5–10 mm do chão.

## 4. Fiação e alimentação
1. Seguir `tabela-pinos.md` linha por linha.
2. Fios dos motores torcidos (reduz ruído no sensor).
3. Roteamento: fios de sinal longe dos fios de motor.
4. Conferir GND comum antes de ligar qualquer coisa.

## 5. Teste final de cada robô
- [ ] Sobe com botão de start e para sem comandos
- [ ] Sumô: reage a mão na frente do laser; reage à mudança de chão (borda)
- [ ] Rampa: segue linha reta; faz a curva de correção
- [ ] Nada esquentando anormalmente em 1 min de operação
