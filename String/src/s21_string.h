#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdarg.h>
#include <stdbool.h>

#define s21_NULL (void *)0
typedef long unsigned s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
s21_size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
int s21_strcmp_int(const char *p1, const char *p2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *str1, const char *str2);
char *s21_strncpy(char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strcat(char *str1, const char *str2);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str1, const char symbol);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

typedef struct sprintf_flags {
  bool zero;
  bool hash;
  bool space;
  bool plus;
  bool minus;
  bool l;
  bool h;
  bool z;
  bool lll;

  char conv;
  int min_width;
  int precision;
  bool prec_dot;
  bool neg_value;

} t_sprintf_flags;

typedef struct sprinf_params {
  t_sprintf_flags f;
  va_list va;
  char *s;
  char *buf;
} t_sprintf_params;

int s21_sprintf(char *str, const char *fmt, ...);
#endif
