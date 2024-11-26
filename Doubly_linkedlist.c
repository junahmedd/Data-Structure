#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List

struct Node {
    int info;
    struct Node *llink;
    struct Node *rlink;
};
typedef struct Node *NODE;

NODE getnode() {
    NODE temp = (NODE) malloc(sizeof(NODE));
    temp -> llink = NULL;
    temp -> rlink = NULL;
    if (temp == NULL) {
        printf("\nNot Alloced\n");
        return NULL;
    }
    return temp;
}

void display(NODE first) {
    int count = 0;
    NODE cur = first;
    if (cur == NULL) {
        printf("\nLinked List Empty\n");
        return;
    }
    printf("\nLinked List Elements\n");
    while (cur != NULL) {
        printf("[%d]\t", cur->info);
        cur = cur->rlink;
        count++;
    }
    printf("\nNumber of Nodes = %d\n", count);
}

NODE insert_front(NODE first, int item) {
    NODE temp = getnode();
    temp->info = item;
    if (first == NULL) {
        return temp;
    }
    temp->rlink = first;
    first->llink = temp;
    return temp;
}

NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("\nDLL empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("\n[%d]\t deleted\n", first->info);
        free(first);
        return NULL;
    }
    printf("\n[%d]\t deleted\n", first->info);
    first = first->rlink;
    return first;
}

NODE insert_rear(NODE first, int item) {
    NODE temp = getnode();
    temp->info = item;
    if (first == NULL) {
        return temp;
    }
    NODE cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    temp->llink = cur;
    cur->rlink = temp;
    return first;
}

NODE delete_rear(NODE first) {
    if (first == NULL) {
        printf("\nDLL empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("\n[%d]\t deleted\n", first->info);
        free(first);
        return NULL;
    }
    NODE cur = first;
    NODE prev = NULL;
    while (cur->rlink != NULL) {
        prev = cur;
        cur = cur->rlink;
    }
    printf("\n[%d]\t deleted\n", cur->info);
    prev->rlink = cur->rlink;
    return first;
}

void main() {
    NODE first = NULL;

    first = insert_front(first, 10);
    first = insert_rear(first, 20);
    display(first);

    first = delete_rear(first);
    display(first);
}
