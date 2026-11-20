// ============================================================
//  MÓDULO SENSORES — implementação
//  Usa bibliotecas C++ da Adafruit (por isso é .cpp e não .c):
//  - Adafruit TCA9548A : multiplexador I2C
//  - Adafruit VL53L0X  : sensor laser
// ============================================================
#include "sensores.h"
#include "config.h"

#include <Wire.h>
#include <Adafruit_TCA9548A.h>
#include <Adafruit_VL53L0X.h>

Adafruit_TCA9548A mux(ENDERECO_MUX);
Adafruit_VL53L0X laser_frente;

bool sensores_iniciar(void) {
    pinMode(PIN_BORDA_TRIG, OUTPUT);
    pinMode(PIN_BORDA_ECHO, INPUT);

    if (!mux.begin()) return false;

    // Coloca o laser isolado no canal 0 do mux e inicia
    mux.selectChannel(CANAL_LASER_FRENTE);
    if (!laser_frente.begin(0x29)) return false;
    laser_frente.startRangeContinuous();

    return true;
}

int16_t sensores_ler_oponente_mm(void) {
    // garante que estamos falando com o canal certo
    mux.selectChannel(CANAL_LASER_FRENTE);

    VL53L0X_RangingMeasurementData_t medicao;
    laser_frente.rangingTest(&medicao, false);

    if (medicao.RangeStatus != 4) {       // 4 = leitura inválida
        return (int16_t)medicao.RangeMilliMeter;
    }
    return -1;                            // falhou
}

unsigned long sensores_ler_borda_cm(void) {
    // média de 3 leituras para filtrar ruído dos motores
    unsigned long soma = 0;
    for (int i = 0; i < 3; i++) {
        digitalWrite(PIN_BORDA_TRIG, LOW);  delayMicroseconds(2);
        digitalWrite(PIN_BORDA_TRIG, HIGH); delayMicroseconds(10);
        digitalWrite(PIN_BORDA_TRIG, LOW);
        unsigned long dur = pulseIn(PIN_BORDA_ECHO, HIGH, 25000UL);
        soma += dur * 0.0343 / 2.0;       // converte para cm
        delay(5);
    }
    return soma / 3;
}

bool sensores_borda_detectada(void) {
    unsigned long cm = sensores_ler_borda_cm();
    // Fora da faixa = o chão sob o sensor mudou = borda/queda
    return (cm < BORDA_MIN_CM || cm > BORDA_MAX_CM);
}
