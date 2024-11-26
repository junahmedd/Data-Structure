#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};
typedef struct Node *NODE;

NODE getnode() {
    NODE temp = (NODE) malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Memory Not Alloc");
        return NULL;
    }
    else {
        return temp;
    }
}

void display(NODE last) {
    if (last == NULL) {
        printf("No Nodes\n");
        return;
    }
    NODE first = last->link;
    while (first != last) {
        printf("[%d]\t", first->info);
        first = first->link;
    }
    printf("[%d]\t", first->info);
}

NODE insert_front(NODE last, int item) {
    NODE temp = getnode();
    temp->link = temp;
    temp->info = item;
    if (last == NULL) {
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    return last;
}

NODE delete_front(NODE last) {
    if (last == NULL) {
        printf("No nodes exist\n");
        return NULL;
    }
    if (last->link == last) {
        printf("[%d] deleted\n", last->info);
        free(last);
        return NULL;
    }
    NODE first = last->link;
    printf("[%d] deleted\n", first->info);
    last->link = first->link;
    free(first);
    return last;
}

NODE insert_rear(NODE last, int item) {
    NODE temp = getnode();
    temp->info = item;
    temp->link = temp;
    if (last == NULL) {
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    return temp;
}

NODE delete_rear(NODE last) {
    if (last == NULL) {
        printf("No nodes\n");
        return NULL;
    }
    if (last->link == last) {
        printf("[%d] deleted\n", last->info);
        free(last);
        return NULL;
    }
    NODE cur = last->link;
    NODE prev = NULL;
    while (cur != last) {
        prev = cur;
        cur = cur->link;
    }
    printf("[%d] deleted\n", cur->info);
    prev->link = cur->link;
    free(cur);
    return prev;
}

void main() {
    NODE last = NULL;
    int item, choice;
    while (1) {
        printf("Enter choice\n1.Insert_Front\n2.Insert_Rear\n3.Delete_Front\n4.Delete_Rear\n5.Display\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
                printf("Enter item ");
                scanf("%d", &item);
                last = insert_front(last, item);
                break;
            case 2 :
                printf("Enter item ");
                scanf("%d", &item);
                last = insert_rear(last, item);
                break;
            case 3 :
                last = delete_front(last);
                break;
            case 4 :
                last = delete_rear(last);
                break;
            case 5 :
                display(last);
                break;
            default : exit(0);
        }
    }
}
