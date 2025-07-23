#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {
    void *value;
    struct Node *next;

    void *(*get_value)(struct Node *);
} Node;

Node *nodez(void *, Node *);
void *get_value(Node *);

#endif
