#ifndef CONFIG_H
#define CONFIG_H
// ============================================================
//  CONFIG — Robô SOBE-RAMPA
//  Todos os pinos e constantes de ajuste ficam AQUI.
//  Mudou a ligação na protoboard? Mude só este arquivo.
// ============================================================

// ---------- PONTES H / MOTORES (Driver tipo L298N/TB6612) ----------
// Motor A = esquerdo | Motor B = direito
const int PIN_MOTOR_A_IN1 = 5;
const int PIN_MOTOR_A_IN2 = 6;
const int PIN_MOTOR_B_IN1 = 9;
const int PIN_MOTOR_B_IN2 = 10;
const int PIN_MOTOR_A_PWM = 3;    // precisa ser ~
const int PIN_MOTOR_B_PWM = 11;   // precisa ser ~

// ---------- SENSOR IR DE LINHA (TCRT5000, saída analógica) ----------
const int PIN_IR_LINHA = A0;

// Calibração da linha — medir com teste C da bancada e ajustar:
// faça o Serial imprimir o valor sobre a linha preta e sobre o branco.
const int LINHA_PRETO_ACIMA_DE = 500;   // leitura ADC acima = preto
// Se sua fita reflete ao contrário, inverta a lógica em rampa.ino.

// ---------- VELOCIDADES (0–255) ----------
const int VEL_RETA        = 180;  // andando reto na rampa
const int VEL_CORRECAO    = 120;  // roda interna ao fazer curva suave
const int VEL_SUBIDA      = 220;  // rampa inclinada pede mais força

// ---------- START ----------
const int PIN_BOTAO_START = 12;
const unsigned long DELAY_START_MS = 3000;

// ---------- UTIL ----------
const unsigned long TEMPO_LOOP_MS = 10;

#endif // CONFIG_H
