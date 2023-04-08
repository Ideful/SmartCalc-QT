#include "calc.h"

char* str_parser(char* str) {
  clear_space(str);
  int error = check_if_ok(str);
  char* res_str = calloc(1296, sizeof(char));
  int br_fl = 0;
  int prev_priority = 0;
  int digit_existence = 0;
  Nodesym* s2 = {0};
  if (!error) {
    for (int i = 0; i < (int)strlen(str); i++) {
      char* temp = calloc(1296, sizeof(char));
      if (isdigit(str[i]) || str[i] == 'x') {
        digit_existence = 1;
        if (str[i] == 'x')
          strcat(temp, "x");
        else
          sprintf(temp, "%.7f", num_parser(str, &i));
        strcat(res_str, temp);
        strcat(res_str, " ");
      } else {
        operand_checker(str, &s2, &i, &br_fl);
        s2 = lil(res_str, temp, s2, &br_fl, digit_existence, prev_priority);
      }
      free(temp);
      if (s2 != NULL) {
        if (s2->data[0] != '(')
          prev_priority = s2->priority;  // SOS
        else
          prev_priority = 0;
      }
    }
    if (s2 != NULL) {
      while (!is_emptyc(s2)) {
        strcat(res_str, popc(&s2));
        strcat(res_str, " ");
      }
      if (s2->data[0] != '(') strcat(res_str, popc(&s2));
    }
  }
  return res_str;
}

// char* str_parser(char* str){
//     clear_space(str);
//     int error = check_if_ok(str);
//     // printf("\n%s\n",str);
//     char* res_str = calloc(1000,sizeof(char));
//     int flag = 0;
//     int br_fl = 0;
//     int prev_priority = 0;
//     int BestDoctor = 0;
//     Nodesym* s2 = {0};
//     if (!error) {
//         for(int i = 0; i < (int)strlen(str);i++) {
//             char* temp = calloc(800,sizeof(char));
//             if (isdigit(str[i])) {
//                 flag = 0;
//                 BestDoctor = 1;
//                 sprintf(temp,"%.7f",num_parser(str,&i));
//             } else {
//                 flag = 1;
//                 operand_checker(str,&s2,&i,&br_fl);
//             }

//             if (flag) {
//                 s2 = lil(res_str,temp,s2,&br_fl,BestDoctor,prev_priority);
//             } else { // у нас операнд, добавляем в строку
//                 // printf("%s\n",temp);
//                 strcat(res_str,temp);
//                 strcat(res_str, " ");
//             }
//             // printf("@%d\n",br_fl);
//             // printc(s2);
//             // printf("@      %s\n\n",res_str);
//             // printf("\n");

//             free(temp);
//             if (s2 != NULL) {
//                 if (s2->data[0] != '(') prev_priority = s2->priority; // SOS
//                 else prev_priority = 0;
//             }
//         }
//         if (s2 != NULL) {
//             while(!is_emptyc(s2)) {
//                 strcat(res_str,popc(&s2));
//                 strcat(res_str," ");
//             }
//             if(s2->data[0] != '(') strcat(res_str,popc(&s2));
//         }

//         // printf("\n%s\n",res_str);
//     // printc(s2);
//     } else printf("input error\n");
//     return res_str;
// }