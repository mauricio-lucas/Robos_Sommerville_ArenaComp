#ifndef MOTOR_H
#define MOTOR_H
// ============================================================
//  MÓDULO MOTOR — controle de 2 motores DC via ponte H
//  (driver tipo L298N / TB6612: 2 pinos de direção + 1 PWM)
//
//  Este módulo é igual no sumô e na rampa.
//  Corrigiu um bug aqui? Corrija na outra pasta também.
// ============================================================

#include <Arduino.h>

struct MotorPinos {
    int in1;   // direção
    int in2;   // direção
    int pwm;   // velocidade (pino ~)
};

// Guarda os pinos dos dois motores. Chamar UMA vez no setup().
void motor_iniciar(const MotorPinos& esquerdo, const MotorPinos& direito);

// vel: -255 (ré total) a 255 (frente total). 0 = parado.
void motor_esquerdo(int vel);
void motor_direito(int vel);

// Atalhos de manobra
void motor_frente(int vel);
void motor_tras(int vel);
void motor_girar_esquerda(int vel);  // esq. ré, dir. frente
void motor_girar_direita(int vel);   // esq. frente, dir. ré
void motor_parar(void);

#endif // MOTOR_H
