#include <Arduino.h>

#include "Encoder.h"

#define Ts_us 5000 // Период квантования в [мкс]
#define Ts_s (Ts_us / 1000000.0) // Период квантования в [с]

void setup()
{
  //////// INIT /////////
  left_enc_init();

  Serial.begin(9600);
}

void loop()
{
  ///////// TIMER /////////
  // Задание постоянной частоты главного цикла прогааммы
  static uint32_t timer = micros();
  while(micros() - timer < Ts_us)
    ;
  timer = micros();
  
  ///////// SENSE /////////
  // Считывание датчиков
  left_enc_tick();
  const float left_phi = g_left_phi;

  ///////// PLAN /////////
  // Расчет управляющих воздействий

  ///////// ACT /////////
  // Приведение управляющих воздействий в действие и логирование данных
  Serial.println(left_phi);
}