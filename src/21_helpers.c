#include "calc.h"

double num_parser(char* str, int* counter) {
  double fract = 0;
  int int_part = 0;
  while (isdigit(str[*counter])) {
    int_part = int_part * 10 + str[*counter] - '0';
    *counter += 1;
  }
  if (str[*counter] == '.') {
    *counter += 1;
    int scale = 0;
    while (isdigit(str[*counter])) {
      // printf("qwe");
      fract = fract * 10 + str[*counter] - '0';
      scale += 1;
      *counter += 1;
    }
    fract = fract * pow(10, -scale);
  }
  *counter -= 1;
  return int_part + fract;
}

void clear_space(char* str) {
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == ' ') {
      int j = i;
      while (j < (int)strlen(str)) {
        str[j] = str[j + 1];
        j++;
      }
    }
  }
}

int if_unary(char* str, int counter) {
  int res = 0;
  if (counter == 0 || str[counter - 1] == '(') res = 1;
  return res;
}

char* x_case(char* str, double x) {
  char* x_cpy = calloc(sizeof(char), 50);
  sprintf(x_cpy, "%.7f", x);
  char* new_str = calloc(sizeof(char), 1296);
  int count = 0;
  while (*str) {
    if (*str == 'x') {
      strcat(new_str, x_cpy);
      str++;
      count++;
    } else {
      char* qwe = calloc(1296, sizeof(char));
      int i = 0;
      while (*str != 'x' && *str) {
        qwe[i] = *str;
        str++;
        i++;
        count++;
      }
      strcat(new_str, qwe);
      free(qwe);
    }
  }
  str -= count;

  free(x_cpy);
  // free(str);
  return new_str;
}

int IsOkDouble(char* str) {
  int error = 0, dotcounter = 0;
  char* qwe = ".0123456789";
  int i = 0;
  if (str[0] == '-') i++;
  for (; i < (int)strlen(str); i++) {
    if (strchr(qwe, str[i]) == NULL) error = 1;
    if (str[i] == '.') dotcounter++;
  }
  if (str[0] == '.' || str[(int)strlen(str) - 1] == '.') error = 1;
  if (dotcounter > 1) error = 1;
  return error;
}