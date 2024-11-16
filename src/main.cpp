#include <Arduino.h>

#include "Config.h"
// #include "LeftEncoder.h"
// #include "RightEncoder.h"
// #include "VelEstimator.h"
#include "Encoder.h"

#include "Devices.h"

void setup()
{
  //////// INIT /////////
  // left_enc_init();
  // right_enc_init();
  leftEncoder.init();
  rightEncoder.init();

  Serial.begin(9600);
}

void loop()
{
  ///////// TIMER /////////
  // Задание постоянной частоты главного цикла прогааммы
  static uint32_t timer = micros();
  while (micros() - timer < Ts_us)
    ;
  uint32_t dt = micros() - timer;
  timer = micros();

  ///////// SENSE /////////
  // Считывание датчиков
  // left_enc_tick();
  // right_enc_tick();
  // const float left_phi = g_left_phi;
  // const float right_phi = g_right_phi;
  // velest_tick();
  // const float left_w = g_left_w;
  // const float right_w = g_right_w;
  leftEncoder.tick();
  rightEncoder.tick();

  // ///////// PLAN /////////
  // // Расчет управляющих воздействий

  // ///////// ACT /////////
  // // Приведение управляющих воздействий в действие и логирование данных
  Serial.print(dt);
  Serial.print(" ");
  Serial.print(leftEncoder.q_phi);
  Serial.print(" ");
  Serial.println(rightEncoder.q_phi);
}