
#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

START_TEST(abs_test) {
  int a = -123412451;
  ck_assert_double_eq_tol(abs(a), s21_abs(a), 1e-09);
  a = -123242424.0;
  ck_assert_double_eq_tol(abs(a), s21_abs(a), 1e-09);
  a = 123242424.0;
  ck_assert_double_eq_tol(abs(a), s21_abs(a), 1e-09);
  for (int i = -1000; i < 1000; i += 10)
    ck_assert_double_eq_tol(abs(i), s21_abs(i), 1e-09);
}
END_TEST

START_TEST(fabs_test) {
  double a = -0.000001;
  ck_assert_double_eq_tol(fabs(a), s21_fabs(a), 1e-09);
  a = -123242424.12414554533;
  ck_assert_double_eq_tol(fabs(a), s21_fabs(a), 1e-09);
  for (double i = -10; i < 10; i += 0.001)
    ck_assert_double_eq_tol(fabs(i), s21_fabs(i), 1e-09);
}
END_TEST

START_TEST(fmod_test) {
  double x = 53456.43523;
  double y = 2345.34535;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = 53456.43523;
  y = -2345.34535;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = -53456.43523;
  y = 2345.34535;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = -10.1;
  y = -3.;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = 53456.43523;
  y = 0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 0;
  y = 35353.4232;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = 0;
  y = -S21_NaN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = S21_NaN;
  y = 245.32525;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 2424.424525;
  y = S21_NaN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 246346346.43534;
  y = S21_INF;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = S21_INF;
  y = 214124.123;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(2.6, 3.45), pow(2.6, 3.45), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.6, -3.45), pow(2.6, -3.45), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(14, 0.45), pow(14, 0.45), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-16, 9), pow(-16, 9), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(16436.543, 0.31), pow(16436.543, 0.31),
                           1e-6);
  ck_assert_int_eq(s21_pow(S21_INF, 0.45), S21_INF);
  ck_assert_ldouble_nan(s21_pow(S21_NaN, 24252353));
  ck_assert_ldouble_nan(s21_pow(S21_pi, S21_NaN));
}
END_TEST;

START_TEST(sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(S21_pi / 2), sin(S21_pi / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_pi / 4), sin(S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_pi / 6), sin(S21_pi / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_pi / 3), sin(S21_pi / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_pi / 2), sin(-S21_pi / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_pi / 4), sin(-S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_pi / 6), sin(-S21_pi / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_pi / 3), sin(-S21_pi / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_pi), sin(-S21_pi), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_pi), sin(S21_pi), 1e-6);
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(s21_sin(S21_NaN));
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
  ck_assert_ldouble_eq_tol(s21_sin(2.352352), sin(2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-2.352352), sin(-2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.00032), sin(0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.00032), sin(-0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(325235), sin(325235), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-325235), sin(-325235), 1e-6);
}
END_TEST;

START_TEST(cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_pi / 2), cos(S21_pi / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_pi / 4), cos(S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_pi / 6), cos(S21_pi / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_pi / 3), cos(S21_pi / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_pi / 2), cos(-S21_pi / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_pi / 4), cos(-S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_pi / 6), cos(-S21_pi / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_pi / 3), cos(-S21_pi / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_pi), cos(-S21_pi), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_pi), cos(S21_pi), 1e-6);
  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_nan(s21_cos(S21_NaN));
  ck_assert_ldouble_nan(s21_cos(-S21_INF));
  ck_assert_ldouble_eq_tol(s21_cos(2.352352), cos(2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-2.352352), cos(-2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.00032), cos(0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.00032), cos(-0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(32523), cos(32523), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-32523), cos(-32523), 1e-6);
}
END_TEST;

START_TEST(asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(S21_pi / 4), asin(S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(S21_pi / 6), asin(S21_pi / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-S21_pi / 4), asin(-S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-S21_pi / 6), asin(-S21_pi / 6), 1e-6);
  ck_assert_ldouble_nan(s21_asin(S21_INF));
  ck_assert_ldouble_nan(s21_asin(S21_NaN));
  ck_assert_ldouble_nan(s21_asin(-S21_INF));
  ck_assert_ldouble_nan(s21_asin(1.0000001));
  ck_assert_ldouble_nan(s21_asin(-1.0000001));
  ck_assert_ldouble_nan(s21_asin(S21_pi / 3));
}
END_TEST;

START_TEST(acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(S21_pi / 4), acos(S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(S21_pi / 6), acos(S21_pi / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-S21_pi / 4), acos(-S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-S21_pi / 6), acos(-S21_pi / 6), 1e-6);
  ck_assert_ldouble_nan(s21_acos(S21_INF));
  ck_assert_ldouble_nan(s21_acos(S21_NaN));
  ck_assert_ldouble_nan(s21_acos(-S21_INF));
  ck_assert_ldouble_nan(s21_acos(1.0000001));
  ck_assert_ldouble_nan(s21_acos(-1.0000001));
  ck_assert_ldouble_nan(s21_acos(S21_pi / 3));
}
END_TEST;

START_TEST(atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_pi / 2), atan(S21_pi / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_pi / 4), atan(S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_pi / 6), atan(S21_pi / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_pi / 3), atan(S21_pi / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_pi / 2), atan(-S21_pi / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_pi / 4), atan(-S21_pi / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_pi / 6), atan(-S21_pi / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_pi / 3), atan(-S21_pi / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_pi), atan(-S21_pi), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_pi), atan(S21_pi), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF), atan(S21_INF), 1e-6);
  ck_assert_ldouble_nan(s21_atan(S21_NaN));
  ck_assert_ldouble_eq_tol(s21_atan(-S21_INF), atan(-S21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(2.352352), atan(2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-2.352352), atan(-2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.00032), atan(0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.00032), atan(-0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(325235), atan(325235), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-325235), atan(-325235), 1e-6);
}
END_TEST;

START_TEST(ceil_test) {
  ck_assert_ldouble_infinite(s21_ceil(S21_INF));
  double x = 8543948.445;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(232424), ceil(232424));
  ck_assert_ldouble_nan(s21_ceil(S21_NaN));
  ck_assert_ldouble_infinite(s21_ceil(-S21_INF));
}
END_TEST;

START_TEST(floor_test) {
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
  double x = 8543948.445;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  ck_assert_ldouble_infinite(s21_floor(S21_INF));
  ck_assert_ldouble_infinite(s21_floor(-S21_INF));
  x = -8543948.445;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  ck_assert_ldouble_nan(s21_floor(S21_NaN));
}
END_TEST;

START_TEST(sqrt_test) {
  double x = 10.0;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(S21_NaN));
  ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(10e+5), sqrt(10e+5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(2.6), sqrt(2.6), 1e-6);
}
END_TEST;

START_TEST(log_test) {
  double x = 0.0;
  ck_assert_ldouble_infinite(s21_log(x));
  x = 10.0;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  ck_assert_ldouble_infinite(s21_log(S21_INF));
  ck_assert_ldouble_nan(s21_log(S21_NaN));
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
  ck_assert_ldouble_nan(s21_log(-5));
  ck_assert_ldouble_eq_tol(s21_log(10e+16), log(10e+16), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(3.5), log(3.5), 1e-6);
}
END_TEST;

START_TEST(exp_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-6);
  ck_assert_ldouble_infinite(s21_exp(S21_INF));
  ck_assert_ldouble_nan(s21_exp(S21_NaN));
  x = 3.5;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-6);
  x = -32.7584;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-6);
}
END_TEST;

START_TEST(tan_test) {
  double x = S21_pi / 2;
  ck_assert_ldouble_nan(s21_tan(x));
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(s21_tan(-S21_INF));
  ck_assert_ldouble_nan(s21_tan(S21_NaN));
  x = 0;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 1e-06);
  x = 55.49234825;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 1e-06);
  ck_assert_ldouble_eq_tol(s21_tan(-S21_pi / 6), tan(-S21_pi / 6), 1e-0);
  ck_assert_ldouble_eq_tol(s21_tan(2 * S21_pi), tan(2 * S21_pi), 1e-06);
  ck_assert_ldouble_eq_tol(s21_tan(1.00001), tan(1.00001), 1e-06);
  ck_assert_ldouble_eq_tol(s21_tan(-1.00001), tan(-1.00001), 1e-06);
}
END_TEST;

START_TEST(exp_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

// START_TEST(exp_test_4) {
//   double x = 999999999999;
//   ck_assert_ldouble_infinite(s21_exp(x));
//   ck_assert_ldouble_infinite(exp(x));
// }
// END_TEST

// START_TEST(exp_test_5) {
//   double x = -999999999999;
//   ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
// }
// END_TEST

// START_TEST(exp_test_6) {
//   double x = DBL_MAX;
//   ck_assert_ldouble_infinite(s21_exp(x));
//   ck_assert_ldouble_infinite(exp(x));
// }
// END_TEST

// START_TEST(exp_test_7) {
//   double x = -DBL_MAX;
//   ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
// }
// END_TEST

START_TEST(exp_test_8) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_9) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_10) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(exp(NAN));
}
END_TEST

START_TEST(exp_test_11) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(exp(INFINITY));
}
END_TEST

START_TEST(exp_test_12) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), S21_EPS);
}
END_TEST

Suite *test_suite() {
  Suite *s;
  TCase *tc_core, *tc_exp;
  s = suite_create("s21_math.h tests");

  tc_core = tcase_create("core");
  tcase_add_test(tc_core, abs_test);
  tcase_add_test(tc_core, fabs_test);
  tcase_add_test(tc_core, fmod_test);
  tcase_add_test(tc_core, pow_test);
  tcase_add_test(tc_core, sin_test);
  tcase_add_test(tc_core, cos_test);
  tcase_add_test(tc_core, asin_test);
  tcase_add_test(tc_core, acos_test);
  tcase_add_test(tc_core, atan_test);
  tcase_add_test(tc_core, ceil_test);
  tcase_add_test(tc_core, floor_test);
  tcase_add_test(tc_core, sqrt_test);
  tcase_add_test(tc_core, log_test);
  tcase_add_test(tc_core, exp_test);
  tcase_add_test(tc_core, tan_test);

  tc_exp = tcase_create("s21_exp_case");
  tcase_add_test(tc_exp, exp_test_1);
  tcase_add_test(tc_exp, exp_test_2);
  tcase_add_test(tc_exp, exp_test_3);
  // tcase_add_test(tc_exp, exp_test_4);
  // tcase_add_test(tc_exp, exp_test_5);
  // tcase_add_test(tc_exp, exp_test_6);
  // tcase_add_test(tc_exp, exp_test_7);
  tcase_add_test(tc_exp, exp_test_8);
  tcase_add_test(tc_exp, exp_test_9);
  tcase_add_test(tc_exp, exp_test_10);
  tcase_add_test(tc_exp, exp_test_11);
  tcase_add_test(tc_exp, exp_test_12);

  suite_add_tcase(s, tc_exp);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = test_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
