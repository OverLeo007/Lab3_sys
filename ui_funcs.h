//
// Created by stud on 16.03.23.
//

#ifndef LAB3_UI_FUNCS_H
#define LAB3_UI_FUNCS_H

#include "inp_funcs.h"
#include "list_src.h"
#include "country_src.h"


typedef enum {
    ADD_COUNTRY = 1,
    DEL_COUNTRY,
    PRINT_LIST,
    EXIT

} main_menu_enum;


void run_ui();

void print_menu();

void country_add_handler(DbLinkedList *list);

void country_del_handler(DbLinkedList *list);

#endif //LAB3_UI_FUNCS_H
