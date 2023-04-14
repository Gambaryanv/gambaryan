#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  s21_NORMAL_VALUE = 0,
  s21_INFI = 1,
  s21_NEGATIVE_INFI = 2,
  s21_NAN = 3,
  s21_DOPCODE = 4,
} value_type_t;

typedef struct {
  unsigned bits[4];
} s21_decimal;

typedef struct {
  unsigned bits[7];
} s21_decimal_x2;

// == Преобразование ==  //

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// ==Сравнение== //

int s21_is_less(s21_decimal dec_a, s21_decimal dec_b);
// dec_a < dec_b
int s21_is_less_or_equal(s21_decimal dec_a, s21_decimal dec_b);
// dec_a <= dec_b
int s21_is_greater(s21_decimal dec_a, s21_decimal dec_b);
// dec_a > dec_b
int s21_is_greater_or_equal(s21_decimal dec_a, s21_decimal dec_b);
// dec_a >= dec_b
int s21_is_equal(s21_decimal dec_a, s21_decimal dec_b);
// dec_a == dec_b
int s21_is_not_equal(s21_decimal dec_a, s21_decimal dec_b);
// dec_a != dec_b

// ==Прочие функции== //

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// ==Арифметика== //
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int null_big_decimal(s21_decimal_x2 op);
int proverka_null(s21_decimal src);
void otkat(s21_decimal_x2 *norm_c, s21_decimal *stepen);
int otkat_truncate(s21_decimal_x2 *norm_c, int stepen);
void znak(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal de_normaliz(s21_decimal_x2 src, int *err_code, int step);
s21_decimal_x2 funk_mod(s21_decimal_x2 src1, s21_decimal_x2 src2);
void set_cexp(s21_decimal *op, int value);
unsigned get_cexp(s21_decimal op);
unsigned get_sign(s21_decimal op);
s21_decimal_x2 in_big_decimal(s21_decimal op);
unsigned get_bit(s21_decimal_x2 dst, unsigned bit);
unsigned get_bit_x1(s21_decimal dst, unsigned bit);
unsigned get_stepen(s21_decimal src);
void set_bit(s21_decimal_x2 *dec_c, int i, int znchenie);
void set_bit_X1(s21_decimal *dec_c, int i, int znchenie);
s21_decimal_x2 shift_bit_right(s21_decimal_x2 src);
s21_decimal_x2 shift_bit_left(s21_decimal_x2 src);
void s21_func_sub(s21_decimal_x2 value_1, s21_decimal_x2 value_2,
                  s21_decimal_x2 *result_big);
void s21_func_add(s21_decimal_x2 value_1, s21_decimal_x2 value_2,
                  s21_decimal_x2 *result_big);
s21_decimal_x2 s21_func_div(s21_decimal_x2 norm_a, s21_decimal_x2 norm_b);
s21_decimal_x2 mul_funk(s21_decimal_x2 big_op1, s21_decimal_x2 big_op2);
s21_decimal_x2 normalizator(s21_decimal_x2 norm, int step);
s21_decimal_x2 scale_s21_decimal_x2(s21_decimal_x2 norm);
void set_sign(s21_decimal *value, int sign);
void optimizcia_stepeni(int step_a, int step_b, s21_decimal value_1,
                        s21_decimal value_2, s21_decimal_x2 *result_big,
                        int flag);
int srav_f(s21_decimal_x2 dec_a, s21_decimal_x2 dec_b, int znach_a,
           int znach_b);
int rb_pak(s21_decimal dec_a, s21_decimal dec_b);
s21_decimal modul(s21_decimal value);
void step_in_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *stepen);
int return_value(s21_decimal_x2 *result_big, s21_decimal *result);
s21_decimal clin_3_bit(s21_decimal dec_a);
int is_decimal_zero(s21_decimal *src);

#endif  // _SRC_S21_DECIMAL_H_