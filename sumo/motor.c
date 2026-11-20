// ============================================================
//  MÓDULO MOTOR — implementação
// ============================================================
#include "motor.h"

static MotorPinos _esq = {0, 0, 0};
static MotorPinos _dir = {0, 0, 0};

static void _ligarMotor(const MotorPinos& m, int vel) {
    // limita ao intervalo [-255, 255]
    if (vel >  255) vel =  255;
    if (vel < -255) vel = -255;

    if (vel > 0) {              // frente
        digitalWrite(m.in1, HIGH);
        digitalWrite(m.in2, LOW);
    } else if (vel < 0) {       // ré
        digitalWrite(m.in1, LOW);
        digitalWrite(m.in2, HIGH);
        vel = -vel;
    } else {                    // parado (freio)
        digitalWrite(m.in1, LOW);
        digitalWrite(m.in2, LOW);
    }
    analogWrite(m.pwm, vel);
}

void motor_iniciar(const MotorPinos& esquerdo, const MotorPinos& direito) {
    _esq = esquerdo;
    _dir = direito;

    pinMode(_esq.in1, OUTPUT);
    pinMode(_esq.in2, OUTPUT);
    pinMode(_esq.pwm, OUTPUT);
    pinMode(_dir.in1, OUTPUT);
    pinMode(_dir.in2, OUTPUT);
    pinMode(_dir.pwm, OUTPUT);
    motor_parar();
}

void motor_esquerdo(int vel) { _ligarMotor(_esq, vel); }
void motor_direito(int vel)  { _ligarMotor(_dir, vel); }

void motor_frente(int vel) { motor_esquerdo(vel);  motor_direito(vel); }
void motor_tras(int vel)   { motor_esquerdo(-vel); motor_direito(-vel); }
void motor_girar_esquerda(int vel) { motor_esquerdo(-vel); motor_direito(vel); }
void motor_girar_direita(int vel)  { motor_esquerdo(vel);  motor_direito(-vel); }
void motor_parar(void)     { motor_esquerdo(0); motor_direito(0); }
