#include <check.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./s21_string.h"

#define BUFF_SIZE 512

/* -----===== PART-1 =====----- */
/* -----===== START =====----- */
START_TEST(strlen_1) {
  char *str_1 = "LUGANO\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_2) {
  char *str_2 = "LUGANO THE \0BEST!!!";
  ck_assert_int_eq(strlen(str_2), s21_strlen(str_2));
}
END_TEST

START_TEST(strlen_3) {
  char *str_3 = "\0";
  ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

START_TEST(strcat_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcat(b1, str_1_2), s21_strcat(b11, str_1_2));
}
END_TEST

START_TEST(strcat_2) {
  char b2[1024] = "THE";
  char b22[1024] = "THE";
  char str_2_2[1024] = " BEST!!";
  ck_assert_pstr_eq(strcat(b2, str_2_2), s21_strcat(b22, str_2_2));
}
END_TEST

START_TEST(strcat_3) {
  char b3[1024] = "777";
  char b33[1024] = "777";
  char str_3_2[1024] = " LUGANO!";
  ck_assert_pstr_eq(strcat(b3, str_3_2), s21_strcat(b33, str_3_2));
}
END_TEST

START_TEST(strcmp_1) {
  char *str_1_1 = "LUGANO!";
  char *str_1_2 = "LUGANO!";
  int s21_c = s21_strcmp(str_1_1, str_1_2);
  int s_c = strcmp(str_1_1, str_1_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_2) {
  char *str_2_1 = "LUGANO THE BEST!";
  char *str_2_2 = "LUGANO OF THE BEST!";
  int s21_c = s21_strcmp(str_2_1, str_2_2);
  int s_c = strcmp(str_2_1, str_2_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_3) {
  char *str_3_1 = "LUGANO OF THE BEST!!!!!";
  char *str_3_2 = "LUGANO!";
  int s21_c = s21_strcmp(str_3_1, str_3_2);
  int s_c = strcmp(str_3_1, str_3_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_int_1) {
  char *str_1_1 = "LUGANO!";
  char *str_1_2 = "LUGANO!";
  int s21_c = s21_strcmp_int(str_1_1, str_1_2);
  int s_c = strcmp(str_1_1, str_1_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_int_2) {
  char *str_2_1 = "LUGANO THE BEST!";
  char *str_2_2 = "LUGANO OF THE BEST!";
  int s21_c = s21_strcmp_int(str_2_1, str_2_2);
  int s_c = strcmp(str_2_1, str_2_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_int_3) {
  char *str_3_1 = "LUGANO OF THE BEST!!!!!";
  char *str_3_2 = "LUGANO!";
  int s21_c = s21_strcmp_int(str_3_1, str_3_2);
  int s_c = strcmp(str_3_1, str_3_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncat_1) {
  s21_size_t n1 = 2;
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strncat(b1, str_1_2, n1), s21_strncat(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncat_2) {
  s21_size_t n2 = 2;
  char b2[1024] = "THE";
  char b22[1024] = "THE";
  char str_2_2[1024] = " BEST!!";
  ck_assert_pstr_eq(strncat(b2, str_2_2, n2), s21_strncat(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncat_3) {
  s21_size_t n3 = 2;
  char b3[1024] = "777";
  char b33[1024] = "777";
  char str_3_2[1024] = " LUGANO!";
  ck_assert_pstr_eq(strncat(b3, str_3_2, n3), s21_strncat(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncmp_1) {
  s21_size_t n = 3;
  char *str_1_1 = "LUGANO!";
  char *str_1_2 = "LUGANO!";
  int s21_c = s21_strncmp(str_1_1, str_1_2, n);
  int s_c = strncmp(str_1_1, str_1_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_2) {
  s21_size_t n = 3;
  char *str_2_1 = "LUGANO THE BEST!";
  char *str_2_2 = "LU GANO OF THE BEST!!";
  int s21_c = s21_strncmp(str_2_1, str_2_2, n);
  int s_c = strncmp(str_2_1, str_2_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_3) {
  s21_size_t n = 3;
  char *str_3_1 = " LUGANO OF THE BEST!!";
  char *str_3_2 = "LUGANO!";
  int s21_c = s21_strncmp(str_3_1, str_3_2, n);
  int s_c = strncmp(str_3_1, str_3_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(memcmp_1) {
  s21_size_t n1 = 3;
  void *str_1_1 = "LUGANO!";
  void *str_1_2 = "LUGANO!";
  ck_assert_int_eq(memcmp(str_1_1, str_1_2, n1),
                   s21_memcmp(str_1_1, str_1_2, n1));
}
END_TEST

START_TEST(memcmp_2) {
  s21_size_t n2 = 3;
  void *str_2_1 = "LUGANO THE BEST!";
  void *str_2_2 = "LU GANO OF THE BEST!!";
  ck_assert_int_eq(memcmp(str_2_1, str_2_2, n2),
                   s21_memcmp(str_2_1, str_2_2, n2));
}
END_TEST

START_TEST(memcmp_3) {
  s21_size_t n3 = 3;
  void *str_3_1 = " LUGANO OF THE BEST!!";
  void *str_3_2 = "LUGANO!";
  ck_assert_int_eq(memcmp(str_3_1, str_3_2, n3),
                   s21_memcmp(str_3_1, str_3_2, n3));
}
END_TEST

START_TEST(memset_1) {
  s21_size_t n1 = 6;
  int c1 = '7';
  char b1[1024] = "LUGANO THE BEST!";
  char b11[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memset(b1, c1, n1), s21_memset(b11, c1, n1));
}
END_TEST

START_TEST(memset_2) {
  s21_size_t n2 = 4;
  int c2 = '4';
  char b2[1024] = " BEST!!";
  char b22[1024] = " BEST!!";
  ck_assert_pstr_eq(memset(b2, c2, n2), s21_memset(b22, c2, n2));
}
END_TEST

START_TEST(memset_3) {
  s21_size_t n3 = 6;
  int c3 = '3';
  char b3[1024] = " LUGANO!";
  char b33[1024] = " LUGANO!";
  ck_assert_pstr_eq(memset(b3, c3, n3), s21_memset(b33, c3, n3));
}
END_TEST

START_TEST(strcpy_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcpy(b1, str_1_2), s21_strcpy(b11, str_1_2));
}
END_TEST

START_TEST(strcpy_2) {
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0BEST!!";
  ck_assert_pstr_eq(strcpy(b2, str_2_2), s21_strcpy(b22, str_2_2));
}
END_TEST

START_TEST(strcpy_3) {
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "LUGANO!";
  ck_assert_pstr_eq(strcpy(b3, str_3_2), s21_strcpy(b33, str_3_2));
}
END_TEST

START_TEST(strncpy_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "1111111111";
  char b11[1024] = "1111111111";
  char str_1_2[1024] = "123\0";
  ck_assert_pstr_eq(strncpy(b1, str_1_2, n1), s21_strncpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncpy_2) {
  s21_size_t n2 = 5;
  char b2[1024] = "1111111111";
  char b22[1024] = "1111111111";
  char str_2_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b2, str_2_2, n2), s21_strncpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncpy_3) {
  s21_size_t n3 = 5;
  char b3[1024] = "11";
  char b33[1024] = "11";
  char str_3_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b3, str_3_2, n3), s21_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(memcpy_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memcpy(b1, str_1_2, n1), s21_memcpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(memcpy_2) {
  s21_size_t n2 = 5;
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0BEST!!";
  ck_assert_pstr_eq(memcpy(b2, str_2_2, n2), s21_memcpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(memcpy_3) {
  s21_size_t n3 = 4;
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "LUGANO!";
  ck_assert_pstr_eq(memcpy(b3, str_3_2, n3), s21_memcpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(memcpy_4) {
  s21_size_t n4 = 4;
  char b4[1024] = "LUGANO! 777 ";
  char b44[1024] = "LUGANO! 777 ";
  ck_assert_pstr_eq(memcpy(b4, b4 + 7, n4), s21_memcpy(b44, b44 + 7, n4));
}
END_TEST

START_TEST(memmove_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "LUGANO THE BEST!";
  char b11[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memmove(b1, b1 + 5, n1), s21_memmove(b11, b1 + 5, n1));
}
END_TEST

START_TEST(memmove_2) {
  s21_size_t n2 = 4;
  char b2[1024] = "777 9999999";
  char b22[1024] = "777 9999999";
  ck_assert_pstr_eq(memmove(b2, b2, n2), s21_memmove(b22, b2, n2));
}
END_TEST

START_TEST(memmove_3) {
  s21_size_t n3 = 4;
  char b3[1024] = "777 LUGANO!";
  char b33[1024] = "777 LUGANO!";
  ck_assert_pstr_eq(memmove(b3, b3, n3), s21_memmove(b33, b33, n3));
}
END_TEST

START_TEST(memmove_4) {
  s21_size_t n4 = 4;
  char b4[1024] = "777 LUGANO!";
  char b44[1024] = "777 LUGANO!";
  ck_assert_pstr_eq(memmove(b4, b4, n4), s21_memmove(b44, b44, n4));
}
END_TEST

START_TEST(memchr_1) {
  char str[] = "Hello w\0orld\0";
  ck_assert_pstr_eq(memchr(str, 'r', 5), s21_memchr(str, 'r', 5));
}
END_TEST

START_TEST(memchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(memchr(str2, 's', 6), s21_memchr(str2, 's', 6));
}
END_TEST

START_TEST(memchr_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', '\0'};
  ck_assert_pstr_eq(memchr(str3, 's', 5), s21_memchr(str3, 's', 5));
}
END_TEST

START_TEST(strchr_1) {
  char str[] = "Hello world";
  ck_assert_pstr_eq(strchr(str, ' '), s21_strchr(str, ' '));
}
END_TEST

START_TEST(strchr_2) {
  char str2[] = "john.smith\0@microsoft.com";
  ck_assert_pstr_eq(strchr(str2, 'm'), s21_strchr(str2, 'm'));
}
END_TEST

START_TEST(strchr_3) {
  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strchr(str3, 'h'), s21_strchr(str3, 'h'));
}
END_TEST

START_TEST(strrchr_1) {
  char str[] = "0163456769";
  ck_assert_pstr_eq(strrchr(str, '6'), s21_strrchr(str, '6'));
}
END_TEST

START_TEST(strrchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str2, 'o'), s21_strrchr(str2, 'o'));
}
END_TEST

START_TEST(strrchr_3) {
  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str3, 'h'), s21_strrchr(str3, 'h'));
}
END_TEST

START_TEST(strrchr_4) {
  char str4[] = "";
  ck_assert_pstr_eq(strrchr(str4, 'd'), s21_strrchr(str4, 'd'));
}
END_TEST

START_TEST(strrchr_5) {
  char str5[] = {""};
  ck_assert_pstr_eq(strrchr(str5, 'z'), s21_strrchr(str5, 'z'));
}
END_TEST

START_TEST(strcspn_1) {
  char str1[] = "this is a test";
  ck_assert_int_eq(strcspn(str1, "ab"), s21_strcspn(str1, "ab"));
}
END_TEST

START_TEST(strcspn_2) {
  char str2[] = "LOST: 4-8-15-16-23-42";
  ck_assert_int_eq(strcspn(str2, "1234567890"),
                   s21_strcspn(str2, "1234567890"));
}
END_TEST

START_TEST(strcspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_int_eq(strcspn(str3, "zx"), s21_strcspn(str3, "zx"));
}
END_TEST

START_TEST(strspn_1) {
  char str[] = "12-years";
  ck_assert_int_eq(strspn(str, "1234567890"), s21_strspn(str, "1234567890"));
}
END_TEST

START_TEST(strspn_2) {
  char str2[] = "this is a test";
  ck_assert_int_eq(strspn(str2, "shit "), s21_strspn(str2, "shit "));
}
END_TEST

START_TEST(strspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's'};
  ck_assert_int_eq(strspn(str3, "01234"), s21_strspn(str3, "01234"));
}
END_TEST

START_TEST(strpbrk_1) {
  char str[] = "this_is_a_";
  ck_assert_pstr_eq(strpbrk(str, "369"), s21_strpbrk(str, "369"));
}
END_TEST

START_TEST(strpbrk_2) {
  char str2[] = "john.smith@mic\0rosoft.com";
  ck_assert_pstr_eq(strpbrk(str2, "fzx"), s21_strpbrk(str2, "fzx"));
}
END_TEST

START_TEST(strpbrk_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strpbrk(str3, "saq"), s21_strpbrk(str3, "saq"));
}
END_TEST

START_TEST(strstr_1) {
  char str[] = "";
  ck_assert_pstr_eq(strstr(str, ""), s21_strstr(str, ""));
}
END_TEST

START_TEST(strstr_2) {
  char str2[] = "john.smith@mic\0rosoft.com";
  ck_assert_pstr_eq(strstr(str2, "sm"), s21_strstr(str2, "sm"));
}
END_TEST

START_TEST(strstr_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strstr(str3, "woo"), s21_strstr(str3, "woo"));
}
END_TEST

START_TEST(strerror_1) {
  int err_num = 7;
  ck_assert_pstr_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST

START_TEST(strerror_2) {
  int err_num2 = 1;
  ck_assert_pstr_eq(strerror(err_num2), s21_strerror(err_num2));
}
END_TEST

START_TEST(strerror_3) {
  int err_num3 = 404;
  ck_assert_pstr_eq(strerror(err_num3), s21_strerror(err_num3));
}
END_TEST

START_TEST(strerror_4) {
  int err_num4 = 0;
  ck_assert_pstr_eq(strerror(err_num4), s21_strerror(err_num4));
}
END_TEST

START_TEST(strtok_1) {
  char str4_1[] = "/testing/with/original/string.h/";
  char str4_2[] = "/testing/with/original/string.h/";
  char del4[3] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_2) {
  char str4_1[] = ". . testing with original string.h";
  char str4_2[] = ". . testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_3) {
  char str4_1[] = "testing with original string.h";
  char str4_2[] = "testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

/* -----===== PART-1 =====----- */
/* -----===== FINISH =====----- */

/* -----===== PART-2 =====----- */
/* -----===== START =====----- */
// strlen ->
START_TEST(strlen_empty) {
  char src[] = "";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_abosal) {
  char src[] = "abosal";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_num) {
  char src[] = "987623456124678";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_string) {
  char src[] =
      "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_abosal_no_dal) {
  char src[] = "abosal\0no_dal";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_dai_mne_pen) {
  char src[] = "dai_mne_pen(321321)...123...123";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_Floppy_disk) {
  char src[] = "Floppy_disk";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_Russky_kot_Shlepa) {
  char src[] = "Russky_kot_Shlepa";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_kot_Vasily) {
  char src[] = "kot Vasily";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_floppa) {
  char src[] = "floppa";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
// strlen <-

// strncat ->
START_TEST(strncat_all_empty) {
  char src[] = "";
  char res[] = "";
  char expected[] = "";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_zero_byte) {
  char src[] = "abosal";
  char res[10] = "";
  char expected[10] = "";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_empty_src) {
  char src[] = "";
  char res[10] = "cd";
  char expected[10] = "cd";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_cd_abosa) {
  char src[] = "abosal";
  char res[10] = "cd";
  char expected[10] = "cd";
  s21_size_t n_byte = 5;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_string) {
  char src[] = "abosal";
  char res[25] = "koleka";
  char expected[25] = "koleka";
  s21_size_t n_byte = 6;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 5;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA2) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA3) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA4) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 10;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_zero_char) {
  char src[] = "\0";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST
// strncat <-

// strncmp ->
START_TEST(strncmp_empty) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_) {
  char str1[] = "floppa";
  char str2[] = "";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp__floppa) {
  char str1[] = "";
  char str2[] = "floppa";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_floppa) {
  char str1[] = "floppa";
  char str2[] = "floppa";
  s21_size_t n_byte = 6;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_floppa_zero_byte) {
  char str1[] = "floppabazbazkotya";
  char str2[] = "floppabaz";
  s21_size_t n_byte = 10;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_floppa_one_byte) {
  char str1[] = "floppa";
  char str2[] = "floppa";
  s21_size_t n_byte = 1;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
// strncmp <-

// strrchr ->
START_TEST(strrchr_empty) {
  char str1[] = "";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_floppy_) {
  char str1[] = "floppy";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr__floppy) {
  char str1[] = "";
  char str2 = 'f';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_o) {
  char str1[] = "poki doki";
  char str2 = 'o';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_i) {
  char str1[] = "poki doki";
  char str2 = 'i';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_p) {
  char str1[] = "poki p dokip";
  char str2 = 'p';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_find_big_P) {
  char str1[] = "ppPpppppppppP";
  char str2 = 'P';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_find_zero) {
  char str1[] = "123456789";
  char str2 = '0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
// strrchr <-

// strpbrk ->
START_TEST(strpbrk_empty) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_floppy_) {
  char str1[] = "floppy";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk__floppy) {
  char str1[] = "";
  char str2[] = "floppy";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_poki_doki_o) {
  char str1[] = "poki doki";
  char str2[] = "o";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_poki_doki_i) {
  char str1[] = "poki doki";
  char str2[] = "i";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_poki_doki_p) {
  char str1[] = "poki doki";
  char str2[] = "p";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_find_big_P) {
  char str1[] = "ppppppppppppP";
  char str2[] = "P";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_find_zero) {
  char str1[] = "ppppppppppppP";
  char str2[] = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
// strpbrk <-

// strspn ->
START_TEST(strspn_empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_gora_) {
  char src[] = "gora";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn__gora) {
  char src[] = "";
  char res[] = "gora";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_register) {
  char src[] = "gora";
  char res[] = "gOra";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_num) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_long_num_num) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_long_num) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_basic_test) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST
// strspn <-

// strstr ->
START_TEST(strstr_empty_string_haystack_and_needle) {
  char haystack[] = "";
  char needle[] = "";
  ck_assert_pstr_eq(strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// TODO - fix test case
//  START_TEST(strstr_empty_string_haystack) {
//      char haystack[] = "";
//      char needle[] = "jho1faQsdkjnSa3aefwf8hiuJafeHioj";
//      ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack,
//      needle));
//  } END_TEST

START_TEST(strstr_empty_string_needle) {
  char haystack[] = "safQhilufas7MaSef2345wknwefnkjHawe2fhilu";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_toxic_test) {
  char haystack[] = "You are toxic!";
  char needle[] = "toxic";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_not_word_in_haystack) {
  char haystack[] = "There is no right word in this test!";
  char needle[] = "NOT";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_words_with_any_register) {
  char haystack[] = "AbOBosNyTSa";
  char needle[] = "aBoboSNYTsa";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_repeated_words) {
  char haystack[] = "AD AD AD";
  char needle[] = "AD";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_word_at_end) {
  char haystack[] = "22 321 123";
  char needle[] = "123";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_one_simbol_in_needle_and_haystack) {
  char haystack[] = "1";
  char needle[] = "1";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_one_simbol_in_needle) {
  char haystack[] =
      "13625523478437263475984675342345sdghyftrg freshtsyASFWEt wEafe";
  char needle[] = " ";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// TODO fix test case
// START_TEST(strstr_one_simbol_in_haystack) {
//     char haystack[] = "-";
//     char needle[] = "1234567890qwertyuiopasdfghjk-";
//     ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack,
//     needle));
// } END_TEST
// // strstr <-

// strtok ->
START_TEST(strtok_correct_token_string) {
  char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
  char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_token_string) {
  char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_unary_delimiters) {
  char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_no_delims) {
  char str1[] = "AbobaHasNoDelims";
  char str2[] = "AbobaHasNoDelims";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_only_delims) {
  char str1[] = "++++++++";
  char str2[] = "++++++++";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_ptr_null(got);
  ck_assert_ptr_null(expected);
}
END_TEST

START_TEST(strtok_too_many_uses_non_segfault) {
  char str1[] = "Aboba_Floppa_Roba";
  char str2[] = "Aboba_Floppa_Roba";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  int i = 5;
  while (i) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    i--;
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_even_n_of_delims) {
  char str1[] = "Roba++++Kepa++A++++B__V";
  char str2[] = "Roba++++Kepa++A++++B__V";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_odd_n_of_delims) {
  char str1[] = "Aboba__+Floppa_  Roba";
  char str2[] = "Aboba__+Floppa_  Roba";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_n_of_delims) {
  char str1[] = "Aboba__Floppa_+++Roba_Kepa";
  char str2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_mixed) {
  char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_hard_incorrect) {
  char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_very_hard_mixed) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
// strtok <-

// strncpy ->
START_TEST(strncpy_empty) {
  char src[] = "";
  char res[] = "";
  char exp[] = "";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_zero_byte) {
  char src[] = "123";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_empty_src) {
  char src[] = "";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_one_byte) {
  char src[] = "123";
  char res[5] = "123";
  char exp[5] = "123";
  s21_size_t n_byte = 1;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_two_byte) {
  char src[] = "123";
  char res[7] = "123";
  char exp[7] = "123";
  s21_size_t n_byte = 2;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_string) {
  char src[] = "Str1ng";
  char res[7 + 7] = "Str1ng";
  char exp[7 + 7] = "Str1ng";
  s21_size_t n_byte = 7;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST
// strncpy <-

// strerror ->
START_TEST(strerror_all_std_errors) {
  for (int i = -1000; i < 150; i++) {
    char *got = s21_strerror(i);
    char *expected = strerror(i);
    ck_assert_str_eq(got, expected);
  }
}
END_TEST

START_TEST(strerror_negative_err_code) {
  const char *got = s21_strerror(-1);
  char *expected = strerror(-1);
  ck_assert_str_eq(got, expected);
}
END_TEST
// strerror <-

// strcspn ->
START_TEST(strcspn_empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_gora_) {
  char src[] = "gora";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn__gora) {
  char src[] = "";
  char res[] = "gora";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_register) {
  char src[] = "gora";
  char res[] = "gOra";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_num) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_long_num_num) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_long_num) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_basic_test) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
// strcspn <-

// strcmp ->
START_TEST(strcmp_Heloboba_Heloboba) {
  char a[] = "Heloboba";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_HEloboba_Heloboba) {
  char a[] = "HEloboba";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Hel0boba_Helob0ba) {
  char a[] = "Hel0boba";
  char b[] = "Helob0ba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Heloboba_) {
  char a[] = "Heloboba";
  char b[] = "";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp__Heloboba) {
  char a[] = "";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Heloboba) {
  char a[] = "L(8)L";
  char b[] = "L(8)L";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_empty) {
  char a[] = "";
  char b[] = "";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_only_num) {
  char a[] = "1234567890";
  char b[] = "1234567890";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
// strcmp <-

// strchr ->
START_TEST(strchr_abobasnutsa_find_a) {
  char src[] = "abobasnutsa";
  char find = 'a';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_abobasnutAsa_find_A) {
  char src[] = "abobasnutAsa";
  char find = 'A';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_abobasnutA1sa_find_1) {
  char src[] = "abobasnutA1sa";
  char find = '1';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_abobasnutAsa_find_Z) {
  char src[] = "abobasnutAsa";
  char find = 'Z';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_abobasnutAsa_find_3) {
  char src[] = "abobasnutAsa";
  char find = '3';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_empty_src) {
  char src[] = "";
  char find = '3';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
// strchr <-

// strcpy ->
START_TEST(strcpy_aboba_floppa) {
  char src[] = " floppa!!!";
  char res[5 + 15] = "aboba ";
  char expected[5 + 15] = "aboba ";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy__floppa) {
  char src[] = "Floppa!!!";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_aboba_) {
  char src[] = "";
  char res[5 + 15] = "abobas";
  char expected[5 + 15] = "abobas";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_empty) {
  char src[] = "";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_empty_num) {
  char src[] = "1";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_hello) {
  char src[] = " my dear friend\"";
  char res[5 + 15] = "Hello";
  char expected[5 + 15] = "Hello";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_over_string) {
  char src[] = "ab\0ba";
  char res[10 + 9] = "Gre\0t";
  char expected[10 + 9] = "Gre\0t";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_hard_test) {
  char src[] = "ad[sofijpoiajsdf pj98981h23 p9h floppa!!!";
  char res[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
  char expected[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST
// strcpy <-

// strcat ->
START_TEST(strcat_Hello_aboba) {
  char src[] = " aboba!!!";
  char res[5 + 10] = "Hello";
  char expected[5 + 10] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_zero_first) {
  char src[] = " aboba!!!";
  char res[0 + 10] = "";
  char expected[0 + 10] = "";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_zero_last) {
  char src[] = "";
  char res[] = "Hello";
  char expected[] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register) {
  char src[] = "asdfj  asdf aisdfjaiushdfASD SAD asDSad ASDAsdwqqeAS";
  char res[5 + 53] = "Hello";
  char expected[5 + 53] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register_and_num) {
  char src[] = "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS";
  char res[5 + 59] = "Hello";
  char expected[5 + 59] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register_and_num_and_sim) {
  char src[] =
      "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS)(?!.,";
  char res[5 + 65] = "Hello";
  char expected[5 + 65] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST
// strcat <-

// memcpy ->
START_TEST(memcpy_hate_test) {
  char src[] = "i hate memcmp";
  s21_size_t kByte = 12;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string) {
  char src[] = "aboba";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_any_empty) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string_with_register) {
  char src[] = "I hate memcmp";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_num) {
  char src[] = "123";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string) {
  char src[] = "aboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string_with_register) {
  char src[] = "Zboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_num) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_basic_long_string) {
  char src[] = "abobasdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num_and_simbol) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
// memcpy <-

// memmove ->
START_TEST(memmove_empty_dest_and_src) {
  char src[200] = "";
  char src2[200] = "";
  s21_size_t copy_kByte = 0;
  char *res = src;
  char *expected = src2;
  s21_size_t check_kByte = 0;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_empty_dest) {
  char src[200] = "123SDFAZ`ESFsdfsdf";
  char src2[200] = "123SDFAZ`ESFsdfsdf";
  s21_size_t copy_kByte = 10;
  char res[200] = "";
  char expected[200] = "";
  s21_size_t check_kByte = 10;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_empty_src) {
  char src[200] = "";
  char src2[200] = "";
  s21_size_t copy_kByte = 0;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_size_t check_kByte = 13;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_write_in_left) {
  char src[200] = "Hate";
  char src2[200] = "Hate";
  s21_size_t copy_kByte = 4;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_size_t check_kByte = 17;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_write_in_right) {
  char src[200] = "Hate";
  char src2[200] = "Hate";
  s21_size_t copy_kByte = 4;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_size_t check_kByte = 17;
  s21_memmove(res + 13, src, copy_kByte);
  memmove(expected + 13, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_write_in_mid) {
  char src[200] = "Hate";
  char src2[200] = "Hate";
  s21_size_t copy_kByte = 4;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_size_t check_kByte = 17;
  s21_memmove(res + 5, src, copy_kByte);
  memmove(expected + 5, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_overlap_write_in_left) {
  char src[200] = "I HATE memmove!!!";
  char src2[200] = "I HATE memmove!!!";
  s21_size_t copy_kByte = 17;
  char *res = src;
  char *expected = src2;
  s21_size_t check_kByte = 34;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_overlap_write_in_right) {
  char src[200] = "I HATE memmove!!!";
  char src2[200] = "I HATE memmove!!!";
  s21_size_t copy_kByte = 17;
  char *res = src + 17;
  char *expected = src2 + 17;
  s21_size_t check_kByte = 34;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_overlap_write_in_mid) {
  char src[200] = "I HATE memmove!!!";
  char src2[200] = "I HATE memmove!!!";
  s21_size_t copy_kByte = 17;
  char *res = src + 5;
  char *expected = src2 + 5;
  s21_size_t check_kByte = 34;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_zero_test_string) {
  char src[] = "aboba";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_any_empty) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_zero_test_string_with_register) {
  char src[] = "I hate memcmp";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_zero_test_num) {
  char src[] = "123";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_one_byte_string) {
  char src[] = "aboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_one_byte_string_with_register) {
  char src[] = "Zboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_one_byte_num) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_basic_long_string) {
  char src[] = "abobasdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_string_with_register) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_string_with_register_and_num) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_string_with_register_and_num_and_simbol) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_ints) {
  int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t kByte = 4;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_floats) {
  float src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t kByte = 8;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_doubels) {
  long double src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t kByte = 16;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
// memmove <-

// memset ->
START_TEST(memset_aboba_test) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'g';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_zero_byte) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'g';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_empty) {
  char res[] = "";
  char expected[] = "";
  char replace = '\0';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_sim) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'A';
  s21_size_t n_byte = 3;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_num) {
  char res[] = "a1obA";
  char expected[] = "a1obA";
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_long_string) {
  char res[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char expected[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST
// memset <-

// memcmp ->
START_TEST(memcmp_zero_byte) {
  char str1[] = "aboba";
  char str2[] = "aboba";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_first_byte_in_string) {
  char str1[] = "aboba";
  char str2[] = "aboba";
  int n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_register_test) {
  char str1[] = "aboba";
  char str2[] = "Aboba";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_zero_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_first_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1234";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_in_num) {
  char str1[] = "1234";
  char str2[] = "1234";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_long_two_num) {
  char str1[] = "13";
  char str2[] = "1234";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_long_first_num) {
  char str1[] = "134567";
  char str2[] = "1234";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_eq_long_string) {
  char str1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  int n = 71;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_not_eq_long_string) {
  char str1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASd";
  int n = 71;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
// memcmp <-

// memchr ->
START_TEST(memchr_empty_str) {
  s21_size_t n_byte = 0;
  char str[10] = "";
  int find_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_zero_in_string) {
  s21_size_t n_byte = 7;
  char str[10] = "string";
  int find_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_simbol_in_string_in_start) {
  s21_size_t n_byte = 6;
  char str[10] = "Atring";
  int find_byte = 'A';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_simbol_in_string_in_end) {
  s21_size_t n_byte = 7;
  char str[10] = "StringA";
  int find_byte = 'A';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_num_in_string_in_mid) {
  s21_size_t n_byte = 15;
  char str[16] = "Str55333222ingA";
  int find_byte = '3';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_num_in_array_num) {
  int array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(int) * 7;
  int find_byte = 666;
  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_float_in_array) {
  float array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(float) * 7;
  int find_byte = 666;
  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_easy_test_string) {
  s21_size_t n_byte = 5;
  char str[10] = "aboba";
  int find_byte = 'c';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST
// memchr <-

/* ------===== This part for testing sprintf and sscanf =====------ */
/* ------=====                   START                  =====------ */

// sprintf ->

START_TEST(sprintf_simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_octal_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.51o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST*/

START_TEST(sprintf_octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_hex_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#-10x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST*/

START_TEST(sprintf_hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_hex_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#-10x%x%X%#x%#X%5.5x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
sprintf(str2, format, val, val, val, val, val, val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_hex_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#-5.10x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_hex_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#x";
    unsigned val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST*/

START_TEST(sprintf_hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_hex_one_longer_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#2x";
    unsigned val = 1;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_hex_two_longer_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#30x";
    unsigned val = 1;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST*/

START_TEST(sprintf_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_ptr) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%p";
    ck_assert_int_eq(s21_sprintf(str1, format, format), sprintf(str2, format,
format));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_ptr_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15p";
    ck_assert_int_eq(s21_sprintf(str1, format, format), sprintf(str2, format,
format));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_ptr_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5p";
    ck_assert_int_eq(s21_sprintf(str1, format, format), sprintf(str2, format,
format));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_null_ptr) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%p";
    char *ptr = s21_NULL;
    ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format,
ptr));

    ck_assert_str_eq(str1, str2);
} END_TEST*/

START_TEST(sprintf_string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_n_specifier) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    int ret = 0;
    char *format = "Hello, my sexy little aboba abobushka abobina %n";
    ck_assert_int_eq(s21_sprintf(str1, format, &ret), sprintf(str2, format,
&ret));

    ck_assert_str_eq(str1, str2);
} END_TEST*/

START_TEST(sprintf_float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.5f";
  double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%14f";
  double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0f";
  double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.f";
  double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15f";
  double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15f";
  double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%f";
  double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %f %f %lf %f";
  float val = 0;
  double val1 = 0;
  double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_e_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%.17Le";
    double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_e_precision_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%.0Le";
    double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_e_precision_empty) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%.Le";
    double val = 15.000009121;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST
START_TEST(sprintf_e_precision_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%.15Le";
    long double val = 0.000000000000000123;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_e_precision_huge_negative) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%.15Le";
    long double val = -15.35581134;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_e_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%Le";
    long double val = 72537572375.1431341;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_e_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%015E";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_e_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%15e";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_e_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "% .0e %.le %Le %e %le %Le";
    float val = 0;
    double val1 = 0;
    long double val2 = 3515315.153151;
    float val3 = 5.5;
    double val4 = 0.094913941;
    long double val5 = 95919539159.53151351131;
    ck_assert_int_eq(
        s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
        sprintf(str2, format, val, val1, val2, val3, val4, val5));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_E_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "%.17LE";
    long double val = 4134121;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
val));

    ck_assert_str_eq(str1, str2);
} END_TEST*/

START_TEST(sprintf_all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(sprintf_test_one_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_test_many_hex_lower) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
        sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_many_hex_upper) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
        sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
    ck_assert_str_eq(str1, str2);
} END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(sprintf_test_one_hex_lower_with_alignment_left) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
sprintf(str2, "%-3x", (unsigned)INT32_MIN)); ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX), sprintf(str2, "%-3x",
INT32_MAX)); ck_assert_str_eq(str1, str2); } END_TEST

START_TEST(sprintf_test_one_hex_lower_with_alignment_right) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
sprintf(str2, "%13x", (unsigned)INT32_MIN)); ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX), sprintf(str2, "%13x",
INT32_MAX)); ck_assert_str_eq(str1, str2); } END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_left) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN), sprintf(str2,
"%-60X", (unsigned)INT32_MIN)); ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX), sprintf(str2,
"%-60X", INT32_MAX)); ck_assert_str_eq(str1, str2); } END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_right) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
sprintf(str2, "%7X", (unsigned)INT32_MIN)); ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX), sprintf(str2, "%7X",
INT32_MAX)); ck_assert_str_eq(str1, str2); } END_TEST

START_TEST(sprintf_test_many_hex_lower_with_alignment) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
        sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_many_hex_upper_with_alignment) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(
        s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
        sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
    ck_assert_str_eq(str1, str2);
} END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(sprintf_test_one_hex_with_hashtag) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN), sprintf(str2, "%#x",
(unsigned)INT32_MIN)); ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX), sprintf(str2, "%#x",
INT32_MAX)); ck_assert_str_eq(str1, str2); } END_TEST

START_TEST(sprintf_test_one_hex_upper_with_hashtag) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN), sprintf(str2, "%#X",
(unsigned)INT32_MIN)); ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX), sprintf(str2, "%#X",
INT32_MAX)); ck_assert_str_eq(str1, str2); } END_TEST

START_TEST(sprintf_test_many_hex_lower_with_hashtag_and_alignm) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535,
                                 -13, -0, 123213123), sprintf(str2,
"%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_many_hex_upper_with_hashtag_and_alignm) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535,
                                 -13, -0, 123213123), sprintf(str2,
"%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
    ck_assert_str_eq(str1, str2);
} END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(sprintf_test_one_hex_lower_with_width_star) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN), sprintf(str2,
"%*x", 11, (unsigned)INT32_MIN)); ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0), sprintf(str2, "%*x", 11,
0)); ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX), sprintf(str2,
"%*x", 11, INT32_MAX)); ck_assert_str_eq(str1, str2); } END_TEST

START_TEST(sprintf_test_one_hex_upper_with_width_star) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN), sprintf(str2,
"%*X", 11, (unsigned)INT32_MIN)); ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0), sprintf(str2, "%*X", 11,
0)); ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX), sprintf(str2,
"%*X", 11, INT32_MAX)); ck_assert_str_eq(str1, str2); } END_TEST

START_TEST(sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0,
                                 -1, 199, -123978, 3, -1251), sprintf(str2,
"%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1, 199, -123978, 3, -1251));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_many_hex_upper_with_width_star) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0,
                                 -1, 199, -123978, 3, -1251), sprintf(str2,
"%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199, -123978, 3, -1251));
    ck_assert_str_eq(str1, str2);
} END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(sprintf_test_one_hex_lower_with_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    int a = s21_sprintf(str1, "%*.6x", 11, 0);
    int b = sprintf(str2, "%*.6x", 11, 0);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_one_hex_upper_with_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
    int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_many_hex_lower_with_precision_and_other) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    int a = s21_sprintf(
        str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
        4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
    int b = sprintf(
        str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
        4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_many_hex_upper_with_precision_and_other) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1,
                    "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
                    -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                    41, -41, 33),
        sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
                -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
                -41, 33));
    ck_assert_str_eq(str1, str2);
} END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(sprintf_test_one_hex_lower_with_length) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%hx", -11), sprintf(str2, "%hx",
(unsigned short)-11)); ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 0), sprintf(str2, "%hx", (unsigned
short)0)); ck_assert_str_eq(str1, str2); ck_assert_int_eq(s21_sprintf(str1,
"%hx", 11), sprintf(str2, "%hx", (unsigned short)11)); ck_assert_str_eq(str1,
str2); long unsigned int val = INT32_MAX; ck_assert_int_eq(s21_sprintf(str1,
"%lx", val), sprintf(str2, "%lx", val)); ck_assert_str_eq(str1, str2); long
unsigned int v = 0; ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2,
"%lx", v)); ck_assert_str_eq(str1, str2); } END_TEST

START_TEST(sprintf_test_one_hex_upper_with_length) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%hx", -11), sprintf(str2, "%hx",
(unsigned short)-11)); ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 0), sprintf(str2, "%hx", (unsigned
short)0)); ck_assert_str_eq(str1, str2); ck_assert_int_eq(s21_sprintf(str1,
"%hx", 11), sprintf(str2, "%hx", (unsigned short)11)); ck_assert_str_eq(str1,
str2); long unsigned int val = INT32_MAX; ck_assert_int_eq(s21_sprintf(str1,
"%lx", val), sprintf(str2, "%lx", val)); ck_assert_str_eq(str1, str2); long
unsigned int v = 0; ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2,
"%lx", v)); ck_assert_str_eq(str1, str2); } END_TEST*/

START_TEST(sprintf_test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19f";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf27) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%%%%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_test_sprintf28) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    int n1;
    int n2;
    int a = s21_sprintf(str1, "%d%n", 123, &n1);
    int b = sprintf(str2, "%d%n", 123, &n2);

    ck_assert_int_eq(a, b);
    ck_assert_int_eq(n1, n2);
    ck_assert_str_eq(str1, str2);
} END_TEST*/

START_TEST(sprintf_test_sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_test_sprintf31) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%e";
    double x = 111;
    ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_sprintf32) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%e%e%e%e";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
        sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_sprintf33) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%Le";
    long double x = 122.1231;

    ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_sprintf35) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.10e";

    ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818), sprintf(str2,
format, 111.184314818));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_sprintf36) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%5.3e%3.2e%lf";

    ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
sprintf(str2, format, 0.000111, 111.555, 1.999));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_sprintf37) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%E";

    ck_assert_int_eq(s21_sprintf(str1, format, 0.666666), sprintf(str2, format,
0.666666));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_sprintf38) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%E%E%E";

    ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
sprintf(str2, format, 0.0000999, 111.9999, 6.666));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_sprintf39) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%e ABOBA %Lf %Lf %Le";
    long double c = 848181;
    long double a = 0.00000001;
    long double b = 1111111.11;
    ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c), sprintf(str2,
format, 123.123, a, b, c));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_sprintf40) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%#e Floppa %#E%#f";

    ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
sprintf(str2, format, 123.111, 0.0000999, 0.555));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_test_sprintf41) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.Lf";
    long double a = 7.9418438184;

    ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

    ck_assert_str_eq(str1, str2);
} END_TEST*/

START_TEST(sprintf_test_sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_g_trailing_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%g";
    double hex = 0.50300;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_large) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%g";
    double hex = 5131.43141;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_small) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%g";
    double hex = 0.123000;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.5g";
    double hex = 0.123000;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_precision_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.0g";
    double hex = 0.123000;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_precision_missing) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.g";
    double hex = 0.123000;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_many_zeroes_in_front) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.g";
    double hex = 0.0004;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_one_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%g";
    double hex = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.5g";
    double hex = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_mantiss) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%g";
    double hex = 0.0000005;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_mantiss_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%5.8g";
    double hex = 0.0000005;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_short_no_mantiss) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%g";
    double hex = 0.005;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_LG) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%LG";
    long double hex = 0.000005;
    ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
hex));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_g_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%LG %g %G %Lg %.5g";
    long double hex = 0.000005;
    double hex1 = 41.1341;
    double hex2 = 848.9000;
    long double hex3 = 0.0843;
    double hex4 = 0.0005;
    double hex5 = 0.8481481;
    ck_assert_int_eq(
        s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
        sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(sprintf_wide_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %lc";
    unsigned long w = L'汉';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}

START_TEST(sprintf_width_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %5c";
    char w = 'c';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}

START_TEST(sprintf_minus_wide_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %-5lc";
    unsigned long w = L'森';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
} END_TEST

START_TEST(sprintf_wide_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %ls";
    wchar_t w[] = L"森我爱菠萝";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
} END_TEST

START_TEST(sprintf_wide_string1) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %5.12ls";
    wchar_t w[] = L"森我爱菠萝";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
} END_TEST

START_TEST(sprintf_wide_string2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %120ls ABOBA";
    wchar_t w[] = L"森我爱菠萝";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
} END_TEST

START_TEST(sprintf_wide_string3) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %-43ls";
    wchar_t w[] = L"森我爱菠萝";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
} END_TEST

START_TEST(sprintf_wide_string4) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %43ls";
    wchar_t w[] = L"森我爱菠萝";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
} END_TEST

START_TEST(sprintf_wide_char2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %43lc";
    unsigned long w = L'森';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST*/
// sprintf <-

Suite *suite_part1(void) {
  Suite *s = suite_create("suite_part1");
  TCase *tc = tcase_create("insert_tc");

  /* -----===== PART-1 =====----- */
  /* -----===== START =====----- */
  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strcat_1);
  tcase_add_test(tc, strcat_2);
  tcase_add_test(tc, strcat_3);
  tcase_add_test(tc, strcmp_1);
  tcase_add_test(tc, strcmp_2);
  tcase_add_test(tc, strcmp_3);
  tcase_add_test(tc, strcmp_int_1);
  tcase_add_test(tc, strcmp_int_2);
  tcase_add_test(tc, strcmp_int_3);
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, strcpy_1);
  tcase_add_test(tc, strcpy_2);
  tcase_add_test(tc, strcpy_3);
  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memmove_1);
  tcase_add_test(tc, memmove_2);
  tcase_add_test(tc, memmove_3);
  tcase_add_test(tc, memmove_4);
  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strspn_1);
  tcase_add_test(tc, strspn_2);
  tcase_add_test(tc, strspn_3);
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);

  /* -----===== PART-1 =====----- */
  /* -----===== FINISH =====----- */

  /* -----===== PART-2 =====----- */
  /* -----===== START =====----- */
  tcase_add_test(tc, strlen_empty);
  tcase_add_test(tc, strlen_abosal);
  tcase_add_test(tc, strlen_num);
  tcase_add_test(tc, strlen_string);
  tcase_add_test(tc, strlen_abosal_no_dal);
  tcase_add_test(tc, strlen_dai_mne_pen);
  tcase_add_test(tc, strlen_Floppy_disk);
  tcase_add_test(tc, strlen_floppa);
  tcase_add_test(tc, strlen_kot_Vasily);
  tcase_add_test(tc, strlen_Russky_kot_Shlepa);

  tcase_add_test(tc, strncat_all_empty);
  tcase_add_test(tc, strncat_zero_byte);
  tcase_add_test(tc, strncat_empty_src);
  tcase_add_test(tc, strncat_cd_abosa);
  tcase_add_test(tc, strncat_string);
  tcase_add_test(tc, strncat_BIGFLOPPA);
  tcase_add_test(tc, strncat_BIGFLOPPA2);
  tcase_add_test(tc, strncat_BIGFLOPPA3);
  tcase_add_test(tc, strncat_BIGFLOPPA4);
  tcase_add_test(tc, strncat_zero_char);

  tcase_add_test(tc, strncmp_empty);
  tcase_add_test(tc, strncmp_floppa_);
  tcase_add_test(tc, strncmp__floppa);
  tcase_add_test(tc, strncmp_floppa_floppa);
  tcase_add_test(tc, strncmp_floppa_floppa_zero_byte);
  tcase_add_test(tc, strncmp_floppa_floppa_one_byte);

  tcase_add_test(tc, strrchr_empty);
  tcase_add_test(tc, strrchr_floppy_);
  tcase_add_test(tc, strrchr__floppy);
  tcase_add_test(tc, strrchr_poki_doki_o);
  tcase_add_test(tc, strrchr_poki_doki_i);
  tcase_add_test(tc, strrchr_poki_doki_p);
  tcase_add_test(tc, strrchr_find_big_P);
  tcase_add_test(tc, strrchr_find_zero);

  tcase_add_test(tc, strpbrk_empty);
  tcase_add_test(tc, strpbrk_floppy_);
  tcase_add_test(tc, strpbrk__floppy);
  tcase_add_test(tc, strpbrk_poki_doki_o);
  tcase_add_test(tc, strpbrk_poki_doki_i);
  tcase_add_test(tc, strpbrk_poki_doki_p);
  tcase_add_test(tc, strpbrk_find_big_P);
  tcase_add_test(tc, strpbrk_find_zero);

  tcase_add_test(tc, strspn_empty);
  tcase_add_test(tc, strspn_gora_);
  tcase_add_test(tc, strspn__gora);
  tcase_add_test(tc, strspn_any_register);
  tcase_add_test(tc, strspn_num_num);
  tcase_add_test(tc, strspn_long_num_num);
  tcase_add_test(tc, strspn_num_long_num);
  tcase_add_test(tc, strspn_any_num);
  tcase_add_test(tc, strspn_num_with_letter);
  tcase_add_test(tc, strspn_num_with_letter2);
  tcase_add_test(tc, strspn_basic_test);
  tcase_add_test(tc, strspn_any_sim);
  tcase_add_test(tc, strspn_upper_letter);
  tcase_add_test(tc, strspn_lower_letter);
  tcase_add_test(tc, strspn_not_uniq_sim);

  tcase_add_test(tc, strstr_empty_string_haystack_and_needle);
  // tcase_add_test(tc, strstr_empty_string_haystack);
  tcase_add_test(tc, strstr_empty_string_needle);
  tcase_add_test(tc, strstr_toxic_test);
  tcase_add_test(tc, strstr_not_word_in_haystack);
  tcase_add_test(tc, strstr_words_with_any_register);
  tcase_add_test(tc, strstr_repeated_words);
  tcase_add_test(tc, strstr_word_at_end);
  tcase_add_test(tc, strstr_one_simbol_in_needle_and_haystack);
  tcase_add_test(tc, strstr_one_simbol_in_needle);
  // tcase_add_test(tc, strstr_one_simbol_in_haystack);

  tcase_add_test(tc, strtok_correct_token_string);
  tcase_add_test(tc, strtok_hard_token_string);
  tcase_add_test(tc, strtok_unary_delimiters);
  tcase_add_test(tc, strtok_no_delims);
  tcase_add_test(tc, strtok_only_delims);
  tcase_add_test(tc, strtok_too_many_uses_non_segfault);
  tcase_add_test(tc, strtok_even_n_of_delims);
  tcase_add_test(tc, strtok_odd_n_of_delims);
  tcase_add_test(tc, strtok_mixed_n_of_delims);
  tcase_add_test(tc, strtok_hard_mixed);
  tcase_add_test(tc, strtok_mixed_hard_incorrect);
  tcase_add_test(tc, strtok_very_hard_mixed);

  tcase_add_test(tc, strncpy_empty);
  tcase_add_test(tc, strncpy_zero_byte);
  tcase_add_test(tc, strncpy_empty_src);
  tcase_add_test(tc, strncpy_one_byte);
  tcase_add_test(tc, strncpy_two_byte);
  tcase_add_test(tc, strncpy_string);

  tcase_add_test(tc, strerror_all_std_errors);
  tcase_add_test(tc, strerror_negative_err_code);

  tcase_add_test(tc, strcspn_empty);
  tcase_add_test(tc, strcspn_gora_);
  tcase_add_test(tc, strcspn__gora);
  tcase_add_test(tc, strcspn_any_register);
  tcase_add_test(tc, strcspn_num_num);
  tcase_add_test(tc, strcspn_long_num_num);
  tcase_add_test(tc, strcspn_num_long_num);
  tcase_add_test(tc, strcspn_any_num);
  tcase_add_test(tc, strcspn_num_with_letter);
  tcase_add_test(tc, strcspn_num_with_letter2);
  tcase_add_test(tc, strcspn_basic_test);
  tcase_add_test(tc, strcspn_any_sim);
  tcase_add_test(tc, strcspn_upper_letter);
  tcase_add_test(tc, strcspn_lower_letter);
  tcase_add_test(tc, strcspn_not_uniq_sim);

  tcase_add_test(tc, strcmp_Heloboba_Heloboba);
  tcase_add_test(tc, strcmp_HEloboba_Heloboba);
  tcase_add_test(tc, strcmp_Hel0boba_Helob0ba);
  tcase_add_test(tc, strcmp_Heloboba_);
  tcase_add_test(tc, strcmp__Heloboba);
  tcase_add_test(tc, strcmp_Heloboba);
  tcase_add_test(tc, strcmp_empty);
  tcase_add_test(tc, strcmp_only_num);

  tcase_add_test(tc, strchr_abobasnutsa_find_a);
  tcase_add_test(tc, strchr_abobasnutAsa_find_A);
  tcase_add_test(tc, strchr_abobasnutA1sa_find_1);
  tcase_add_test(tc, strchr_abobasnutAsa_find_Z);
  tcase_add_test(tc, strchr_abobasnutAsa_find_3);
  tcase_add_test(tc, strchr_empty_src);

  tcase_add_test(tc, strcpy_aboba_floppa);
  tcase_add_test(tc, strcpy__floppa);
  tcase_add_test(tc, strcpy_aboba_);
  tcase_add_test(tc, strcpy_empty);
  tcase_add_test(tc, strcpy_empty_num);
  tcase_add_test(tc, strcpy_hello);
  tcase_add_test(tc, strcpy_over_string);
  tcase_add_test(tc, strcpy_hard_test);

  tcase_add_test(tc, strcat_Hello_aboba);
  tcase_add_test(tc, strcat_zero_first);
  tcase_add_test(tc, strcat_zero_last);
  tcase_add_test(tc, strcat_any_letters_with_register);
  tcase_add_test(tc, strcat_any_letters_with_register_and_num);
  tcase_add_test(tc, strcat_any_letters_with_register_and_num_and_sim);

  tcase_add_test(tc, memcpy_hate_test);
  tcase_add_test(tc, memcpy_zero_test_string);
  tcase_add_test(tc, memcpy_any_empty);
  tcase_add_test(tc, memcpy_zero_test_string_with_register);
  tcase_add_test(tc, memcpy_zero_test_num);
  tcase_add_test(tc, memcpy_one_byte_string);
  tcase_add_test(tc, memcpy_one_byte_string_with_register);
  tcase_add_test(tc, memcpy_one_byte_num);
  tcase_add_test(tc, memcpy_basic_long_string);
  tcase_add_test(tc, memcpy_long_string_with_register);
  tcase_add_test(tc, memcpy_long_string_with_register_and_num);
  tcase_add_test(tc, memcpy_long_string_with_register_and_num_and_simbol);

  tcase_add_test(tc, memmove_empty_dest_and_src);
  tcase_add_test(tc, memmove_empty_dest);
  tcase_add_test(tc, memmove_empty_src);
  tcase_add_test(tc, memmove_write_in_left);
  tcase_add_test(tc, memmove_write_in_right);
  tcase_add_test(tc, memmove_write_in_mid);
  tcase_add_test(tc, memmove_overlap_write_in_left);
  tcase_add_test(tc, memmove_overlap_write_in_right);
  tcase_add_test(tc, memmove_overlap_write_in_mid);
  tcase_add_test(tc, memmove_zero_test_string);
  tcase_add_test(tc, memmove_any_empty);
  tcase_add_test(tc, memmove_zero_test_string_with_register);
  tcase_add_test(tc, memmove_zero_test_num);
  tcase_add_test(tc, memmove_one_byte_string);
  tcase_add_test(tc, memmove_one_byte_string_with_register);
  tcase_add_test(tc, memmove_one_byte_num);
  tcase_add_test(tc, memmove_basic_long_string);
  tcase_add_test(tc, memmove_long_string_with_register);
  tcase_add_test(tc, memmove_long_string_with_register_and_num);
  tcase_add_test(tc, memmove_long_string_with_register_and_num_and_simbol);
  tcase_add_test(tc, memmove_ints);
  tcase_add_test(tc, memmove_floats);
  tcase_add_test(tc, memmove_long_doubels);

  tcase_add_test(tc, memset_aboba_test);
  tcase_add_test(tc, memset_zero_byte);
  tcase_add_test(tc, memset_empty);
  tcase_add_test(tc, memset_replace_on_register_sim);
  tcase_add_test(tc, memset_replace_on_register_num);
  tcase_add_test(tc, memset_long_string);

  tcase_add_test(tc, memcmp_zero_byte);
  tcase_add_test(tc, memcmp_first_byte_in_string);
  tcase_add_test(tc, memcmp_register_test);
  tcase_add_test(tc, memcmp_zero_byte_in_num);
  tcase_add_test(tc, memcmp_first_byte_in_num);
  tcase_add_test(tc, memcmp_two_byte_in_num);
  tcase_add_test(tc, memcmp_two_byte_long_two_num);
  tcase_add_test(tc, memcmp_two_byte_long_first_num);
  tcase_add_test(tc, memcmp_eq_long_string);
  tcase_add_test(tc, memcmp_not_eq_long_string);

  tcase_add_test(tc, memchr_empty_str);
  tcase_add_test(tc, memchr_find_zero_in_string);
  tcase_add_test(tc, memchr_find_simbol_in_string_in_start);
  tcase_add_test(tc, memchr_find_simbol_in_string_in_end);
  tcase_add_test(tc, memchr_find_num_in_string_in_mid);
  tcase_add_test(tc, memchr_find_num_in_array_num);
  tcase_add_test(tc, memchr_find_float_in_array);
  tcase_add_test(tc, memchr_easy_test_string);

  /* -----===== PART-2 =====----- */
  /* -----===== FINISH =====----- */

  /* ------===== this part for testing sprintf and sscanf =====------ */
  /* ------=====                   START                  =====------ */

  tcase_add_test(tc, sprintf_simple_int);
  tcase_add_test(tc, sprintf_precise_int);
  tcase_add_test(tc, sprintf_width_int);
  tcase_add_test(tc, sprintf_minus_width_int);
  tcase_add_test(tc, sprintf_plus_width_int);
  tcase_add_test(tc, sprintf_padding_int);
  tcase_add_test(tc, sprintf_star_width_int);
  tcase_add_test(tc, sprintf_star_precision_int);
  tcase_add_test(tc, sprintf_many_flags_many_ints);
  tcase_add_test(tc, sprintf_flags_long_int);
  tcase_add_test(tc, sprintf_flags_short_int);
  tcase_add_test(tc, sprintf_flags_another_long_int);
  tcase_add_test(tc, sprintf_zero_precision_zero_int);
  tcase_add_test(tc, sprintf_space_flag_int);
  tcase_add_test(tc, sprintf_unsigned_val);
  tcase_add_test(tc, sprintf_unsigned_val_width);
  tcase_add_test(tc, sprintf_unsigned_val_flags);
  tcase_add_test(tc, sprintf_unsigned_val_precision);
  tcase_add_test(tc, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc, sprintf_unsigned_val_short);
  tcase_add_test(tc, sprintf_unsigned_val_long);
  tcase_add_test(tc, sprintf_unsigned_val_many);

  tcase_add_test(tc, sprintf_octal_width);
  tcase_add_test(tc, sprintf_octal_flags);
  tcase_add_test(tc, sprintf_octal_precision);
  // tcase_add_test(tc, sprintf_octal_many_flags);
  tcase_add_test(tc, sprintf_octal_short);
  tcase_add_test(tc, sprintf_octal_long);
  tcase_add_test(tc, sprintf_octal_many);
  tcase_add_test(tc, sprintf_octal);
  tcase_add_test(tc, sprintf_octal_zero);
  tcase_add_test(tc, sprintf_octal_hash);
  tcase_add_test(tc, sprintf_unsigned_zero);
  tcase_add_test(tc, sprintf_hex_width);
  // tcase_add_test(tc, sprintf_hex_flags);
  tcase_add_test(tc, sprintf_hex_precision);
  // tcase_add_test(tc, sprintf_hex_many);
  // tcase_add_test(tc, sprintf_hex_many_flags);
  // tcase_add_test(tc, sprintf_hex_zero);
  tcase_add_test(tc, sprintf_hex_huge);
  tcase_add_test(tc, sprintf_hex_short);
  tcase_add_test(tc, sprintf_hex_long);
  // tcase_add_test(tc, sprintf_hex_one_longer_width);
  // tcase_add_test(tc, sprintf_hex_two_longer_width);
  tcase_add_test(tc, sprintf_one_char);
  tcase_add_test(tc, sprintf_one_precision);
  tcase_add_test(tc, sprintf_one_flags);
  tcase_add_test(tc, sprintf_one_width);
  tcase_add_test(tc, sprintf_one_many);
  tcase_add_test(tc, sprintf_one_many_flags);
  tcase_add_test(tc, sprintf_string);
  tcase_add_test(tc, sprintf_string_precision);
  tcase_add_test(tc, sprintf_string_width);
  tcase_add_test(tc, sprintf_string_flags);
  tcase_add_test(tc, sprintf_string_long);
  tcase_add_test(tc, sprintf_string_many);
  // tcase_add_test(tc, sprintf_ptr);
  // tcase_add_test(tc, sprintf_ptr_width);
  // tcase_add_test(tc, sprintf_ptr_precision);
  // tcase_add_test(tc, sprintf_null_ptr);
  // tcase_add_test(tc, sprintf_n_specifier);
  tcase_add_test(tc, sprintf_string_width_huge);
  tcase_add_test(tc, sprintf_float_precision);
  tcase_add_test(tc, sprintf_float_width);
  tcase_add_test(tc, sprintf_float_precision_zero);
  tcase_add_test(tc, sprintf_float_precision_empty);
  tcase_add_test(tc, sprintf_float_precision_huge);
  tcase_add_test(tc, sprintf_float_precision_huge_negative);
  tcase_add_test(tc, sprintf_float_huge);
  tcase_add_test(tc, sprintf_float_flags);
  tcase_add_test(tc, sprintf_float_many);
  // tcase_add_test(tc, sprintf_e_precision);
  // tcase_add_test(tc, sprintf_e_precision_zero);
  // tcase_add_test(tc, sprintf_e_precision_empty);
  // tcase_add_test(tc, sprintf_e_precision_huge);
  // tcase_add_test(tc, sprintf_e_precision_huge_negative);
  // tcase_add_test(tc, sprintf_e_huge);
  // tcase_add_test(tc, sprintf_e_many);
  // tcase_add_test(tc, sprintf_e_width);
  // tcase_add_test(tc, sprintf_e_flags);
  // tcase_add_test(tc, sprintf_E_int);
  tcase_add_test(tc, sprintf_all_empty);
  tcase_add_test(tc, sprintf_empty_format_and_parameters);
  tcase_add_test(tc, sprintf_test_one_char);
  tcase_add_test(tc, sprintf_test_many_char);
  tcase_add_test(tc, sprintf_test_one_string);
  tcase_add_test(tc, sprintf_test_many_string);
  tcase_add_test(tc, sprintf_test_one_dec);
  tcase_add_test(tc, sprintf_test_many_dec);
  tcase_add_test(tc, sprintf_test_one_int);
  tcase_add_test(tc, sprintf_test_many_int);
  tcase_add_test(tc, sprintf_test_one_float);
  tcase_add_test(tc, sprintf_test_many_float);
  tcase_add_test(tc, sprintf_test_one_unsigned_dec);
  tcase_add_test(tc, sprintf_test_many_unsigned_dec);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_char_with_alignment);
  tcase_add_test(tc, sprintf_test_one_hex_lower);
  tcase_add_test(tc, sprintf_test_one_hex_upper);
  // tcase_add_test(tc, sprintf_test_many_hex_lower);
  // tcase_add_test(tc, sprintf_test_many_hex_upper);
  // tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_left);
  // tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_right);
  // tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_left);
  // tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_right);
  // tcase_add_test(tc, sprintf_test_many_hex_lower_with_alignment);
  // tcase_add_test(tc, sprintf_test_many_hex_upper_with_alignment);
  // tcase_add_test(tc, sprintf_test_one_hex_with_hashtag);
  // tcase_add_test(tc, sprintf_test_one_hex_upper_with_hashtag);
  // tcase_add_test(tc, sprintf_test_many_hex_lower_with_hashtag_and_alignm);
  // tcase_add_test(tc, sprintf_test_many_hex_upper_with_hashtag_and_alignm);
  // tcase_add_test(tc, sprintf_test_one_hex_lower_with_width_star);
  // tcase_add_test(tc, sprintf_test_one_hex_upper_with_width_star);
  // tcase_add_test(tc,
  // sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag);
  // tcase_add_test(tc, sprintf_test_many_hex_upper_with_width_star);
  // tcase_add_test(tc, sprintf_test_one_hex_lower_with_precision);
  // tcase_add_test(tc, sprintf_test_one_hex_upper_with_precision);
  // tcase_add_test(tc, sprintf_test_many_hex_lower_with_precision_and_other);
  // tcase_add_test(tc, sprintf_test_many_hex_upper_with_precision_and_other);
  // tcase_add_test(tc, sprintf_test_one_hex_lower_with_length);
  // tcase_add_test(tc, sprintf_test_one_hex_upper_with_length);
  tcase_add_test(tc, sprintf_test_sprintf1);
  tcase_add_test(tc, sprintf_test_sprintf2);
  tcase_add_test(tc, sprintf_test_sprintf3);
  tcase_add_test(tc, sprintf_test_sprintf4);
  tcase_add_test(tc, sprintf_test_sprintf6);
  tcase_add_test(tc, sprintf_test_sprintf7);
  tcase_add_test(tc, sprintf_test_sprintf8);
  tcase_add_test(tc, sprintf_test_sprintf9);
  tcase_add_test(tc, sprintf_test_sprintf10);
  tcase_add_test(tc, sprintf_test_sprintf11);
  tcase_add_test(tc, sprintf_test_sprintf12);
  tcase_add_test(tc, sprintf_test_sprintf14);
  tcase_add_test(tc, sprintf_test_sprintf15);
  tcase_add_test(tc, sprintf_test_sprintf16);
  tcase_add_test(tc, sprintf_test_sprintf17);
  tcase_add_test(tc, sprintf_test_sprintf18);
  tcase_add_test(tc, sprintf_test_sprintf19);
  tcase_add_test(tc, sprintf_test_sprintf20);
  tcase_add_test(tc, sprintf_test_sprintf24);
  tcase_add_test(tc, sprintf_test_sprintf25);
  // tcase_add_test(tc, sprintf_test_sprintf28);
  tcase_add_test(tc, sprintf_test_sprintf29);
  tcase_add_test(tc, sprintf_test_sprintf30);
  // tcase_add_test(tc, sprintf_test_sprintf31);
  // tcase_add_test(tc, sprintf_test_sprintf32);
  // tcase_add_test(tc, sprintf_test_sprintf33);
  // tcase_add_test(tc, sprintf_test_sprintf35);
  // tcase_add_test(tc, sprintf_test_sprintf36);
  // tcase_add_test(tc, sprintf_test_sprintf37);
  // tcase_add_test(tc, sprintf_test_sprintf38);
  // tcase_add_test(tc, sprintf_test_sprintf39);
  // tcase_add_test(tc, sprintf_test_sprintf40);
  // tcase_add_test(tc, sprintf_test_sprintf41);
  tcase_add_test(tc, sprintf_test_sprintf42);
  tcase_add_test(tc, sprintf_test_sprintf43);
  tcase_add_test(tc, sprintf_test_sprintf44);
  tcase_add_test(tc, sprintf_test_sprintf26);
  tcase_add_test(tc, sprintf_test_sprintf27);
  /*tcase_add_test(tc, sprintf_g_trailing_zero);
  tcase_add_test(tc, sprintf_g_large);
  tcase_add_test(tc, sprintf_g_small);
  tcase_add_test(tc, sprintf_g_precision);
  tcase_add_test(tc, sprintf_g_precision_zero);
  tcase_add_test(tc, sprintf_g_precision_missing);
  tcase_add_test(tc, sprintf_g_many_zeroes_in_front);
  tcase_add_test(tc, sprintf_g_one_zero);
  tcase_add_test(tc, sprintf_g_mantiss);
  tcase_add_test(tc, sprintf_g_mantiss_flags);
  tcase_add_test(tc, sprintf_g_short_no_mantiss);
  tcase_add_test(tc, sprintf_LG);
  tcase_add_test(tc, sprintf_g_many);
  tcase_add_test(tc, sprintf_g_zero);
  tcase_add_test(tc, sprintf_wide_char);
  tcase_add_test(tc, sprintf_width_char);
  tcase_add_test(tc, sprintf_minus_wide_char);
  tcase_add_test(tc, sprintf_wide_string);
  tcase_add_test(tc, sprintf_wide_string1);
  tcase_add_test(tc, sprintf_wide_string2);
  tcase_add_test(tc, sprintf_wide_string3);
  tcase_add_test(tc, sprintf_wide_string4);
  tcase_add_test(tc, sprintf_wide_char2);*/
  /* ------===== this part for testing sprintf and sscanf =====------ */
  /* ------=====                  FINISH                  =====------ */
  /* -----===== FINISH =====----- */

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  int nf;
  Suite *s1;
  SRunner *sr;
  s1 = suite_part1();
  sr = srunner_create(s1);

  // srunner_run_all(sr, CK_ENV);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);

  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  printf("count of errors is %d", nf);
  return 0;
}
