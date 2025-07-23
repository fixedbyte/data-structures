#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Linkedlist {
    int l_size;
    Node *head;

    int (*size)(struct Linkedlist *);
    Node *(*add_last)(struct Linkedlist *, void *);
    Node *(*add_first)(struct Linkedlist *, void *);
    Node *(*add_at)(struct Linkedlist *, int, void *);
} Linkedlist;

Linkedlist *linkedlistz();
int size(Linkedlist *);
Node *add_last(Linkedlist *, void *);
Node *add_first(Linkedlist *, void *);
Node *add_at(Linkedlist *, int, void *);

#endif
