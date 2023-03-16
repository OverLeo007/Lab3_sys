#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "list_src.h"
#include "country_src.h"


void add_country(DbLinkedList *list, char *continent, char *name, long GDP, long population) {
    DATA_NAME *country = (DATA_NAME *) malloc(sizeof(DATA_NAME));
    country->continent = continent;
    country->name = name;
    country->GDP = GDP;
    country->population = population;

    if (list->tail) {
        country->id = list->tail->value->id + 1;
    } else {
        country->id = list->size;
    }
    append(country, list);
}


void print_country(DATA_NAME *country) {
    printf("Страна №%zu\n", country->id);
    printf("\tРасположена на континенте %s\n", country->continent);
    printf("\tЕё название: %s\n", country->name);
    printf("\tВВП: %ld\n", country->GDP);
    printf("\tНаселение: %ld\n", country->population);
}

void print_list(DbLinkedList *list) {
    Node *tmp = list->head;

    while (tmp) {
        print_country(CUR_DATA);
        tmp = tmp->next;
    }

}