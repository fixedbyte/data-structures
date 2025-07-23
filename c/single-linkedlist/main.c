#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

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
    printf("Linkedlist (size: %d): \n", l1->size(l1));
    while (l1->head != NULL) {
        void *val = l1->head->value;
        printf("%d -> ", *(int *)val);
        l1->head = l1->head->next;
        if (l1->head == NULL) {
            printf("NULL\n");
        }
    }
    return 0;
}
