#include "calc.h"

int operand_checker(char* str, Nodesym** s2, int* counter, int* br_fl) {
  if (str[*counter] == '+') {
    if (if_unary(str, *counter))
      pushc2(&s2, "#", 5);
    else
      pushc2(&s2, "+", 1);
  } else if (str[*counter] == '-') {
    if (if_unary(str, *counter))
      pushc2(&s2, "~", 5);
    else
      pushc2(&s2, "-", 1);
  } else if (str[*counter] == '*')
    pushc2(&s2, "*", 2);
  else if (str[*counter] == '/')
    pushc2(&s2, "/", 2);
  else if (str[*counter] == '^')
    pushc2(&s2, "^", 3);
  else if (str[*counter] == '(')
    pushc2(&s2, "(", 5);
  else if (str[*counter] == ')')
    pushc2(&s2, ")", 5), *br_fl = 2;
  else if (str[*counter] == 's') {
    if (str[*counter + 1] == 'i' && str[*counter += 2] == 'n')
      pushc2(&s2, "sin", 3);
    else if (str[*counter + 1] == 'q' && str[*counter + 2] == 'r' &&
             str[*counter += 3] == 't')
      pushc2(&s2, "sqrt", 4);
  } else if (str[*counter] == 'c') {
    if (str[*counter + 1] == 'o' && str[*counter + 2] == 's') *counter += 2;
    pushc2(&s2, "cos", 4);
  } else if (str[*counter] == 't') {
    if (str[*counter + 1] == 'a' && str[*counter + 2] == 'n') *counter += 2;
    pushc2(&s2, "tan", 4);
  } else if (str[*counter] == 'l') {
    if (str[*counter + 1] == 'o' && str[*counter + 2] == 'g')
      *counter += 2, pushc2(&s2, "log", 4);
    else if (str[*counter += 1] == 'n')
      pushc2(&s2, "ln", 4);
  } else if (str[*counter] == 'm') {
    if (str[*counter + 1] == 'o' && str[*counter + 2] == 'd') *counter += 2;
    pushc2(&s2, "mod", 2);
  } else if (str[*counter] == 'a') {
    if (str[*counter + 1] == 's' && str[*counter + 2] == 'i' &&
        str[*counter + 3] == 'n')
      *counter += 3, pushc2(&s2, "asin", 4);
    if (str[*counter + 1] == 'c' && str[*counter + 2] == 'o' &&
        str[*counter + 3] == 's')
      *counter += 3, pushc2(&s2, "acos", 4);
    if (str[*counter + 1] == 't' && str[*counter + 2] == 'a' &&
        str[*counter + 3] == 'n')
      *counter += 3, pushc2(&s2, "atan", 4);
  }
  return 1;
}

Node* unparser_null(char* str, int* counter, Node* s2) {
  Node* cpy = s2;
  if (str[*counter] == 'c' && str[*counter + 1] == 'o' &&
      str[*counter += 2] == 's')
    cpy->data = cos(cpy->data);
  else if (str[*counter] == 't' && str[*counter + 1] == 'a' &&
           str[*counter += 2] == 'n')
    cpy->data = tan(cpy->data);
  else if (str[*counter] == 's') {
    if (str[*counter + 1] == 'q' && str[*counter + 2] == 'r' &&
        str[*counter += 3] == 't')
      cpy->data = sqrt(cpy->data);
    else if (str[*counter + 1] == 'i' && str[*counter += 2] == 'n')
      cpy->data = sin(cpy->data);
  } else if (str[*counter] == 'a') {
    if (str[*counter + 1] == 's' && str[*counter + 2] == 'i' &&
        str[*counter += 3] == 'n')
      cpy->data = asin(cpy->data);
    if (str[*counter + 1] == 'c' && str[*counter + 2] == 'o' &&
        str[*counter += 3] == 's')
      cpy->data = acos(cpy->data);
    if (str[*counter + 1] == 't' && str[*counter + 2] == 'a' &&
        str[*counter += 3] == 'n')
      cpy->data = atan(cpy->data);
  } else if (str[*counter] == 'l') {
    if (str[*counter + 1] == 'o' && str[*counter += 2] == 'g')
      cpy->data = log10(cpy->data);
    else if (str[*counter += 1] == 'n')
      cpy->data = log(cpy->data);
  } else if (str[*counter] == '#')
    cpy->data = cpy->data;
  else if (str[*counter] == '~')
    cpy->data = -cpy->data;
  return cpy;
}

Node* unparser_Nnull(char* str, int* counter, Node* s2, double tempvar2,
                     double tempvar) {
  // Node* cpy = s2;
  if (str[*counter] == '+')
    push(&s2, tempvar2 + tempvar);
  else if (str[*counter] == '-')
    push(&s2, tempvar2 - tempvar);
  else if (str[*counter] == '*')
    push(&s2, tempvar2 * tempvar);
  else if (str[*counter] == '/')
    push(&s2, tempvar2 / tempvar);
  else if (str[*counter] == '^')
    push(&s2, pow(tempvar2, tempvar));
  else if (str[*counter] == 'm' && str[*counter + 1] == 'o' &&
           str[*counter += 2] == 'd')
    push(&s2, fmod(tempvar2, tempvar));
  else if (str[*counter] == 'c' && str[*counter + 1] == 'o' &&
           str[*counter += 2] == 's')
    push(&s2, tempvar2), push(&s2, cos(tempvar));
  else if (str[*counter] == 't' && str[*counter + 1] == 'a' &&
           str[*counter += 2] == 'n')
    push(&s2, tempvar2), push(&s2, tan(tempvar));
  else if (str[*counter] == 'l') {
    if (str[*counter + 1] == 'o' && str[*counter += 2] == 'g')
      push(&s2, tempvar2), push(&s2, log10(tempvar));
    else if (str[*counter += 1] == 'n')
      push(&s2, tempvar2), push(&s2, log(tempvar));
  } else if (str[*counter] == 's') {
    if (str[*counter + 1] == 'i' && str[*counter += 2] == 'n')
      push(&s2, tempvar2), push(&s2, sin(tempvar));
    else if (str[*counter + 1] == 'q' && str[*counter + 2] == 'r' &&
             str[*counter += 3] == 't')
      push(&s2, tempvar2), push(&s2, sqrt(tempvar));
  } else if (str[*counter] == 'a') {
    if (str[*counter + 1] == 's' && str[*counter + 2] == 'i' &&
        str[*counter += 3] == 'n')
      push(&s2, tempvar2), push(&s2, asin(tempvar));
    else if (str[*counter + 1] == 'c' && str[*counter + 2] == 'o' &&
             str[*counter += 3] == 's')
      push(&s2, tempvar2), push(&s2, acos(tempvar));
    else if (str[*counter + 1] == 't' && str[*counter + 2] == 'a' &&
             str[*counter += 3] == 'n')
      push(&s2, tempvar2), push(&s2, atan(tempvar));
  } else if (str[*counter] == '#')
    push(&s2, tempvar2), push(&s2, tempvar);
  else if (str[*counter] == '~')
    push(&s2, tempvar2), push(&s2, -tempvar);
  return s2;
}