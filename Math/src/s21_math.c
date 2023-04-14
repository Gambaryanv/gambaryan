#include "s21_math.h"

long long s21_abs(long long x) {
  if (x < 0) x *= -1;
  return x;
}

long double s21_fabs(double x) {
  if (x < 0) x *= -1.;
  return x;
}

long double s21_fmod(double x, double y) {
  long long int sum;
  long double res, def;
  if (y == 0.0 || x == S21_INF) {
    def = S21_NaN;
  } else if (y == S21_INF) {
    def = x;
  } else {
    sum = (long long int)(x / y);
    res = y * (long double)sum;
    def = x - res;
    if (x < 0.0 && res < x) {
      def = y;
    } else if (x >= 0.0 && res > x) {
      def = y;
    }
  }
  return def;
}

long double simple_pow(double x, int y) {
  long long res = 1;
  for (int i = 0; i < y; i++) {
    res *= x;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 0;
  if (S21_ISNAN(base) || S21_ISNAN(exp)) {
    res = S21_NaN;
  } else if (base == 1.0 || exp == 0.0) {
    res = 1.0;
  } else if (base < 0.0 && s21_fmod(exp, 1.0) != 0) {
    res = S21_NaN;
  } else if (base == 0.0 && exp <= 0.0) {
    res = S21_INF;
  } else if (exp == (int)exp) {
    res = simple_pow(base, exp);
  } else {
    res = s21_exp(exp * s21_log(s21_fabs(base)));
    if (base < 0.0 && s21_fmod(exp, 2.0) != 0.0) {
      res *= -1;
    }
  }
  return res;
}

long long s21_factorial(int n) {
  return (n < 2) ? 1 : n * s21_factorial(n - 1);
}

long double s21_exp(double x) {
  long double res = 0;
  long double ans = 0;
  long double stap = 1.0;
  long fuc = 1;
  int flag = 0;
  if (S21_ISNAN(x)) {
    res = S21_NaN;
  } else if (S21_ISINF(x)) {
    res = x < 0 ? 0 : S21_INF;
  } else if (x == 0) {
    res = 1;
  } else {
    if (x < 0) {
      flag = 1;
      x *= -1;
    }
    while (s21_fabs(stap) >= S21_EPS) {
      ans += stap;
      stap *= x / fuc;
      fuc++;
    }
    res = flag ? (1 / ans) : ans;
  }
  return res;
}

long double s21_log(double x) {
  long double res = 0;
  int arg = 0;
  if (S21_ISNAN(x)) {
    res = S21_NaN;
  } else if (S21_ISINF(x)) {
    res = x < 0 ? S21_NaN : S21_INF;
  } else if (x < 0) {
    res = S21_NaN;
  } else if (x == 1) {
    res = 0;
  } else if (x == 0) {
    res = -S21_INF;
  } else {
    while (x >= S21_e) {
      x /= S21_e;
      arg++;
    }
    long double stap = 0;
    for (int i = 0; i < 1000; i++) {
      stap = res;
      res = stap + 2 * ((x - s21_exp(stap)) / (x + s21_exp(stap)));
    }
  }
  return (res + arg);
}

long double s21_sin(double x) {
  x = s21_fmod(x, 2 * S21_pi);
  long double result = 0;
  long double temp = x;
  unsigned flag = 1;
  while (flag < 1000) {
    result += temp;
    flag += 2;
    temp *= -(x * x) / ((flag - 1) * flag);
  }
  return result;
}

long double s21_sqrt(double x) { return x >= 0 ? s21_pow(x, 0.5) : S21_NaN; }

long double s21_cos(double x) {
  x = s21_fmod(x, 2 * S21_pi);
  return s21_sin(x + (S21_pi) / 2.0);
}

long double s21_tan(double x) {
  long double res = 0.0;
  if (S21_ISNAN(x)) {
    res = S21_NaN;
  } else if (S21_ISINF(x)) {
    res = S21_NaN;
  } else {
    x = s21_fmod(x, 2 * S21_pi);
    if (x != S21_pi / 2 && x != -S21_pi / 2 && x != -S21_pi / 2 - S21_pi &&
        x != S21_pi / 2 + S21_pi)
      res = s21_sin(x) / s21_cos(x);
    else
      res = S21_NaN;
  }
  return res;
}

long double s21_atan_tailor(double x) {
  long double res = x;
  long double stap = x;
  long double n = 1;
  while (s21_fabs(stap) > S21_EPS) {
    stap = -1 * stap * x * x * (2 * n - 1) / (2 * n + 1);
    n += 1;
    res += stap;
  }
  return res;
}

long double s21_atan(double x) {
  long double res = 0;
  if (x == 1.0) {
    res = S21_pi / 4;
  } else if (x == S21_INF) {
    res = S21_pi / 2;
  } else if (x == -S21_INF) {
    res = -S21_pi / 2;
  } else if (x == -1.0) {
    res = (-1 * S21_pi / 4);
  } else if (x == 0) {
    res = 0;
  } else if (x > 1.0) {
    res = S21_pi / 2 - s21_atan_tailor(1 / x);
  } else if (x < -1.0) {
    res = -1 * S21_pi / 2 - s21_atan_tailor(1 / x);
  } else if (S21_ISNAN(x)) {
    res = S21_NaN;
  } else if (x < 1.0 && x > -1.0) {
    res = s21_atan_tailor(x);
  }
  return res;
}

long double s21_asin(double x) {
  long double res = 0;
  if (S21_ISNAN(x) || x > 1 || x < -1) {
    res = S21_NaN;
  } else if (x == 1) {
    res = S21_pi / 2;
  } else if (x == -1) {
    res = -S21_pi / 2;
  } else {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return res;
}

long double s21_acos(double x) {
  long double res = 0;
  if (S21_ISNAN(x) || x > 1 || x < -1) {
    res = S21_NaN;
  } else if (x == 1) {
    res = 0;
  } else if (x == -1) {
    res = S21_pi;
  } else if (x == 0) {
    res = S21_pi / 2;
  } else if (x > 0 && x <= 1) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x < 0 && x >= -1) {
    res = S21_pi + s21_atan(s21_sqrt(1 - x * x) / x);
  }
  return res;
}

long double s21_floor(double x) {
  long double res = 0;
  if (x == S21_INF) {
    res = S21_INF;
  } else if (x == -S21_INF) {
    res = -S21_INF;
  } else if (S21_ISNAN(x)) {
    res = S21_NaN;
  } else if (x == -0.0) {
    res = -0.0;
  } else if (x == (int)x) {
    res = x;
  } else if (x >= 0) {
    res = (int)x;
  } else if (x < 0) {
    res = (x - (1. + (x - (int)x / 1.0)));
  }
  return res;
}

long double s21_ceil(double x) {
  long double res = 0;
  if (S21_ISNAN(x)) {
    res = S21_NaN;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else if (x == -S21_INF) {
    res = -S21_INF;
  } else if (x == -0.0) {
    res = -0.0;
  } else if (x == (int)x) {
    res = x;
  } else if (x <= 0) {
    res = (int)x;
  } else if (x > 0) {
    res = x + (1. - (x - (int)x / 1.0));
  }
  return res;
}
