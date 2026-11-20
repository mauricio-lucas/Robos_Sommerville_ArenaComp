#ifndef SENSORES_H
#define SENSORES_H
// ============================================================
//  MÓDULO SENSORES — Robô SUMÔ
//  - VL53L0X (laser, oponente) acessado pelo TCA9548A
//  - HC-SR04 (borda da arena) apontado para baixo
// ============================================================

#include <Arduino.h>

// Inicializa mux + laser + ultrassom da borda. true = tudo ok.
bool sensores_iniciar(void);

// Distância do oponente em mm. Retorna -1 se leitura falhar.
int16_t sensores_ler_oponente_mm(void);

// true se detectou borda/queda da arena.
bool sensores_borda_detectada(void);

// Distância da borda em cm (para debug/calibração via Serial).
unsigned long sensores_ler_borda_cm(void);

#endif // SENSORES_H
