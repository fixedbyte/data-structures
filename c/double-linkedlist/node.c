#include "node.h"

Node *nodez(void *value, Node *prev, Node *next) {
    Node *thiz;
    thiz = (Node *) malloc(sizeof(Node));
    thiz->value = value;
    thiz->prev = prev;
    thiz->next = next;

    thiz->get_value = get_value;

    return thiz;
}

void *get_value(Node *node) {
    return node->value;
}
