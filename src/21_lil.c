#include "calc.h"

Nodesym* lil(char* res_str, char* temp, Nodesym* s2, int* br_fl, int numfound,
             int prev_priority) {
  if (*br_fl == 0) {
    if ((s2->priority < prev_priority ||
         (s2->priority == prev_priority && s2->data[0] != '^')) &&
        s2->next != NULL && numfound) {
      int tmpprio = 0;
      if (s2->data[0] != '(')
        tmpprio = s2->priority;
      else
        tmpprio = 0;
      char* tmpcharp = popc(&s2);
      while (!is_emptyc(s2) && s2->priority >= tmpprio && s2->data[0] != '(') {
        strcat(temp, popc(&s2));
        strcat(temp, " ");
      }
      if (s2->priority >= tmpprio && s2->data[0] != '(') {
        strcat(temp, popc(&s2));
      }
      pushc(&s2, tmpcharp, tmpprio);
      strcat(res_str, temp);
      strcat(res_str, " ");
    }
  } else if (*br_fl == 2) {
    popc(&s2);
    while (s2->data[0] != '(') {
      strcat(temp, popc(&s2));
      strcat(temp, " ");
    }
    strcat(res_str, temp);
    popc(&s2);
    *br_fl = 0;
  }
  return s2;
}
