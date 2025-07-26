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
    Node *(*get_node)(struct Linkedlist *, void *);
    int (*get_position)(struct Linkedlist *, void *);
    void (*empty)(struct Linkedlist *);
    void (*remove_for)(struct Linkedlist *, void *);
    void (*remove_first)(struct Linkedlist *);
    void (*remove_last)(struct Linkedlist *);
    void (*remove_at)(struct Linkedlist *, int);
    void (*print)(struct Linkedlist *);
} Linkedlist;

Linkedlist *linkedlistz();
int size(Linkedlist *);
Node *add_last(Linkedlist *, void *);
Node *add_first(Linkedlist *, void *);
Node *add_at(Linkedlist *, int, void *);
Node *get_node(struct Linkedlist *, void *);
int get_position(struct Linkedlist *, void *);
void empty(struct Linkedlist *);
void remove_for(struct Linkedlist *, void *);
void remove_first(struct Linkedlist *);
void remove_last(struct Linkedlist *);
void remove_at(struct Linkedlist *, int);
void print(struct Linkedlist *);

#endif
