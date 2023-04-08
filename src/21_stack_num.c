#include "calc.h"

void push(Node **p_list, double d) {
  Node *p = malloc(sizeof(Node));
  p->data = d;
  p->next = *p_list;
  *p_list = p;
}

double pop(Node **p_list) {
  Node *p = *p_list;
  double res = p->data;
  *p_list = p->next;
  free(p);

  return res;
}
