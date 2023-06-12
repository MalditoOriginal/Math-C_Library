#ifndef S21_MATH_H
#define S21_MATH_H
#define E 2.7182818284590452353602874713527
#define PI 3.141592653589793238462643383279502884L
#define EPSILON 1e-11
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define PRECISION 0.9999999999
#define NEG_INF -1.0 / 0.0
#define PRECISION_TERM 200

long double s21_fact(int x);
long double s21_nan();

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_acos(double x);
long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_pow(double base, double exp);
long double s21_exp(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);

#endif