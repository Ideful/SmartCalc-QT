#include "calc.h"

double str_unparser(char* str) {
  Node* s2 = NULL;
  double res = 0;
  double tempvar = 0, tempvar2 = 0;
  if (*str != 0) {
    for (int i = 0; i < (int)strlen(str); i++) {
      while (str[i] == ' ') i++;
      if (isdigit(str[i])) {
        tempvar = num_parser(str, &i);
        push(&s2, tempvar);
      } else {
        if (s2->next != NULL) {
          tempvar = pop(&s2);
          tempvar2 = pop(&s2);
          s2 = unparser_Nnull(str, &i, s2, tempvar2, tempvar);
        } else
          s2 = unparser_null(str, &i, s2);
      }
    }
    res = pop(&s2);
  }
  free(str);

  return res;
}
