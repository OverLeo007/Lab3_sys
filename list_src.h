//
// Created by stud on 15.03.23.
//

#ifndef LAB3_LIST_SRC_H
#define LAB3_LIST_SRC_H
#define CUR_DATA (tmp->value)
#define DATA_NAME Country


#include <stdlib.h>

typedef struct {
    int id;
    char *continent;
    char *name;
    long GDP;
    long population;

} DATA_NAME;

typedef struct _Node {
    Country value;
    struct _Node *next;
    struct _Node *prev;
} Node;


typedef struct _DbLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DbLinkedList;





#endif //LAB3_LIST_SRC_H
