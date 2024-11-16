// TIME

#define Ts_us 20000              // Период квантования в [мкс]
#define Ts_s (Ts_us / 1000000.0) // Период квантования в [с]

// MOTOR PARAMS

#define ENC_PPR 48
#define GEAR_RATIO 30

#define TICK_TO_RAD (2.0 * M_PI / (ENC_PPR * GEAR_RATIO))

#define LPF_ALPHA 0.5
