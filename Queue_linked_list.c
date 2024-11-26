#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};
typedef struct Node *NODE;

NODE getnode() {
    NODE temp = (NODE) malloc(sizeof(struct Node)); // Allocate memory for struct Node
    if (temp == NULL) {
        printf("Node not created\n");
        return NULL;
    }
    return temp;
}

NODE insert_rear(NODE first, int item) {
    NODE temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL) {
        return temp;
    }
    NODE cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("Queue Underflow\n");
        return NULL;
    }
    printf("[%d] Deleted\n", first->info);
    NODE temp = first;
    first = first->link;
    free(temp);
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    NODE cur = first;
    printf("Queue Elements are\n");
    while (cur != NULL) {
        printf("[%d]\t", cur->info);
        cur = cur->link;
    }
    printf("\n"); // Add a newline for better formatting
}

void main() {
    NODE first = NULL;
    int ch, item;
    while (1) {
        printf("Enter the choice:\n1. Insert rear\n2. Delete front\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                first = insert_rear(first, item);
                break;
            case 2:
                first = delete_front(first);
                break;
            case 3:
                display(first);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
