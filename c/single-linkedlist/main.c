#include "linkedlist.h"
#include <stdio.h>

int main() {
    Linkedlist *l1 = linkedlistz();
    Linkedlist *l2 = linkedlistz();

    for (int i = 0; i < 4; i++) {
        int *num = (int *) (malloc(sizeof(int *)));
        *num = i + 1;
        l1->add_last(l1, num);
    }

    for (int i = 0; i >= -1; i--) {
        int *num = (int *) (malloc(sizeof(int *)));
        *num = i;
        l1->add_first(l1, num);
    }

    int *num = (int *) (malloc(sizeof(int *)));
    *num = 10;
    l1->add_at(l1, 3, num);
    l1->add_at(l1, l1->size(l1), num);
    l1->add_at(l1, l1->size(l1) + 1, num);
    l1->add_at(l1, 0, num);

    l1->print(l1);

    printf("What node does have the 3 value?\n");
    Node *get_node_res = l1->get_node(l1, num);
    printf("Node -> addr: %p, val: %d\n", &get_node_res, *(int *) get_node_res->get_value(get_node_res));
    l1->print(l1);
    printf("remove_at\n");
    l1->remove_at(l1, 3);
    l1->print(l1);
    printf("remove_at beginning\n");
    l1->remove_at(l1, 1);
    l1->print(l1);
    printf("remove_at end\n");
    l1->remove_at(l1, l1->size(l1));
    l1->print(l1);
    return 0;
}
