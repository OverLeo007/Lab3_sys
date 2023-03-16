#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "list_src.h"
#include "country_src.h"


void add_country(DbLinkedList *list, char *continent, char *name, long GDP, long population) {
    Country *country = (Country *) malloc(sizeof(Country));
    country->continent = continent;
    country->name = name;
    country->GDP = GDP;
    country->population = population;
    country->id = list->size;
    
}