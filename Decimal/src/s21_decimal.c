#include "s21_decimal.h"

void otkat(s21_decimal_x2 *norm_c, s21_decimal *stepen) {
  int value = 2;
  int h = 0;
  s21_decimal stepen_1 = {{0b10000000000000000, 0, 0, 0}};
  s21_decimal stepen_0 = {{0, 0, 0, 0}};
  s21_decimal stepen_mod = {{stepen->bits[0], 0, 0, 0}};

  set_bit_X1(&stepen_mod, 31, 0);
  s21_decimal_x2 div_on_10 = {{10, 0, 0, 0, 0, 0, 0}};
  s21_decimal_x2 on_5 = {{0b101, 0, 0, 0, 0, 0, 0}};
  s21_decimal_x2 norma_add_1 = {{0b1, 0, 0, 0, 0, 0, 0}};

  s21_decimal_x2 norma_c_mod_0 = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_x2 norma_c_mod_rith = {{0, 0, 0, 0, 0, 0, 0}};

  s21_decimal step29 = {{0b111000000000000000000, 0, 0, 0}};
  while ((value == 2) && (s21_is_greater(stepen_mod, stepen_0) != 0) &&
         (srav_f(*norm_c, norma_c_mod_0, 0, 0) != 0)) {
    for (int i = 96; i < 193; i++) {
      if (get_bit(*norm_c, i) != 0) {
        value = 2;
        break;
      } else {
        if (s21_is_greater(stepen_mod, step29) != 0) {
          value = 2;
        } else {
          value = 0;
        }
      }
    }
    if (value != 0) {
      s21_sub(stepen_mod, stepen_1, &stepen_mod);
      s21_sub(*stepen, stepen_1, stepen);
      norma_c_mod_rith = s21_func_div(*norm_c, div_on_10);
      norma_c_mod_rith = mul_funk(norma_c_mod_rith, div_on_10);
      s21_func_sub(*norm_c, norma_c_mod_rith, &norma_c_mod_rith);
      h = srav_f(norma_c_mod_rith, on_5, 0, 0);
      *norm_c = s21_func_div(*norm_c, div_on_10);
    }
  }
  if (h == 2) {
    s21_func_add(*norm_c, norma_add_1, norm_c);
  }
}

void step_in_div(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *stepen) {
  s21_decimal norm_a = {{value_1.bits[3], 0, 0, 0}};
  s21_decimal norm_b = {{value_2.bits[3], 0, 0, 0}};
  s21_sub(norm_a, norm_b, stepen);
}

s21_decimal_x2 s21_func_div(s21_decimal_x2 src1, s21_decimal_x2 src2) {
  s21_decimal_x2 resalt = {{0, 0, 0, 0, 0, 0, 0}};
  int shift = 0;
  while (!get_bit(src2, 191 - shift)) {
    shift++;
  }
  for (int i = 0; !get_bit(src1, 191 - i); i++) {
    shift--;
  }
  if (shift >= 0) {
    for (int k = 0; k < shift; k++) {
      src2 = shift_bit_left(src2);
    }
    while (shift >= 0) {
      int v = 9;
      int n = srav_f(src1, src2, 0, 0);
      if (n == 1) {
        v = 0;
      } else {
        v = 1;
      }
      set_bit(&resalt, 0, v);
      if (get_bit(resalt, 0)) {
        s21_func_sub(src1, src2, &src1);
      }
      src2 = shift_bit_right(src2);
      if (shift) resalt = shift_bit_left(resalt);
      shift--;
    }
  }
  return resalt;
}

s21_decimal_x2 shift_bit_left(s21_decimal_x2 src) {
  s21_decimal_x2 dst = {{0, 0, 0, 0, 0, 0, 0}};
  for (int i = 1; i < 192; i++) {
    set_bit(&dst, i, !!(get_bit(src, i - 1)));
  }
  return dst;
}

s21_decimal_x2 shift_bit_right(s21_decimal_x2 src) {
  s21_decimal_x2 dst = {{0, 0, 0, 0, 0, 0, 0}};
  for (int i = 0; i < 191; i++) {
    set_bit(&dst, i, !!get_bit(src, i + 1));
  }
  set_bit(&dst, 191, 0);
  return dst;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int h = 0;
  s21_decimal_x2 dec_a = in_big_decimal(value_1);
  s21_decimal_x2 dec_b = in_big_decimal(value_2);
  s21_decimal_x2 result_big = {{0, 0, 0, 0, 0, 0, 0}};
  if ((proverka_null(value_1) == 0) || (proverka_null(value_2) == 0)) {
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;
  } else {
    result_big = mul_funk(dec_a, dec_b);
    s21_decimal step1 = {{value_1.bits[3], 0, 0, 0}};
    set_bit_X1(&step1, 31, 0);
    s21_decimal step2 = {{value_2.bits[3], 0, 0, 0}};
    set_bit_X1(&step2, 31, 0);
    s21_decimal step = {{0, 0, 0, 0}};
    s21_add(step1, step2, &step);
    otkat(&result_big, &step);
    result_big.bits[6] = step.bits[0];
    h = return_value(&result_big, result);
    int znach_a = get_bit_x1(value_1, 127);
    int znach_b = get_bit_x1(value_2, 127);
    if (znach_a != 0 || znach_b != 0) {
      if (h != 0) {
        h = 2;
      } else {
        set_bit_X1(result, 127, 1);
      }
    }
    if (znach_a != 0 && znach_b != 0) {
      set_bit_X1(result, 127, 0);
    }
  }
  return h;
}

int proverka_null(s21_decimal src) {
  int flag0 = 0;
  for (int l = 0; l < 96; l++) {
    if (get_bit_x1(src, l) > 0) {
      flag0 = 1;

      break;
    }
  }
  return flag0;
}

s21_decimal_x2 mul_funk(s21_decimal_x2 big_op1, s21_decimal_x2 big_op2) {
  set_bit(&big_op1, 223, 0);
  set_bit(&big_op2, 223, 0);
  s21_decimal step_a = {{big_op1.bits[0], 0, 0, 0}};
  s21_decimal step_b = {{big_op2.bits[0], 0, 0, 0}};
  s21_decimal step = {{0, 0, 0, 0}};
  s21_add(step_a, step_b, &step);
  s21_decimal_x2 dst = {{0, 0, 0, 0, 0, 0, 0}};
  while (!null_big_decimal(big_op2)) {
    if (get_bit(big_op2, 0)) {
      s21_func_add(dst, big_op1, &dst);
    }
    big_op1 = shift_bit_left(big_op1);
    big_op2 = shift_bit_right(big_op2);
  }
  return dst;
}

int null_big_decimal(s21_decimal_x2 src) {
  int result = 1;
  for (int i = 5; i >= 0; i--) {
    if (src.bits[i]) {
      result = 0;
      break;
    }
  }
  return result;
}
int return_value(s21_decimal_x2 *result_big, s21_decimal *result) {
  s21_decimal step = {{result_big->bits[6], 0, 0, 0}};
  set_bit_X1(&step, 31, 0);
  s21_decimal step29 = {{0b111000000000000000000, 0, 0, 0}};
  int value = 0;
  for (int i = 96; i < 193; i++) {
    if (get_bit(*result_big, i) > 0) {
      if (get_bit(*result_big, 223) > 0) {
        value = 2;
      } else {
        value = 1;
      }
      break;
    }
  }

  if (s21_is_greater(step, step29) != 0) {
    if (get_bit(*result_big, 223) > 0) {
      value = 1;
    } else {
      value = 2;
    }
  }

  if (value != 0) {
    result->bits[3] = 0;
    result->bits[2] = 0;
    result->bits[1] = 0;
    result->bits[0] = 0;
  } else {
    result->bits[3] = result_big->bits[6];
    result->bits[2] = result_big->bits[2];
    result->bits[1] = result_big->bits[1];
    result->bits[0] = result_big->bits[0];
  }
  return value;
}
unsigned get_bit_x1(s21_decimal dst, unsigned bit) {
  int res = 0;
  unsigned int mask = 1u << (bit % 32);
  res = dst.bits[bit / 32] & mask;
  return res;
}

s21_decimal_x2 in_big_decimal(s21_decimal op) {
  s21_decimal_x2 result = {{op.bits[0], op.bits[1], op.bits[2], 0, 0, 0, 0}};
  return result;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int result_code = 0;
  int sign = get_sign(value_1);
  int dst_exp = 0;
  dst_exp = get_cexp(value_1) >= get_cexp(value_2) ? get_cexp(value_1)
                                                   : get_cexp(value_2);
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  if (s21_is_greater(value_1, value_2)) {
    s21_decimal_x2 value_1_big_decimal = in_big_decimal(value_1);
    s21_decimal_x2 value_2_big_decimal = in_big_decimal(value_2);
    if (null_big_decimal(value_2_big_decimal)) {
      result_code = 3;
    } else {
      if (get_cexp(value_1) > get_cexp(value_2)) {
        value_2_big_decimal = normalizator(
            value_2_big_decimal, get_cexp(value_1) - get_cexp(value_2));
      }
      if (get_cexp(value_2) > get_cexp(value_1)) {
        value_1_big_decimal = normalizator(
            value_1_big_decimal, get_cexp(value_2) - get_cexp(value_1));
      }
      value_1_big_decimal = funk_mod(value_1_big_decimal, value_2_big_decimal);
      value_1 =
          de_normaliz(value_1_big_decimal, &result_code, get_cexp(value_1));
    }
  } else {
    dst_exp = get_cexp(value_1);
  }
  set_cexp(&value_1, dst_exp);
  set_sign(&value_1, sign);
  *result = value_1;
  return result_code;
}

int big_decimal_mod_10(s21_decimal_x2 src) {
  int dst = 0;
  for (int i = 191; i >= 0; i--) {
    dst = dst << 1;
    dst |= get_bit(src, i);
    if (dst >= 10) dst -= 10;
  }
  return dst;
}

unsigned get_sign(s21_decimal op) { return (op.bits[3] & 0x80000000U) >> 31; }

void set_sign(s21_decimal *value, int sign) {
  value->bits[3] =
      (sign) ? value->bits[3] | 0x80000000U : value->bits[3] & ~0x80000000U;
}
void set_cexp(s21_decimal *op, int value) {
  op->bits[3] = (op->bits[3] & 0x80000000U) | (value << 16);
}
unsigned get_cexp(s21_decimal op) { return (op.bits[3] & 0x00FF0000U) >> 16; }

s21_decimal de_normaliz(s21_decimal_x2 src, int *err_code, int step) {
  *err_code = 0;
  s21_decimal_x2 ten = {{10, 0, 0, 0, 0, 0, 0}};

  unsigned cexp = step;

  int tmp_out = 0;
  int full = 0;
  while (((src.bits[3] || src.bits[4] || src.bits[5]) && cexp) || cexp > 28) {
    full = 1;
    tmp_out = big_decimal_mod_10(src);
    src = s21_func_div(src, ten);
    cexp--;
  }
  if (src.bits[3] || src.bits[4] || src.bits[5]) {
    src = (s21_decimal_x2){{0, 0, 0, 0, 0, 0, 0}};
    *err_code = 2;
  }
  if (full && tmp_out > 4) {
    src = s21_func_div(src, ten);
  }
  s21_decimal result = {{src.bits[0], src.bits[1], src.bits[2], 0}};

  set_cexp(&result, cexp);
  return result;
}

s21_decimal_x2 funk_mod(s21_decimal_x2 src1, s21_decimal_x2 src2) {
  int shift = 0;
  while (!get_bit(src2, 191 - shift)) {
    shift++;
  }
  for (int i = 0; !get_bit(src1, 191 - i); i++) {
    shift--;
  }
  if (shift >= 0) {
    for (int k = 0; k < shift; k++) {
      src2 = shift_bit_left(src2);
    }

    while (shift >= 0) {
      int v = 9;
      int n = srav_f(src1, src2, 0, 0);
      if (n == 1) {
        v = 0;
      } else {
        v = 1;
      }
      if (v == 1) {
        s21_func_sub(src1, src2, &src1);
      }
      src2 = shift_bit_right(src2);
      shift--;
    }
  }
  return src1;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int result_znac = 0;
  int flag = 0;
  s21_decimal_x2 norm_a = in_big_decimal(value_1);
  s21_decimal_x2 norm_b = in_big_decimal(value_2);
  s21_decimal_x2 norm_c = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal stepen = {{0, 0, 0, 0}};
  s21_decimal stepen_1 = {{0b10000000000000000, 0, 0, 0}};
  s21_decimal_x2 mod = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal mod_x1 = {{0, 0, 0, 0}};
  s21_decimal_x2 x10 = {{10, 0, 0, 0, 0, 0, 0}};
  s21_decimal_x2 baff = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal baff_x1 = {{0, 0, 0, 0}};
  s21_decimal_x2 null_mod = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal null_mod_x1 = {{0, 0, 0, 0}};
  int q = proverka_null(value_1);
  int w = proverka_null(value_2);
  if (w == 0) {
    result_znac = 3;
    for (int m = 0; m < 4; m++) {
      result->bits[m] = 0;
    }
  } else if (q == 0) {
    result_znac = 0;
    for (int m = 0; m < 4; m++) {
      result->bits[m] = 0;
    }
  } else {
    unsigned step_a = get_stepen(value_1);
    unsigned step_b = get_stepen(value_2);
    if (step_a < step_b) {
      norm_a = normalizator(norm_a, step_b);
      norm_a.bits[6] = value_1.bits[3];
      norm_b = normalizator(norm_b, step_a);
      norm_b.bits[6] = value_2.bits[3];
      flag = 1;
    } else {
      norm_a = normalizator(norm_a, step_a);
      norm_a.bits[6] = value_1.bits[3];
      norm_b = normalizator(norm_b, step_a);
      norm_b.bits[6] = value_2.bits[3];
    }
    set_bit(&norm_a, 223, 0);
    set_bit(&norm_b, 223, 0);
    step_in_div(value_1, value_2, &stepen);
    if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0) {
      result_znac = 0;

    } else {
      norm_c = s21_func_div(norm_a, norm_b);
      s21_func_sub(norm_a, mul_funk(norm_b, norm_c), &mod);
      int l = 9;
      l = srav_f(mod, null_mod, 0, 0);
      int tochnost = 0;
      while (tochnost < 28 && l == 2) {
        mod = mul_funk(mod, x10);
        norm_c = mul_funk(norm_c, x10);
        norm_a = mul_funk(norm_a, x10);
        baff = s21_func_div(mod, norm_b);
        s21_func_add(norm_c, baff, &norm_c);
        s21_add(stepen, stepen_1, &stepen);
        s21_func_sub(norm_a, mul_funk(norm_b, norm_c), &mod);
        l = srav_f(mod, null_mod, 0, 0);
        tochnost++;
      }
    }
  }
  otkat(&norm_c, &stepen);
  result_znac = return_value(&norm_c, result);
  if (flag == 0) {
    result->bits[3] = stepen.bits[0];
    s21_mul(*result, value_2, &baff_x1);
    s21_sub(value_1, baff_x1, &mod_x1);
    int l = s21_is_equal(mod_x1, null_mod_x1);
    if (l == 0) {
      l = 2;
    }
  }
  znak(value_1, value_2, result);
  return result_znac;
}

void znak(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int znach_a = get_bit_x1(value_1, 127);
  int znach_b = get_bit_x1(value_2, 127);
  if (znach_a != 0 || znach_b != 0) {
    set_bit_X1(result, 127, 1);
  }
  if (znach_a != 0 && znach_b != 0) {
    set_bit_X1(result, 127, 0);
  }
}
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal_x2 norm_a = in_big_decimal(value_1);
  s21_decimal_x2 norm_b = in_big_decimal(value_2);
  s21_decimal_x2 result_big = {{0, 0, 0, 0, 0, 0, 0}};
  unsigned step_a = get_stepen(value_1);
  unsigned step_b = get_stepen(value_2);
  norm_a = normalizator(norm_a, step_b);
  norm_a.bits[6] = value_1.bits[3];
  norm_b = normalizator(norm_b, step_a);
  norm_b.bits[6] = value_2.bits[3];
  int flag = 0;
  s21_decimal modul_value_1 = {{0, 0, 0, 0}};
  s21_decimal modul_value_2 = {{0, 0, 0, 0}};
  modul_value_1 = modul(value_1);
  modul_value_2 = modul(value_2);
  if ((get_bit(norm_a, 223) != 0) && (get_bit(norm_b, 223) == 0)) {
    if (s21_is_greater(modul_value_1, modul_value_2) == 0) {
      s21_func_sub(norm_b, norm_a, &result_big);
    } else {
      s21_func_sub(norm_a, norm_b, &result_big);
      flag = 1;
    }
  } else if ((get_bit(norm_a, 223) == 0) && (get_bit(norm_b, 223) != 0)) {
    if (s21_is_greater(modul_value_1, modul_value_2) == 0) {
      s21_func_sub(norm_b, norm_a, &result_big);
      flag = 1;
    } else {
      s21_func_sub(norm_a, norm_b, &result_big);
    }
  } else if ((get_bit(norm_a, 223) != 0) && (get_bit(norm_b, 223) != 0)) {
    flag = 1;
    s21_func_add(norm_a, norm_b, &result_big);
  } else {
    s21_func_add(norm_a, norm_b, &result_big);
  }
  optimizcia_stepeni(step_a, step_b, value_1, value_2, &result_big, flag);
  s21_decimal stepen99 = {{result_big.bits[6], 0, 0, 0}};
  otkat(&result_big, &stepen99);
  result_big.bits[6] = stepen99.bits[0];
  int h = 9;
  h = return_value(&result_big, result);
  return h;
}

void optimizcia_stepeni(int step_a, int step_b, s21_decimal value_1,
                        s21_decimal value_2, s21_decimal_x2 *result, int flag) {
  s21_decimal_x2 norm_b = {{10, 0, 0, 0, 0, 0, 0}};

  int flag0 = 0;
  int m_step = 0;
  if (step_b < step_a) {
    m_step = step_b;
  } else {
    m_step = step_a;
  }
  for (int l = 0; l < 193; l++) {
    if (get_bit(*result, l) > 0) {
      flag0 = 1;
      break;
    }
  }
  if (flag0 == 0) {
    flag = 0;
  }
  if (flag0 != 0) {
    while (m_step > 0) {
      *result = s21_func_div(*result, norm_b);
      m_step--;
    }
  }

  if (step_b < step_a) {
    result->bits[6] = value_1.bits[3];
    set_bit(result, 223, 0);

  } else {
    result->bits[6] = value_2.bits[3];
    set_bit(result, 223, 0);
  }
  if (flag == 1) {
    set_bit(result, 223, 1);
  }
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal_x2 norm_a = in_big_decimal(value_1);
  s21_decimal_x2 norm_b = in_big_decimal(value_2);
  /*
  printf("\n\n\n\n\nПервое число\n%d \n %d\n%d\n %d\n ", value_1.bits[0],
         value_1.bits[1], value_1.bits[2], value_1.bits[4]);
  printf("Второе число\n%d \n %d\n%d\n %d\n ", value_2.bits[0], value_2.bits[1],
         value_2.bits[2], value_2.bits[4]);
         */
  s21_decimal_x2 result_big = {{0, 0, 0, 0, 0, 0, 0}};
  unsigned step_a = get_stepen(value_1);
  unsigned step_b = get_stepen(value_2);
  norm_a = normalizator(norm_a, step_b);
  norm_a.bits[6] = value_1.bits[3];
  norm_b = normalizator(norm_b, step_a);
  norm_b.bits[6] = value_2.bits[3];
  int flag = 0;
  s21_decimal modul_value_1 = {{0, 0, 0, 0}};
  s21_decimal modul_value_2 = {{0, 0, 0, 0}};
  modul_value_1 = modul(value_1);
  modul_value_2 = modul(value_2);
  if ((get_bit(norm_a, 223) != 0) && (get_bit(norm_b, 223) == 0)) {
    s21_func_add(norm_a, norm_b, &result_big);
    flag = 1;
  } else if ((get_bit(norm_a, 223) == 0) && (get_bit(norm_b, 223) != 0)) {
    s21_func_add(norm_a, norm_b, &result_big);
  } else if ((get_bit(norm_a, 223) != 0) && (get_bit(norm_b, 223) != 0)) {
    if (s21_is_greater(modul_value_1, modul_value_2) == 0) {
      s21_func_sub(norm_b, norm_a, &result_big);
    } else {
      s21_func_sub(norm_a, norm_b, &result_big);
      flag = 1;
    }
  } else {
    if (s21_is_greater(value_1, value_2) == 0) {
      s21_func_sub(norm_b, norm_a, &result_big);
      flag = 1;
    } else {
      s21_func_sub(norm_a, norm_b, &result_big);
    }
  }

  optimizcia_stepeni(step_a, step_b, value_1, value_2, &result_big, flag);
  s21_decimal stepen99 = {{result_big.bits[6], 0, 0, 0}};
  otkat(&result_big, &stepen99);
  result_big.bits[6] = stepen99.bits[0];
  int g = return_value(&result_big, result);
  return g;
}

void s21_func_add(s21_decimal_x2 value_1, s21_decimal_x2 value_2,
                  s21_decimal_x2 *result) {
  int baff = 0;
  for (int i = 0; i <= 192; i++) {
    if (((get_bit(value_1, i) > 0) && (get_bit(value_2, i) == 0)) ||
        ((get_bit(value_1, i) == 0) && (get_bit(value_2, i) > 0))) {
      int znchenie = 1;
      if (baff == 1) {
        znchenie = 0;
      }
      set_bit(result, i, znchenie);
    }
    if ((get_bit(value_1, i) == 0) && (get_bit(value_2, i) == 0)) {
      int znchenie = 0;
      if (baff == 1) {
        znchenie = 1;
      }
      baff = 0;
      set_bit(result, i, znchenie);
    }
    if ((get_bit(value_1, i) > 0) && (get_bit(value_2, i) > 0)) {
      int znchenie = 0;
      if (baff == 1) {
        znchenie = 1;
      }
      baff = 1;
      set_bit(result, i, znchenie);
    }
  }
}

void s21_func_sub(s21_decimal_x2 value_1, s21_decimal_x2 value_2,
                  s21_decimal_x2 *result) {
  int baff = 0;
  for (int i = 0; i <= 192; i++) {
    if ((get_bit(value_1, i) > 0) && (get_bit(value_2, i) == 0)) {
      int znchenie = 1;
      if (baff == 1) {
        znchenie = 0;
        baff = 0;
      }
      set_bit(result, i, znchenie);
    }
    if ((get_bit(value_1, i) == 0) && (get_bit(value_2, i) > 0)) {
      int znchenie = 1;
      if (baff == 1) {
        znchenie = 0;
      }
      baff = 1;
      set_bit(result, i, znchenie);
    }
    if ((get_bit(value_1, i) == 0) && (get_bit(value_2, i) == 0)) {
      int znchenie = 0;
      if (baff == 1) {
        znchenie = 1;
      }
      set_bit(result, i, znchenie);
    }
    if ((get_bit(value_1, i) > 0) && (get_bit(value_2, i) > 0)) {
      int znchenie = 0;
      if (baff == 1) {
        znchenie = 1;
      }
      set_bit(result, i, znchenie);
    }
  }
}

unsigned get_bit(s21_decimal_x2 dst, unsigned bit) {
  int res = 0;
  unsigned int mask = 1u << (bit % 32);
  res = dst.bits[bit / 32] & mask;
  return res;
}
unsigned get_stepen(s21_decimal src) {
  src = clin_3_bit(src);
  unsigned stepen;
  stepen = ((src.bits[3] << 1) >> 17);
  return stepen;
}

void set_bit(s21_decimal_x2 *dec_c, int i, int znchenie) {
  unsigned int bit = 1u << (i % 32);
  if (znchenie == 1) {
    dec_c->bits[i / 32] |= bit;
  } else {
    dec_c->bits[i / 32] &= ~bit;
  }
}

s21_decimal_x2 normalizator(s21_decimal_x2 norm, int step) {
  while (step--) {
    norm = scale_s21_decimal_x2(norm);
  }
  return norm;
}

s21_decimal_x2 scale_s21_decimal_x2(s21_decimal_x2 norm) {
  s21_decimal_x2 norml = {{0, 0, 0, 0, 0, 0}};
  unsigned long long baff = 0;
  for (int i = 0; i < 6; i++) {
    baff = baff + (unsigned long long)norm.bits[i] * 10;
    norml.bits[i] = (unsigned)baff;
    baff = baff >> 32;
  }
  return norml;
}
s21_decimal clin_3_bit(s21_decimal dec_a) {
  for (int i = 0; i < 112; i++) {
    set_bit_X1(&dec_a, i, 0);
  }
  for (int i = 120; i < 127; i++) {
    set_bit_X1(&dec_a, i, 0);
  }
  return dec_a;
}
int rb_pak(s21_decimal dec_a, s21_decimal dec_b) {
  int res = 8;
  int znach_a = get_bit_x1(dec_a, 127);
  int znach_b = get_bit_x1(dec_b, 127);
  s21_decimal_x2 norm_a = in_big_decimal(dec_a);
  s21_decimal_x2 norm_b = in_big_decimal(dec_b);
  unsigned step_a = get_stepen(dec_a);
  unsigned step_b = get_stepen(dec_b);
  norm_a = normalizator(norm_a, step_b);
  norm_b = normalizator(norm_b, step_a);
  res = srav_f(norm_a, norm_b, znach_a, znach_b);
  return res;
}

int srav_f(s21_decimal_x2 dec_a, s21_decimal_x2 dec_b, int znach_a,
           int znach_b) {
  int res = 0;
  int flsg_iskl_0 = 0;
  int j = 0;
  while (j < 192) {
    if ((get_bit(dec_a, j) != 0) || (get_bit(dec_b, j) != 0)) {
      flsg_iskl_0 = 1;
      break;
    }
    j++;
  }
  if (!znach_a && znach_b && (flsg_iskl_0 == 1)) {
    res = 2;
  } else if (znach_a && !znach_b && (flsg_iskl_0 == 1)) {
    res = 1;
  } else if (flsg_iskl_0 == 0) {
    res = 0;
  } else if (!znach_a && !znach_b && (flsg_iskl_0 == 1)) {
    for (int i = 191; i >= 0; i--) {
      if (get_bit(dec_a, i) > get_bit(dec_b, i)) {
        res = 2;
        break;
      }
      if (get_bit(dec_a, i) < get_bit(dec_b, i)) {
        res = 1;
        break;
      }
    }
  } else {
    for (int i = 191; i >= 0; i--) {
      if (get_bit(dec_a, i) > get_bit(dec_b, i)) {
        res = 1;
        break;
      }
      if (get_bit(dec_a, i) < get_bit(dec_b, i)) {
        res = 2;
        break;
      }
    }
  }
  if (res == 0 && (znach_a == znach_b)) {
    res = 0;
  }
  return res;
}

s21_decimal modul(s21_decimal value) {
  set_bit_X1(&value, 127, 0);
  return value;
}

void set_bit_X1(s21_decimal *dec_c, int i, int znchenie) {
  unsigned int bit = 1u << (i % 32);
  if (znchenie == 1) {
    dec_c->bits[i / 32] |= bit;
  } else {
    dec_c->bits[i / 32] &= ~bit;
  }
}

int s21_is_not_equal(s21_decimal dec_a, s21_decimal dec_b) {
  int res_not_equal = 0;
  int res = 9;
  res = rb_pak(dec_a, dec_b);
  if (res != 0) {
    res_not_equal = 1;
  }
  return res_not_equal;
}

int s21_is_equal(s21_decimal dec_a, s21_decimal dec_b) {
  int res_equal = 0;
  int res = 9;
  res = rb_pak(dec_a, dec_b);
  if (res == 0) {
    res_equal = 1;
  }
  return res_equal;
}

int s21_is_greater(s21_decimal dec_a, s21_decimal dec_b) {
  int res_greater = 0;
  int res = 9;
  res = rb_pak(dec_a, dec_b);
  if (res == 2) {
    res_greater = 1;
  }
  return res_greater;
}

int s21_is_greater_or_equal(s21_decimal dec_a, s21_decimal dec_b) {
  int res_greater_or_equal = 0;
  int res = 9;
  res = rb_pak(dec_a, dec_b);
  if (res == 2 || res == 0) {
    res_greater_or_equal = 1;
  }
  return res_greater_or_equal;
}

int s21_is_less_or_equal(s21_decimal dec_a, s21_decimal dec_b) {
  int res_less_or_equal = 0;
  int res = 9;
  res = rb_pak(dec_a, dec_b);
  if (res == 1 || res == 0) {
    res_less_or_equal = 1;
  }
  return res_less_or_equal;
}

int s21_is_less(s21_decimal dec_a, s21_decimal dec_b) {
  int res_less = 0;
  int res = 9;
  res = rb_pak(dec_a, dec_b);
  if (res == 1) {
    res_less = 1;
  }
  return res_less;
}

//====================CAST FUNCTIONS==========================

int getFSign(float *src) { return *(int *)src >> 31; }

int getFExp(float *src) { return (*(int *)src >> 23 & ~(1 << 31)) - 127; }

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
  int result = 0, sign = getFSign(&src), exp;
  if (isinf(src) || isnan(src)) {
    result = 1;
  } else if (!isinf(src) && !isnan(src) && dst && src != 0) {
    double tmp = (double)fabs(src);
    float t = fabs(src);
    exp = getFExp(&t);
    int scale = 0;
    while (scale < 28 && (int)tmp / (int)pow(2, 21) == 0) {
      tmp *= 10;
      scale++;
    }
    tmp = (float)round(tmp);
    if (scale <= 28 && exp < 96 && exp > -94) {
      while (fmod(tmp, 10) == 0 && scale > 0) {
        tmp /= 10;
        scale--;
      }
      float temp = tmp;
      exp = getFExp(&temp);
      dst->bits[exp / 32] |= 1 << exp % 32;
      for (int i = 0; i < 96 && (int)temp > 0.0; i++) {
        if (((int)temp % 2) != 0) dst->bits[i / 32] |= 1 << i % 32;
        temp /= 2;
      }
      dst->bits[3] |= (sign == -1) ? 1 << 31 : 0;
      dst->bits[3] |= scale << 16;
      result = 1;
    }
  }

  return result;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int sign = src.bits[3] >> 31 ? -1 : 1;
  double tmp = 0.0;
  int scale = src.bits[3] >> 16 & ~(1 << 15);
  for (int i = 0; i < 96; i++)
    if ((src.bits[i / 32] & (1 << i % 32)) != 0) tmp += pow(2, i);
  for (int i = scale; i > 0; i--) tmp /= 10.0;
  *dst = (float)tmp * sign;
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  s21_decimal tmp = {{0, 0, 0, 0}};
  int sign = get_sign(src);
  s21_truncate(src, &tmp);
  unsigned int last_bit = get_bit_x1(tmp, 31);
  if (tmp.bits[1] != 0 || tmp.bits[2] != 0 || last_bit != 0) {
    error = 1;
  } else {
    *dst = tmp.bits[0];

    if (sign) {
      *dst *= (-1);
    }
  }

  return error;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if ((src != NAN) && (dst != NULL)) {
    int negate = (src < 0) ? 1 : 0;
    src = abs(src);
    dst->bits[0] = src;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    if (negate) set_bit_X1(dst, 127, 1);
  } else
    error = 1;

  return error;
}

//==========================================================================

int s21_negate(s21_decimal value, s21_decimal *result) {
  result->bits[3] = value.bits[3];
  result->bits[2] = value.bits[2];
  result->bits[1] = value.bits[1];
  result->bits[0] = value.bits[0];
  if (get_bit_x1(value, 127) == 0) {
    set_bit_X1(result, 127, 1);
  } else {
    set_bit_X1(result, 127, 0);
  }
  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  unsigned int sign = get_sign(value);
  s21_decimal_x2 norm_a = {
      {value.bits[0], value.bits[1], value.bits[2], 0, 0, 0, value.bits[3]}};
  int k = !!get_bit_x1(value, 127);
  unsigned step = get_stepen(value);
  int flag = 0;
  flag = otkat_truncate(&norm_a, step);
  result->bits[3] = norm_a.bits[6];
  result->bits[2] = norm_a.bits[2];
  result->bits[1] = norm_a.bits[1];
  result->bits[0] = norm_a.bits[0];
  if (flag == 0) {
    set_bit_X1(result, 127, k);
  }
  set_sign(result, sign);
  return 0;
}

int otkat_truncate(s21_decimal_x2 *norm_c, int stepen) {
  int value = 0;
  s21_decimal_x2 div_on_10 = {{10, 0, 0, 0, 0, 0, 0}};
  int flag = 0;
  for (int i = 0; i < 193; i++) {
    if (get_bit(*norm_c, i) != 0) {
      value = 2;
      break;
    }
  }
  if (value == 2) {
    while (stepen > 0) {
      *norm_c = s21_func_div(*norm_c, div_on_10);
      stepen--;
    }
  } else {
    for (int i = 0; i < 7; i++) {
      norm_c->bits[i] = 0;
      flag = 1;
    }
  }
  return flag;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0;
  s21_decimal one = {{1, 0, 0, 0}};
  unsigned sign = 9;
  sign = get_sign(value);

  s21_truncate(value, result);

  int is_zeroV = 0;
  is_zeroV = is_decimal_zero(&value);
  unsigned int scale = 0;
  scale = get_stepen(value);
  int is_zeroR = 0;
  is_zeroR = is_decimal_zero(result);
  if ((sign && !is_zeroR && scale) || (sign && !is_zeroV && scale)) {
    set_sign(result, 0);
    s21_add(*result, one, result);
  }
  set_sign(result, sign);
  return error;
}

int is_decimal_zero(s21_decimal *src) {
  int is_zero = 0;
  if (src->bits[0] == 0 && src->bits[1] == 0 && src->bits[2] == 0) {
    is_zero = 1;
  }
  return is_zero;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal five = {{5, 0, 0, 0}};
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal rest = {{0, 0, 0, 0}};
  s21_decimal tmp10 = {{0, 0, 0, 0}};
  s21_decimal tmp = {{0, 0, 0, 0}};
  unsigned int sign = 9;
  sign = get_sign(value);
  set_sign(&value, 0);
  s21_truncate(value, &tmp);
  unsigned int scale = 0;
  scale = get_stepen(value);

  if (scale != 0) {
    set_cexp(&value, (scale - 1));
    s21_truncate(value, &tmp10);

    for (int i = 0; i < 10; i++) {
      s21_sub(tmp10, tmp, &rest);
      tmp10 = rest;
    }

    int x = s21_is_greater_or_equal(rest, five);
    if (x == 1) {
      s21_add(tmp, one, result);
    } else {
      result->bits[0] = tmp.bits[0];
      result->bits[1] = tmp.bits[1];
      result->bits[2] = tmp.bits[2];
    }
  } else {
    result->bits[0] = tmp.bits[0];
    result->bits[1] = tmp.bits[1];
    result->bits[2] = tmp.bits[2];
  }
  set_sign(result, sign);

  return 0;
}

//===============================================================================
