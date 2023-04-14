#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <limits.h>

#include "s21_string.h"

#define ISDIGIT(c) ((c) >= '0' && (c) <= '9')
#define ISSPACE(c) ((c) == ' ' || (c) <= '\t')

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = NULL;
  if (str != NULL)
    for (s21_size_t i = 0; i < n && !res; i++)
      if (*((char *)str + i) == (char)c) res = (char *)(str + i);
  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int tmp = 0;
  s21_size_t i = 0;
  while (i < n && tmp == 0 && *(char *)(str1 + i) != '\0' &&
         *(char *)(str2 + i) != '\0') {
    tmp = *(unsigned char *)(str1 + i) - *(unsigned char *)(str2 + i);
    i++;
  }
  return tmp;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != NULL && src != NULL)
    for (s21_size_t i = 0; i < n; i++) *(char *)(dest + i) = *(char *)(src + i);
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *tmp_dest = (char *)dest;
  const char *tmp_src = (const char *)src;
  if (dest < src) {
    for (s21_size_t i = 0; i < n; i++) *(tmp_dest + i) = *(tmp_src + i);
  } else if (dest > src) {
    for (s21_size_t i = n; i > 0; i--) *(tmp_dest + i - 1) = *(tmp_src + i - 1);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *tmp = (char *)str;
  for (s21_size_t i = 0; i < n; i++) *(tmp + i) = c;
  return str;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (*str) {
    len++;
    str++;
  }
  return len;
}

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  if (str1 != str2) {
    while ((*str1 || *str2) && res == 0) {
      res = *str1 - *str2;
      str1++;
      str2++;
    }
  }
  return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  s21_size_t i = 0;
  if (str1 != str2) {
    while ((*str1 || *str2) && res == 0 && i < n) {
      res = *str1 - *str2;
      str1++;
      str2++;
    }
  }
  return res;
}

char *s21_strcpy(char *str1, const char *str2) {
  char *tmp_str1 = str1;
  const char *tmp_str2 = str2;
  while (*tmp_str2) {
    *tmp_str1 = *tmp_str2;
    tmp_str1++;
    tmp_str2++;
  }
  *tmp_str1 = '\0';
  return str1;
}

char *s21_strncpy(char *str1, const char *str2, s21_size_t n) {
  char *tmp_str1 = str1;
  const char *tmp_str2 = str2;
  s21_size_t i = 0;
  while (*tmp_str2 && i < n) {
    *tmp_str1 = *tmp_str2;
    tmp_str1++;
    tmp_str2++;
    i++;
  }
  while (i < n) {
    *tmp_str1 = '\0';
    tmp_str1++;
    i++;
  }
  return str1;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  if (str2 == NULL) {
    res = s21_strlen(str1);
  } else {
    while (*str1 && !s21_strchr(str2, *str1)) {
      res++;
      str1++;
    }
  }
  return res;
}

char *s21_strerror(int errnum) {
#if defined(__linux__)
  char errors[10000] =
      "0: Success\n1: Operation not permitted\n2: No such file or directory\n3: No such process\n4: Interrupted system call\n\
        5: Input/output error\n6: No such device or address\n7: Argument list too long\n8: Exec format error\n9: Bad file descriptor\n\
        10: No child processes\n11: Resource temporarily unavailable\n12: Cannot allocate memory\n13: Permission denied\n14: Bad address\n\
        15: Block device required\n16: Device or resource busy\n17: File exists\n18: Invalid cross-device link\n19: No such device\n20: Not a directory\n\
        21: Is a directory\n22: Invalid argument\n23: Too many open files in system\n24: Too many open files\n25: Inappropriate ioctl for device\n\
        26: Text file busy\n27: File too large\n28: No space left on device\n29: Illegal seek\n30: Read-only file system\n31: Too many links\n32: Broken pipe\n\
        33: Numerical argument out of domain\n34: Numerical result out of range\n35: Resource deadlock avoided\n36: File name too long\n37: No locks available\n\
        38: Function not implemented\n39: Directory not empty\n40: Too many levels of symbolic links\n41: Unknown error 41\n42: No message of desired type\n\
        43: Identifier removed\n44: Channel number out of range\n45: Level 2 not synchronized\n46: Level 3 halted\n47: Level 3 reset\n48: Link number out of range\n\
        49: Protocol driver not attached\n50: No CSI structure available\n51: Level 2 halted\n52: Invalid exchange\n53: Invalid request descriptor\n54: Exchange full\n\
        55: No anode\n56: Invalid request code\n57: Invalid slot\n58: Unknown error 58\n59: Bad font file format\n60: Device not a stream\n61: No data available\n\
        62: Timer expired\n63: Out of streams resources\n64: Machine is not on the network\n65: Package not installed\n66: Object is remote\n67: Link has been severed\n\
        68: Advertise error\n69: Srmount error\n70: Communication error on send\n71: Protocol error\n72: Multihop attempted\n73: RFS specific error\n74: Bad message\n\
        75: Value too large for defined data type\n76: Name not unique on network\n77: File descriptor in bad state\n78: Remote address changed\n\
        79: Can not access a needed shared library\n80: Accessing a corrupted shared library\n81: .lib section in a.out corrupted\n\
        82: Attempting to link in too many shared libraries\n83: Cannot exec a shared library directly\n84: Invalid or incomplete multibyte or wide character\n\
        85: Interrupted system call should be restarted\n86: Streams pipe error\n87: Too many users\n88: Socket operation on non-socket\n89: Destination address required\n\
        90: Message too long\n91: Protocol wrong type for socket\n92: Protocol not available\n93: Protocol not supported\n94: Socket type not supported\n\
        95: Operation not supported\n96: Protocol family not supported\n97: Address family not supported by protocol\n98: Address already in use\n\
        99: Cannot assign requested address\n100: Network is down\n101: Network is unreachable\n102: Network dropped connection on reset\n103: Software caused connection abort\n\
        104: Connection reset by peer\n105: No buffer space available\n106: Transport endpoint is already connected\n107: Transport endpoint is not connected\n\
        108: Cannot send after transport endpoint shutdown\n109: Too many references: cannot splice\n110: Connection timed out\n111: Connection refused\n\
        112: Host is down\n113: No route to host\n114: Operation already in progress\n115: Operation now in progress\n116: Stale file handle\n117: Structure needs cleaning\n\
        118: Not a XENIX named type file\n119: No XENIX semaphores available\n120: Is a named type file\n121: Remote I/O error\n122: Disk quota exceeded\n123: No medium found\n\
        124: Wrong medium type\n125: Operation canceled\n126: Required key not available\n127: Key has expired\n128: Key has been revoked\n129: Key was rejected by service\n\
        130: Owner died\n131: State not recoverable\n132: Operation not possible due to RF-kill\n133: Memory page has hardware error";
  int max = 133, min = 0;
#elif defined(__MACH__)
  char errors[10000] =
      "1: Operation not permitted\n2: No such file or directory\n3: No such process\n4: Interrupted system call\n5: Input/output error\n6: Device not configured\n\
        7: Argument list too long\n8: Exec format error\n9: Bad file descriptor\n10: No child processes\n11: Resource deadlock avoided\n12: Cannot allocate memory\n\
        13: Permission denied\n14: Bad address\n15: Block device required\n16: Resource busy\n17: File exists\n18: Cross-device link\n19: Operation not supported by device\n\
        20: Not a directory\n21: Is a directory\n22: Invalid argument\n23: Too many open files in system\n24: Too many open files\n25: Inappropriate ioctl for device\n\
        26: Text file busy\n27: File too large\n28: No space left on device\n29: Illegal seek\n30: Read-only file system\n31: Too many links\n32: Broken pipe\n\
        33: Numerical argument out of domain\n34: Result too large\n35: Resource temporarily unavailable\n36: Operation now in progress\n37: Operation already in progress\n\
        38: Socket operation on non-socket\n39: Destination address required\n40: Message too long\n41: Protocol wrong type for socket\n42: Protocol not available\n\
        43: Protocol not supported\n44: Socket type not supported\n45: Operation not supported\n46: Protocol family not supported\n\
        47: Address family not supported by protocol family\n48: Address already in use\n49: Can't assign requested address\n50: Network is down\n51: Network is unreachable\n\
        52: Network dropped connection on reset\n53: Software caused connection abort\n54: Connection reset by peer\n55: No buffer space available\n\
        56: Socket is already connected\n57: Socket is not connected\n58: Can't send after socket shutdown\n59: Too many references: can't splice\n60: Operation timed out\n\
        61: Connection refused\n62: Too many levels of symbolic links\n63: File name too long\n64: Host is down\n65: No route to host\n66: Directory not empty\n\
        67: Too many processes\n68: Too many users\n69: Disc quota exceeded\n70: Stale NFS file handle\n71: Too many levels of remote in path\n72: RPC struct is bad\n\
        73: RPC version wrong\n74: RPC prog. not avail\n75: Program version wrong\n76: Bad procedure for program\n77: No locks available\n78: Function not implemented\n\
        79: Inappropriate file type or format\n80: Authentication error\n81: Need authenticator\n82: Device power is off\n83: Device error\n\
        84: Value too large to be stored in data type\n85: Bad executable (or shared library)\n86: Bad CPU type in executable\n87: Shared library version mismatch\n\
        88: Malformed Mach-o file\n89: Operation canceled\n90: Identifier removed\n91: No message of desired type\n92: Illegal byte sequence\n93: Attribute not found\n\
        94: Bad message\n95: EMULTIHOP (Reserved)\n96: No message available on STREAM\n97: ENOLINK (Reserved)\n98: No STREAM resources\n99: Not a STREAM\n\
        100: Protocol error\n101: STREAM ioctl timeout\n102: Operation not supported on socket\n103: Policy not found\n104: State not recoverable\n105: Previous owner died\n\
        106: Interface output queue is full";
  int max = 106, min = 1;
#endif
  char errnumber[11];
  int i = 0, tmp = 1000000;
  char *res = NULL;
  int err = errnum;
  if (errnum < 0) {
    errnumber[i] = '-';
    i++;
    err = -err;
  }
  if (errnum == 0) {
    errnumber[i] = '0';
    i++;
  } else {
    for (int j = 6; j >= 0; j--) {
      if (err >= tmp) {
        errnumber[i] = (err / tmp) % 10 + 48;
        i++;
      }
      tmp = tmp / 10;
    }
  }
  errnumber[i] = '\0';
  if (errnum <= max && errnum >= min) {
    res = s21_strstr(s21_strtok(s21_strstr(errors, errnumber), "\n"), ": ") + 2;
  } else {
    if (errnum == 0) {
      char unknown[100] = "Undefined error: ";
      res = s21_strcat(unknown, errnumber);
    } else {
#if defined(__linux__)
      char unknown[100] = "Unknown error ";
#elif defined(__MACH__)
      char unknown[100] = "Unknown error: ";
#endif
      res = s21_strcat(unknown, errnumber);
    }
  }
  return res;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = NULL;
  while (*str1 && !res) {
    if (s21_strchr(str2, *str1)) res = (char *)str1;
    str1++;
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *res = NULL;
  for (s21_size_t i = s21_strlen(str) + 1; i > 0 && !res; i--)
    if (*(str + i - 1) == c) res = (char *)(str + i - 1);
  return res;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  while (*str1 && s21_strchr(str2, *str1)) {
    res++;
    str1++;
  }
  return res;
}

char *s21_strcat(char *str1, const char *str2) {
  char *tmp_str1 = str1;
  ;
  while (*tmp_str1) tmp_str1++;
  while (*str2) {
    *tmp_str1 = *str2;
    tmp_str1++;
    str2++;
  }
  *tmp_str1 = '\0';
  return str1;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *tmp_dest = dest;
  s21_size_t i = 0;
  while (*tmp_dest) tmp_dest++;
  while (*src && i < n) {
    *tmp_dest = *src;
    tmp_dest++;
    src++;
    i++;
  }
  *tmp_dest = '\0';
  return dest;
}

char *s21_strchr(const char *str1, const char symbol) {
  while (*str1 && *str1 != symbol) str1++;
  return (*str1) ? (char *)str1 : NULL;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = NULL;
  if (s21_strlen(needle) == 0) {
    res = (char *)haystack;
  } else {
    for (s21_size_t i = 0;
         i <= s21_strlen(haystack) - s21_strlen(needle) && !res; i++)
      if (*(haystack + i) == *needle) {
        res = (char *)(haystack + i);
        for (s21_size_t j = 0; j < s21_strlen(needle) && res; j++)
          if (*(haystack + i + j) != *(needle + j)) res = NULL;
      }
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *next;
  if (str) {
    next = str;
    while (*next && s21_strchr(delim, *next)) *next++ = '\0';
  }
  if (!*next) return NULL;
  str = next;
  while (*next && !s21_strchr(delim, *next)) next++;
  while (*next && s21_strchr(delim, *next)) *next++ = '\0';
  return str;
}
/*
// sprintf
*/

char *s21_strrev_char(char *buf, int i, int j) {
  while (i < j) {
    char t = *(buf + i);
    *(buf + i++) = *(buf + j);
    *(buf + j--) = t;
  }
  return buf;
}

int s21_strcmp_int(const char *p1, const char *p2) {
  const unsigned char *s1 = (const unsigned char *)p1;
  const unsigned char *s2 = (const unsigned char *)p2;
  unsigned char c1, c2;
  do {
    c1 = (unsigned char)*s1++;
    c2 = (unsigned char)*s2++;
    if (c1 == '\0') return c1 - c2;
  } while (c1 == c2);
  return c1 - c2;
}

char *s21_strnfill_char(char *buf, int len, char c) {
  for (int i = 0; i < len; i++) *buf++ = c;
  return buf;
}

char *s21_strcpy_char(char *to, const char *from) {
  for (; (*to = *from); ++from, ++to)
    ;
  return (to);
}

int s21_strlen_int(const char *str) {
  const char *s;

  for (s = str; *s; ++s)
    ;
  return (s - str);
}

char *s21_sprintf_itoa(long num, char *buf, int base, char **buff, int minwidth,
                       int width, char padding, int plus, int padleft,
                       int space, int h, int l, int dot, int isfloat) {
  if (base < 2 || base > 32) return buf;

  if (!h && !l && !isfloat)
    num = (int)num;
  else if (h)
    num = (short)num;

  int sign = (num < 0) ? -1 : plus;
  int sign1 = (num < 0) ? -1 : 1;
  char *s = buf;

  while (num) {
    int digit = num % base * sign1;
    *s++ = (digit >= 10) ? 'A' + digit - 10 : '0' + digit;

    num /= base;
  }

  if (s == buf) *s++ = '0';

  int numlen = s - buf;
  char signchar = (sign == -1) ? '-' : (sign == 1) ? '+' : ' ';

  if (isfloat && minwidth) {
    if (numlen + width + 1 >= minwidth)
      minwidth = numlen;
    else
      minwidth = minwidth - width - 1;
  }

  if (isfloat) width = numlen;

  if (((padding == ' ') || (numlen >= width)) && sign && base == 10) {
    *s++ = signchar;
    numlen++;
  } else if (((padding == ' ') || (numlen >= width)) && !sign && base == 10 &&
             space) {
    *s++ = signchar;
    numlen++;
  }

  int number_length_stat = numlen;

  for (; numlen < width; numlen++) {
    if (padding != ' ' && numlen + 1 == width && sign && base == 10) {
      *s++ = signchar;
    } else if (padding != ' ' && numlen + 1 == width && !sign && base == 10 &&
               space) {
      *s++ = signchar;
    } else {
      *s++ = padding;
    }
  }

  if (dot) number_length_stat = numlen;

  if (!padleft) {
    // printf("????? %s",buf);
    for (; numlen < minwidth; numlen++) *s++ = ' ';
    s21_strrev_char(buf, 0, s - buf - 1);
  }

  if (padleft) {
    // printf("!!!!! %s",buf);
    s21_strrev_char(buf, 0, s - buf - 1 - (numlen - number_length_stat));
    for (; numlen < minwidth; numlen++) *s++ = ' ';
  }

  *s = '\0';

  if (buff) *buff = s;

  return s;
}

char *s21_sprintf_uitoa(unsigned long long num, char *buf, int base,
                        char **buff, int minwidth, int width, char padding,
                        int padleft) {
  char *s = buf;

  char basechar = 'a';
  if (base < 0) {
    base = -base;
    basechar = 'A';
  }

  while (num) {
    int digit = (base != 0) ? num % base : 0;
    *s++ = (digit >= 10) ? basechar + digit - 10 : '0' + digit;
    num /= base;
  }

  if (s == buf) *s++ = '0';

  int numlen = s - buf;

  // printf("padleft %d numlen %d width %d\n",padleft,numlen,width);

  if (!padleft)
    for (; numlen < width; numlen++) *s++ = padding;

  if (!padleft)
    for (; numlen < minwidth; numlen++) *s++ = ' ';

  //*s = '\0'; printf("@%s@\n",buf);

  s21_strrev_char(buf, 0, s - buf - 1);

  if (padleft)
    for (; numlen < minwidth; numlen++) *s++ = ' ';

  *s = '\0';

  if (buff) *buff = s;

  return s;
}

char *s21_sprintf_ftoa(double num, char *buf, char **buff, int width, int prec,
                       char padding, int plus, int padleft, int space) {
  long int intpart = (long int)num;

  char *s = s21_sprintf_itoa(intpart, buf, 10, buff, width, prec, padding, plus,
                             padleft, space, 0, 0, 0, 1);

  int intlen = s - buf;

  if (prec) {
    double fpart = num - (double)intpart;

    if (fpart < 0) fpart = -fpart;

    for (int i = 0; i < prec; i++) {
      fpart *= 10;
    }
    fpart += 0.5;

    *s++ = '.';
    intlen++;

    unsigned long int pointpart = (unsigned long int)fpart;
    s = s21_sprintf_uitoa(pointpart, s, 10, buff, 0, prec, '0', 0);

    if (padleft) {
      int numpadleft = width - intlen - prec;
      for (int i = 0; i < numpadleft; i++) *s++ = ' ';
    }

    *s = '\0';

    if (buff) *buff = s;
  }

  return s;
}

void s21_sprintf_memset(void *ptr, int size, char c) {
  char *p = (char *)ptr;
  for (int i = 0; i < size; i++) *p++ = c;
}

int s21_sprintf_atoi(const char *s, const char **ss) {
  int sign = 1, num = 0;

  while (ISSPACE(*s)) s++;

  if (*s == '+' || *s == '-') {
    sign = 1 - 2 * (*s == '-');
    s++;
  }

  while (ISDIGIT(*s)) {
    num = (10 * num) + (*s - '0');
    s++;
  }

  if (ss) *ss = s;

  return sign * num;
}

bool process_flags(const char **fmt, t_sprintf_params *params) {
  bool flag_processed = true;

  switch (**fmt) {
    case '0':
      params->f.zero = true;
      break;
    case '+':
      params->f.plus = true;
      break;
    case '-':
      params->f.minus = true;
      break;
    case ' ':
      params->f.space = true;
      break;
    case '#':
      params->f.hash = true;
      break;
    case 'l':
      params->f.l = true;
      break;
    case 'h':
      params->f.h = true;
      break;
    case 'L':
      params->f.lll = true;
      break;
    case '*':
      params->f.min_width = va_arg(params->va, int);
      if (params->f.min_width < 0 && params->f.minus) {
        params->f.min_width *= -1;
      }
      break;
      break;

    default:
      flag_processed = false;
      break;
  }
  return flag_processed;
}

void process_data(const char **fmt, t_sprintf_params *params) {
  char c = **fmt;
  // printf("process data char \'%c\'\n",c);

  switch (c) {
    case 'c': {
      char c = va_arg(params->va, int);
      int width = params->f.min_width;

      if (!params->f.minus)
        params->buf = s21_strnfill_char(params->buf, width - 1, ' ');

      *params->buf++ = c;

      if (params->f.minus)
        params->buf = s21_strnfill_char(params->buf, width - 1, ' ');

      (*fmt)++;
      break;
    }

    case 'f': {
      double num = va_arg(params->va, double);

      if (params->f.precision == 0 && !params->f.prec_dot)
        params->f.precision = 6;

      char padding = (params->f.zero) ? '0' : ' ';

      char *buf = params->buf;
      s21_sprintf_ftoa(num, buf, &buf, params->f.min_width, params->f.precision,
                       padding, params->f.plus, params->f.minus,
                       params->f.space);

      params->buf = buf;
      (*fmt)++;
      break;
    }

    case 's': {
      char *s = va_arg(params->va, char *);
      int width = params->f.min_width;
      char *tmp = NULL;

      if (params->f.precision) {
        tmp = malloc(params->f.precision * sizeof(char));
        s21_strncpy(tmp, s, params->f.precision);
        tmp[params->f.precision] = '\0';
        s = tmp;
      }

      int slen = s21_strlen_int(s);

      if (!params->f.minus)
        params->buf = s21_strnfill_char(params->buf, width - slen, ' ');

      params->buf = s21_strcpy_char(params->buf, s);

      if (params->f.minus)
        params->buf = s21_strnfill_char(params->buf, width - slen, ' ');

      (*fmt)++;
      if (tmp) free(tmp);
      break;
    }

    case 'd':
    case 'i':
    case 'n': {
      long int num =
          (c == 'n') ? params->buf - params->s : va_arg(params->va, long int);

      int width = params->f.min_width;
      char padding = (params->f.zero) ? '0' : ' ';

      if (params->f.prec_dot &&
          (params->f.space || params->f.plus || num < 0)) {
        width = params->f.precision + 1;
        padding = '0';
      } else if (params->f.prec_dot) {
        width = params->f.precision;
        padding = '0';
      }

      char *buf = params->buf;
      if (params->f.prec_dot && width == 0 && num == 0) {
        for (int i = 0; i < params->f.min_width; i++) *buf++ = ' ';
        if (params->f.plus) *(buf - 1) = '+';
      } else
        s21_sprintf_itoa(num, buf, 10, &buf, params->f.min_width, width,
                         padding, params->f.plus, params->f.minus,
                         params->f.space, params->f.h, params->f.l,
                         params->f.prec_dot, 0);

      params->buf = buf;
      (*fmt)++;
      break;
    }

    case 'u':
    case 'x':
    case 'X':
    case 'o':
    case 'p': {
      unsigned long long num;
      if (c == 'p')
        num = (unsigned long long)va_arg(params->va, void *);
      else
        num = va_arg(params->va, unsigned long);

      int base;

      switch (c) {
        case 'x':
        case 'p':
          base = 16;
          break;
        case 'X':
          base = -16;
          break;
        case 'o':
          base = 8;
          break;
        default:
          base = 10;
          break;
      }

      int width = params->f.min_width;
      char padding = (params->f.zero) ? '0' : ' ';

      if (!width && c == 'p') {
        width = 16;
        padding = '0';
      }

      if (params->f.prec_dot) {
        width = params->f.precision;
        padding = '0';
      }

      char *buf = params->buf;
      if (params->f.hash) switch (base) {
          case -16:

            *buf++ = '0';
            *buf++ = 'X';
            break;

          case 16:
            *buf++ = '0';
            *buf++ = 'x';
            break;

          case 8:
            *buf++ = '0';
            break;

          default:
            break;
        }

      if (params->f.prec_dot && width == 0 && num == 0) {
        for (int i = 0; i < params->f.min_width; i++) *buf++ = ' ';
      } else
        s21_sprintf_uitoa(num, buf, base, &buf, params->f.min_width, width,
                          padding, params->f.minus);

      params->buf = buf;
      (*fmt)++;
      break;
    }

    default:
      *(params->buf++) = c;
      (*fmt)++;
      break;
  }
}

void process_sprintf(const char *fmt, t_sprintf_params *params) {
  int num;
  params->f.precision = 0;
  while (*fmt) {
    // printf("process fmt char %c\n",*fmt);
    if (*fmt == '%') {
      s21_sprintf_memset(&params->f, sizeof(t_sprintf_flags), '\0');

      fmt++;
      while (*fmt) {
        if (process_flags(&fmt, params)) {
          fmt++;
        } else if ((num = s21_sprintf_atoi(fmt, &fmt))) {
          params->f.min_width = num;
        } else if (*fmt == '.') {
          params->f.prec_dot = true;
          if (*++fmt == '*') {
            params->f.precision = va_arg(params->va, int);
            fmt++;
          } else {
            params->f.precision = s21_sprintf_atoi(fmt, &fmt);
            // printf("precision %d\n",params->f.precision);
          }
          if (params->f.precision < 0) {
            params->f.prec_dot = false;
            params->f.precision = 0;
          }
        } else {
          // printf("fmt data -%s-\n",fmt);
          process_data(&fmt, params);
          break;
        }
      }
    } else {
      *(params->buf++) = *fmt++;
    }
  }
  *(params->buf) = '\0';
}

int s21_sprintf(char *str, const char *fmt, ...) {
  static t_sprintf_params params;
  params.s = str;
  params.buf = str;

  va_start(params.va, fmt);

  process_sprintf(fmt, &params);

  va_end(params.va);

  return params.buf - str;
}
