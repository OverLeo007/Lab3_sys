//
// Created by stud on 16.03.23.
//

#ifndef LAB3_COUNTRY_SRC_H
#define LAB3_COUNTRY_SRC_H

#include "list_src.h"

void add_country(DbLinkedList *list, char *continent, char *name, long GDP, long population);

void print_country(DATA_NAME *country);

void print_list(DbLinkedList *list);

#endif //LAB3_COUNTRY_SRC_H
