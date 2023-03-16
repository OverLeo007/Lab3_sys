#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "list_src.h"


DbLinkedList *new_list() {
    DbLinkedList *list = (DbLinkedList *) malloc(sizeof(DbLinkedList));
    list->size = 0;
    list->head = list->tail = NULL;
    return list;
}

void delete_list(DbLinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(CUR_DATA->continent);
        free(CUR_DATA->name);
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}


void append(Node *node, DbLinkedList *list) {
    node->next = NULL;
    node->prev = list->tail;

    if (list->tail == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}


Node *get_node(DbLinkedList *list, size_t index) {
    if (!list || index >= list->size) {
        return NULL;
    }

    size_t midpoint = list->size / 2;
    bool i_bigger_mid = index >= midpoint;
    Node *current_node = (i_bigger_mid) ? list->tail : list->head;
    size_t i = (i_bigger_mid) ? (list->size - 1) : 0;

    while (current_node && ((i_bigger_mid && i > index) || (index < midpoint && i < index))) {
        current_node = (i_bigger_mid) ? current_node->prev : current_node->next;
        i = (i_bigger_mid) ? (i - 1) : (i + 1);
    }

    return current_node;
}


DATA_NAME *del(DbLinkedList *list, size_t index) {
    Node *node = get_node(list, index);
    if (!node) {
        return NULL;
    }


    DATA_NAME *value = (DATA_NAME *) malloc(sizeof(DATA_NAME));
    memcpy(value, node->value, sizeof(DATA_NAME));

    if (node->prev) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    free(node->value);
    free(node);

    list->size--;
    return value;
}



