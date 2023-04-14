#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <limits.h>

#define S21_pi 3.1415926535
#define S21_e 2.7182818284
#define S21_EPS 1E-9
#define s21_ln10 2.302585092994

#define S21_NaN 0.0 / 0.0
#define S21_INF 1.0 / 0.0

#define S21_ISNAN(x) (!(x >= 0) && !(x < 0))
#define S21_ISINF(x) ((x == S21_INF) || (x == -S21_INF))

#include <stdio.h>
#include <stdlib.h>

long long s21_abs(long long x);
long double s21_fabs(double x);
long double s21_pow(double base, double exp);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sin(double x);
long double s21_fmod(double x, double y);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_sqrt(double x);

#endif  // SRC_S21_MATH_H__
