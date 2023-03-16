//
// Created by stud on 15.03.23.
//

#ifndef LAB3_LIST_SRC_H
#define LAB3_LIST_SRC_H
#define CUR_DATA (tmp->value)
#define DATA_NAME Country


#include <stdlib.h>


typedef struct {
    size_t id;
    char *continent;
    char *name;
    long GDP;
    long population;

} DATA_NAME;


typedef struct _Node {
    DATA_NAME *value;
    struct _Node *next;
    struct _Node *prev;
} Node;


typedef struct {
    size_t size;
    Node *head;
    Node *tail;
} DbLinkedList;

DbLinkedList *new_list();

void delete_list(DbLinkedList **list);

void append(DATA_NAME *value, DbLinkedList *list);

Node *get_node(DbLinkedList *list, size_t index);

DATA_NAME *del(DbLinkedList *list, size_t index);


#endif //LAB3_LIST_SRC_H
