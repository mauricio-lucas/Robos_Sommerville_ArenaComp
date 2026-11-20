#ifndef CONFIG_H
#define CONFIG_H
// ============================================================
//  CONFIG — Robô SUMÔ
//  Todos os pinos e constantes de ajuste ficam AQUI.
//  Mudou a ligação na protoboard? Mude só este arquivo.
// ============================================================

// ---------- PONTES H / MOTORES (Driver tipo L298N/TB6612) ----------
// Motor A = esquerdo | Motor B = direito
const int PIN_MOTOR_A_IN1 = 5;   // direção A
const int PIN_MOTOR_A_IN2 = 6;   // direção A
const int PIN_MOTOR_B_IN1 = 9;   // direção B
const int PIN_MOTOR_B_IN2 = 10;  // direção B
const int PIN_MOTOR_A_PWM = 3;   // velocidade A (precisa ser ~)
const int PIN_MOTOR_B_PWM = 11;  // velocidade B (precisa ser ~)

// Velocidades (0 = parado, 255 = máximo)
const int VEL_ATAQUE      = 255; // carga máxima no oponente
const int VEL_BUSCA       = 150; // girando procurando o oponente
const int VEL_RECUO       = 200; // ao detectar borda

// ---------- I2C / TCA9548A (SDA=A4, SCL=A5 são fixos no Uno) ----------
const uint8_t ENDERECO_MUX     = 0x70;  // endereço padrão do TCA9548A
const uint8_t CANAL_LASER_FRENTE = 0;   // VL53L0X do oponente
const uint8_t CANAL_LASER_RESERVA = 1;  // 2º VL53L0X (opcional)

// ---------- VL53L0X (sensor de distância a laser) ----------
// distância em milímetros
const uint16_t DIST_OPPONENTE_MM = 300; // abaixo disso: ATACAR
const uint16_t DIST_ATAQUE_MM    = 120; // abaixo disso: carga máxima

// ---------- HC-SR04 DA BORDA (apontado para baixo) ----------
const int PIN_BORDA_TRIG = 2;
const int PIN_BORDA_ECHO = 7;
// A arena é clara; se o sensor apontar para o chão fora dela
// (borda preta/queda), a leitura muda muito. Ajuste com teste real:
const unsigned long BORDA_MIN_CM = 3;   // mais perto que isso = subiu/queda
const unsigned long BORDA_MAX_CM = 30;  // mais longe que isso = não tem chão

// ---------- START ----------
const int PIN_BOTAO_START = 12;         // aperta, espera 5s, luta
const unsigned long DELAY_START_MS = 5000;

// ---------- UTIL ----------
const unsigned long TEMPO_LOOP_MS = 20; // período do loop de decisão

#endif // CONFIG_H
