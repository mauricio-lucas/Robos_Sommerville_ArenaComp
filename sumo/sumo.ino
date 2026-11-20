// ============================================================
//  ROBÔ SUMÔ — gincana universitária
//  Estratégia: girar no lugar procurando o oponente; quando o
//  laser vê algo perto, carga frontal; se a borda é detectada,
//  recua e vira para não cair.
// ============================================================
#include "config.h"
#include "motor.h"
#include "sensores.h"

// ---- Estados do robô (máquina simples de estados) ----
enum Estado { AGUARDANDO_START, PROCURANDO, ATACANDO, FUGINDO_BORDA };
Estado estado = AGUARDANDO_START;

void setup() {
    Serial.begin(115200);

    MotorPinos esq = {PIN_MOTOR_A_IN1, PIN_MOTOR_A_IN2, PIN_MOTOR_A_PWM};
    MotorPinos dir = {PIN_MOTOR_B_IN1, PIN_MOTOR_B_IN2, PIN_MOTOR_B_PWM};
    motor_iniciar(esq, dir);

    pinMode(PIN_BOTAO_START, INPUT_PULLUP);

    Serial.print("Iniciando sensores... ");
    if (sensores_iniciar()) {
        Serial.println("OK");
    } else {
        // Sem sensor não tem luta: fica travado piscando o LED onboard
        Serial.println("FALHOU — travando aqui");
        while (true) {
            digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
            delay(200);
        }
    }
    Serial.println("Pronto. Aperte o botao de start.");
}

void loop() {
    switch (estado) {

    case AGUARDANDO_START:
        motor_parar();
        if (digitalRead(PIN_BOTAO_START) == LOW) {
            Serial.println("START! Luta em 5s...");
            delay(DELAY_START_MS);
            estado = PROCURANDO;
        }
        break;

    case PROCURANDO: {
        int16_t dist = sensores_ler_oponente_mm();

        if (sensores_borda_detectada()) {
            estado = FUGINDO_BORDA;
        } else if (dist > 0 && dist < DIST_ATAQUE_MM) {
            estado = ATACANDO;
        } else if (dist > 0 && dist < DIST_OPPONENTE_MM) {
            // viu o oponente longe: avança devagar em direção a ele
            motor_frente(VEL_BUSCA);
        } else {
            // nada visto: gira no lugar procurando
            motor_girar_direita(VEL_BUSCA);
        }
        break;
    }

    case ATACANDO: {
        if (sensores_borda_detectada()) {
            estado = FUGINDO_BORDA;
        } else {
            int16_t dist = sensores_ler_oponente_mm();
            if (dist > 0 && dist < DIST_ATAQUE_MM + 100) {
                motor_frente(VEL_ATAQUE);   // carga!
            } else {
                estado = PROCURANDO;        // oponente escapou
            }
        }
        break;
    }

    case FUGINDO_BORDA:
        // recua um pouco e vira para dentro da arena
        motor_tras(VEL_RECUO);
        delay(250);
        motor_girar_esquerda(VEL_RECUO);
        delay(350);
        motor_parar();
        estado = PROCURANDO;
        break;
    }

    delay(TEMPO_LOOP_MS);
}
