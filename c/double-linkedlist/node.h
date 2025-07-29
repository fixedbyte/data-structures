#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {
    void *value;
    struct Node *prev;
    struct Node *next;

    void *(*get_value)(struct Node *);
} Node;

Node *nodez(void *, Node *, Node *);
void *get_value(Node *);

#endif
