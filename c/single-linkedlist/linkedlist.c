#include "linkedlist.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Linkedlist *linkedlistz() {
    Linkedlist *thiz = (Linkedlist *) malloc(sizeof(Linkedlist));
    thiz->l_size = 0;
    thiz->head = NULL;

    thiz->size = size;
    thiz->add_last = add_last;
    thiz->add_at = add_at;
    thiz->add_first = add_first;
    thiz->get_node = get_node;
    thiz->print = print;
    thiz->remove_at = remove_at;
    thiz->remove_last = remove_last;
    thiz->remove_first = remove_first;

    return thiz;
}

int size(Linkedlist *l) {
    return l->l_size;
}

Node *add_last(Linkedlist *l, void *el) {
    Node *new_node = nodez(el, NULL);

    if (l->l_size == 0) {
        l->head = new_node;
    } else {
        Node *pivot = l->head;
        while (pivot->next != NULL) {
            pivot = pivot->next;
        }

        pivot->next = new_node;
    }

    l->l_size++;

    return l->head;
}

Node *add_first(Linkedlist *l, void *el) {
    Node *new_node = nodez(el, l->head);
    l->head = new_node;
    l->l_size++;

    return l->head;
}

Node *add_at(Linkedlist *l, int pos, void *el) {
    if (pos > l->l_size) {
        return add_last(l, el);
    }

    if (pos <= 1) {
        return add_first(l, el);
    }

    Node *new_node = nodez(el, NULL);
    Node *pivot = l->head;

    for (int i = 1; i < l->l_size; i++) {
        if (i == pos - 1) {
            new_node->next = pivot->next;
            pivot->next = new_node;
        }
        pivot = pivot->next;
    }

    l->l_size++;

    return l->head;
}

Node *get_node(Linkedlist *l, void *el) {
    Node *pivot = l->head;

    while (pivot != NULL) {
        if (pivot->get_value(pivot) == el) {
            return pivot;
        }

        pivot = pivot->next;
    }

    return NULL;
}

void print(struct Linkedlist *l) {
    Node *pivot = l->head;
    printf("Linkedlist (size: %d): \n", l->size(l));

    while (pivot != NULL) {
        void *val = pivot->value;
        printf("%d -> ", *(int *) val);
        pivot = pivot->next;
        if (pivot == NULL) {
            printf("NULL\n");
        }
    }
}

void empty(Linkedlist *l) {
    
}

void remove_for(Linkedlist *l, void *el) {

}

void remove_first(Linkedlist *l) {
    remove_at(l, 1);
}

void remove_last(Linkedlist *l) {
    remove_at(l, l->size(l));
}

void remove_at(Linkedlist *l, int pos) {
    if (l->l_size == 0 || pos <= 0 || pos > l->size(l)) {
        return;
    }

    if (l->l_size == 1) {
        free(l->head);
        l->head = NULL;
        l->l_size--;
        return;
    }

    Node *pivot = l->head;

    if (pos == 1) {
        l->head = pivot->next;
        free(pivot);
    } else {
        Node *prev = NULL;

        for (int i = 1; i < l->size(l); i++) {
            if (i == pos - 1) {
                prev = pivot->next;
                pivot->next = pivot->next->next;
                break;
            }

            pivot = pivot->next;
        }

        free(prev);
    }

    l->l_size--;
}
