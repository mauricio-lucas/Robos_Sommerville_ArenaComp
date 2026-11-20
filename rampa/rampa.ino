// ============================================================
//  ROBÔ SOBE-RAMPA — gincana universitária
//  Estratégia: apertou start, espera 3s e segue a linha com
//  o sensor IR; na subida usa velocidade maior.
// ============================================================
#include "config.h"
#include "motor.h"

// ---- Estados do robô ----
enum Estado { AGUARDANDO_START, SEGUINDO };
Estado estado = AGUARDANDO_START;

// Lê o sensor IR e classifica: true = sobre a linha preta
bool sobreLinha(void) {
    int leitura = analogRead(PIN_IR_LINHA);
    return leitura > LINHA_PRETO_ACIMA_DE;
}

void setup() {
    Serial.begin(115200);

    MotorPinos esq = {PIN_MOTOR_A_IN1, PIN_MOTOR_A_IN2, PIN_MOTOR_A_PWM};
    MotorPinos dir = {PIN_MOTOR_B_IN1, PIN_MOTOR_B_IN2, PIN_MOTOR_B_PWM};
    motor_iniciar(esq, dir);

    pinMode(PIN_BOTAO_START, INPUT_PULLUP);
    pinMode(PIN_IR_LINHA, INPUT);

    Serial.println("Pronto. Aperte o botao de start.");
    Serial.println("(Use o Serial Monitor para calibrar o IR: ler analogRead)");
}

void loop() {
    switch (estado) {

    case AGUARDANDO_START:
        motor_parar();
        if (digitalRead(PIN_BOTAO_START) == LOW) {
            Serial.println("START! Saindo em 3s...");
            delay(DELAY_START_MS);
            estado = SEGUINDO;
        }
        break;

    case SEGUINDO: {
        if (sobreLinha()) {
            // linha no centro: reto com força de subida
            motor_frente(VEL_SUBIDA);
        } else {
            // perdeu a linha: curva suave à direita para reencontrar
            motor_direito(VEL_CORRECAO);
            motor_esquerdo(0);
        }
        break;
    }
    }

    delay(TEMPO_LOOP_MS);
}
