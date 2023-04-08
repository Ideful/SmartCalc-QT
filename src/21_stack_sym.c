#include "calc.h"

void pushc(Nodesym** p_list, char* str, int prio) {
  Nodesym* p = malloc(sizeof(Nodesym));
  p->data = str;
  p->priority = prio;
  p->next = *p_list;
  *p_list = p;
}

char* popc(Nodesym** p_list) {
  Nodesym* p = *p_list;
  char* res = p->data;
  *p_list = p->next;
  free(p);
  return res;
}

int is_emptyc(Nodesym* list) { return list->next == NULL; }

void pushc2(Nodesym*** p_list, char* str, int prio) {
  Nodesym* p = malloc(sizeof(Nodesym));
  p->data = str;
  p->priority = prio;
  p->next = **p_list;
  **p_list = p;
}
