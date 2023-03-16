#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "ui_funcs.h"
#include "inp_funcs.h"
#include "list_src.h"
#include "country_src.h"


void run_ui() {
    DbLinkedList *list = new_list();
    int menu_variant;

    do {
        print_menu();
        menu_variant = (int) input_long();
        switch (menu_variant) {
            case ADD_COUNTRY:
                country_add_handler(list);
                break;
            case DEL_COUNTRY:
                country_del_handler(list);
                break;
            case PRINT_LIST:

                break;
            case EXIT:
                delete_list(&list);
                break;
            default:
                puts("Такого варианта в меню нет!");
                break;

        }

    } while (menu_variant != EXIT);


}


void print_menu() {
    puts("1. Добавить страну");
    puts("2. Удалить страну");
    puts("3. Вывести список стран");
    puts("4. Выйти");
}


void country_add_handler(DbLinkedList *list) {
    bool is_cont = false, is_name = false, is_gdp = false, is_population = false;
    char *cont;
    char *name;
    long gdp, population;
    while (!(is_cont && is_name && is_gdp && is_population)) {
        if (!is_cont) {
            puts("Введите название материка:");
            cont = input_string();
            if (cont[0] == '\0') {
                puts("Некорректное название!");

            } else {
                is_cont = true;
            }
        }

        if (!is_name) {
            puts("Введите название страны:");
            name = input_string();
            if (name[0] == '\0') {
                puts("Некорректное имя!");

            } else {
                is_name = true;
            }
        }

        if (!is_gdp) {
            puts("Введите значение ВВП:");
            gdp = input_long();
            if (gdp == LONG_MIN) {
                puts("Некорректное значение!");

            } else {
                is_gdp = true;
            }
        }

        if (!is_population) {
            puts("Введите значение населения:");
            population = input_long();
            if (population == LONG_MIN) {
                puts("Некорректное значение!");

            } else {
                is_population = true;
            }
        }
    }
    add_country(list, cont, name, gdp, population);

}

void country_del_handler(DbLinkedList *list) {
    puts("Введите индекс удаляемой страны");
    long index = input_long();
    if (index == LONG_MIN) {
        puts("Некорректный ввод");
        return;
    }

    Country *del_country = del(list, index);
    if (!del_country) {
        puts("Некорректный индекс");
        return;
    }
    print_country(del_country);
    puts("Успешно удалена из списка");
    free(del_country);
}

void list_print_handler(DbLinkedList *list) {
    if (list->size == 0) {
        puts("Список пуст!");
    }
    print_list(list);
}