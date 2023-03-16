//
// Created by stud on 15.03.23.
//

#ifndef LAB3_LIST_SRC_H
#define LAB3_LIST_SRC_H
#define CUR_DATA (tmp->value)


#include <stdlib.h>
#include "country_src.h"


typedef struct _Node {
    DATA_NAME *value;
    struct _Node *next;
    struct _Node *prev;
} Node;


typedef struct _DbLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DbLinkedList;

DbLinkedList *new_list();

void delete_list(DbLinkedList **list);

void append(Node *node, DbLinkedList *list);

Node *get_node(DbLinkedList *list, size_t index);

DATA_NAME *del(DbLinkedList *list, size_t index);


#endif //LAB3_LIST_SRC_H
