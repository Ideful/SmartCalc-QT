// #ifndef src_21_polka
// #ifdef  src_21_polka
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct Nodesym Nodesym;

struct Node {
  double data;
  Node* next;
};

struct Nodesym {
  char* data;
  int priority;
  Nodesym* next;
};

void push(Node** p_list, double d);
double pop(Node** p_list);
int is_empty(Node* list);
// void print(Node* list);

void pushc(Nodesym** p_list, char* str, int prio);
void pushc2(Nodesym*** p_list, char* str, int prio);
char* popc(Nodesym** p_list);
int is_emptyc(Nodesym* list);
// void printc(Nodesym* list);

char* str_parser(char* str);
int operand_checker(char* str, Nodesym** s2, int* counter, int* br_fl);
Nodesym* lil(char* res_str, char* tmp_str, Nodesym* s2, int* br_fl,
             int BestDoctor, int prev_priority);
int check_if_bracket(Nodesym* s2);

void clear_space(char* str);
double num_parser(char* str, int* counter);
int if_unary(char* str, int counter);

int check_if_ok(char* str);
void op_checker(char* str, int* error);
void DveTochkiVChisle(char* str, int* error);
char* check_skobque(char* str, int* error);
void op_b4_fn(char* str, int* error);
int IsOkDouble(char* str);
void dig_checker(char* str, int* error);

double str_unparser(char* str);
Node* unparser_null(char* str, int* counter, Node* s2);
Node* unparser_Nnull(char* str, int* counter, Node* s2, double tempvar2,
                     double tempvar);

char* x_case(char* qwe, double x);

// #endif // src_21_polka