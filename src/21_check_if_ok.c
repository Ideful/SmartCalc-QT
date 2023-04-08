#include "calc.h"

int check_if_ok(char* str) {
  int error = 0;
  int o_b = 0, c_b = 0, digit_check = 1;
  char* qwe = ".0123456789+-*/^()sincotalgmdqrx";
  char* qwer = "0123456789+-(sctalx";
  char* qwert = "ctsal";
  if (strchr(qwer, *str) == NULL) error = 1;
  while (*str != 0) {
    if (strchr(qwert, *str) != NULL) op_b4_fn(str, &error);
    if (isdigit(*str) || *str == 'x') digit_check = 0;
    if (!isdigit(*str)) str = check_skobque(str, &error);
    if (strchr(qwe, *str) == NULL) error = 1;
    if (*str == '.') {
      if (!isdigit(*(str - 1)) || !isdigit(*(str + 1))) error = 1;
    }
    if (*str == '(' && *(str + 1) == ')') error = 1;
    if (*str == ')') c_b++;
    if (*str == '(') {
      o_b++;
      int i = 0, q = 0;
      while (*str != ')') {
        if (isdigit(*str) || (*str == 'x')) q = 1;
        i++;
        str++;
      }
      str -= i;
      if (!q) error = 1;
    }
    DveTochkiVChisle(str, &error);
    op_checker(str, &error);
    dig_checker(str, &error);
    if (c_b > o_b) error = 1;
    str++;
  }
  if (o_b != c_b) error = 1;
  return (error || digit_check);
}

void DveTochkiVChisle(char* str, int* error) {
  char* qwer = "+-*/^)";
  if (isdigit(*str)) {
    while (isdigit(*str)) {
      str++;
    }
    if (*str == '.') {
      str++;
      while (isdigit(*str)) {
        str++;
      }
      if (strchr(qwer, *str) == NULL) *error = 1;
    }
  }
}

void op_checker(char* str, int* error) {
  char* qwer = "+-*/^";
  char* qwe = "(0123456789mctlsax";
  while (*str != 0) {
    if (strchr(qwer, *str) != NULL) {
      if (strchr(qwe, *(str + 1)) == NULL) *error = 1;
    }
    str++;
  }
}

void dig_checker(char* str, int* error) {
  char* qwe = "0123456789ctmsal+-*/^.)";
  if (isdigit(*str) && *(str + 1) != 0) {
    if (strchr(qwe, *(str + 1)) == NULL) *error = 1;
  }
}

char* check_skobque(char* str, int* error) {
  if (*str == 'c') {
    if (*(str + 1) == 'o' && *(str + 2) == 's' && *(str + 3) == '(')
      str += 3;
    else
      *error = 1;
  } else if (*str == 't') {
    if (*(str + 1) == 'a' && *(str + 2) == 'n' && *(str + 3) == '(')
      str += 3;
    else
      *error = 1;
  } else if (*str == 'm') {
    if (*(str + 1) == 'o' && *(str + 2) == 'd' && *(str + 3) == '(')
      str += 3;
    else
      *error = 1;
  } else if (*str == 's') {
    if (*(str + 1) == 'q') {
      if (*(str + 2) == 'r' && *(str + 3) == 't' && *(str + 4) == '(')
        str += 4;
      else
        *error = 1;
    } else if (*(str + 1) == 'i') {
      if (*(str + 2) == 'n' && *(str + 3) == '(')
        str += 3;
      else
        *error = 1;
    } else
      *error = 1;
  } else if (*str == 'a') {
    if (*(str + 1) == 's') {
      if (*(str + 2) == 'i' && *(str + 3) == 'n' && *(str + 4) == '(')
        str += 4;
      else
        *error = 1;
    } else if (*(str + 1) == 'c') {
      if (*(str + 2) == 'o' && *(str + 3) == 's' && *(str + 4) == '(')
        str += 4;
      else
        *error = 1;
    } else if (*(str + 1) == 't') {
      if (*(str + 2) == 'a' && *(str + 3) == 'n' && *(str + 4) == '(')
        str += 4;
      else
        *error = 1;
    } else
      *error = 1;
  } else if (*str == 'l') {
    if (*(str + 1) == 'n') {
      if (*(str + 2) == '(')
        str += 2;
      else
        *error = 1;
    } else if (*(str + 1) == 'o') {
      if (*(str + 2) == 'g' && *(str + 3) == '(')
        str += 3;
      else
        *error = 1;
    } else
      *error = 1;
  }
  return str;
}

void op_b4_fn(char* str, int* error) {
  if (isdigit(*(str - 1))) *error = 1;
}