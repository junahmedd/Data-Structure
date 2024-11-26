#include <stdio.h>
#include <stdlib.h>

// Singly Linked List

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node *NODE;

NODE getnode() {
    NODE temp = (NODE) malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Node not created\n");
        return NULL;
    }
    else {
        return temp;
    }
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
        printf("[%d]\t", cur->data);
        cur = cur->next;
        count++;
    }
    printf("\nNumber of Nodes = %d\n", count);
}

void searchelement(NODE first, int item) {
    if (first == NULL) {
        printf("\nList Empty\n");
        return;
    }
    else {
        NODE cur = first;
        int count = 1;
        while (cur != NULL && cur->data != item) {
            cur = cur->next;
            count++;
        }
        if (cur == NULL) {
            printf("\nNot found\n");
        }
        else {
            printf("\n%d found in pos = %d\n", item, count);
        }
    }
}

NODE insertatfirst(NODE first, int item) {
    NODE temp = getnode();
    temp->data = item;
    temp->next = NULL;
    if (first == NULL) {
        return temp;
    }
    else {
        temp->next = first;
        return temp;
    }
}

NODE deleteatfirst(NODE first) {
    if (first == NULL) {
        printf("\nLinked List Empty\n");
        return NULL;
    }
    else if (first->next == NULL) {
        printf("\n[%d] deleted\n", first->data);
        free(first);
        return NULL;
    }
    else {
        printf("\n[%d] deleted\n", first->data);
        first = first->next;
        return first;
    }
}

NODE insertatend(NODE first, int item) {
    NODE temp = getnode();
    temp->data = item;
    temp->next = NULL;
    if (first == NULL) {
        return temp;
    }
    else {
        NODE cur = first;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = NULL;
        return first;
    }
}

NODE deleteatend(NODE first) {
    if (first == NULL) {
        printf("\nList Empty\n");
        return NULL;
    }
    else if (first->next == NULL) {
        printf("\n[%d] deleted\n", first->data);
        free(first);
        return NULL;
    }
    else {
        NODE cur = first;
        NODE prev = NULL;
        while (cur->next != NULL) {
            prev = cur;
            cur = cur->next;
        }
        printf("\n[%d] deleted\n", cur->data);
        prev->next = NULL;
        return first;
    }
}

NODE insertatindex(NODE first, int item, int pos) {
    NODE temp = getnode();
    temp->data = item;
    if (first == NULL && pos == 1) {
        temp->next = NULL;
        return temp;
    }
    else if (first == NULL) {
        printf("\nInvalid Positon\n");
        return NULL;
    }
    else if (pos == 1) {
        temp->next = first;
        return temp;
    }
    else {
        NODE cur = first;
        NODE prev = NULL;
        int count = 1;
        while (cur != NULL && count != pos) {
            prev = cur;
            cur = cur->next;
            count++;
        }
        temp->next = cur;
        prev->next = temp;
        return first;
    }
}

NODE deleteatindex(NODE first, int pos) {
    if (first == NULL) {
        printf("\nInvalid Position\n");
        return NULL;
    }
    else if (pos == 1) {
        printf("\n[%d] Deleted\n", first->data);
        first = first->data;
        return first;
    }
    else {
        NODE cur = first;
        NODE prev = NULL;
        int count = 1;
        while (cur != NULL && count != pos) {
            prev = cur;
            cur = cur->next;
            count++;
        }
        if (cur == NULL) {
            printf("\nInvalid Position\n");
            return NULL;
        }
        else {
            printf("\n[%d] Deleted\n", cur->data);
            prev->next = cur->next;
            free(cur);
            return first;
        }
    }
}

NODE deletewithinfo(NODE first, int item) {
    if (first == NULL) {
        printf("\nLinked List Empty\n");
        return NULL;
    }
    else if (first->data == item) {
        printf("\n[%d] Deleted at pos = %d\n", first->data, 1);
        first = first->next;
        return first;
    }
    else if (first->next == NULL) {
        printf("\nInvalid Item\n");
        return NULL;
    }
    else {
        NODE cur = first;
        NODE prev = NULL;
        int pos = 1;
        while (cur != NULL && cur->data != item) {
            prev = cur;
            cur = cur->next;
            pos++;
        }
        if (cur == NULL) {
            printf("\nItem does not Exist in Linked List\n");
            return first;
        }
        else {
            printf("\n[%d] Deleted at pos = %d\n", cur->data, pos);
            prev->next = cur->next;
            return first;
        }
    }
}

void main() {
    NODE first = NULL;

    first = insertatfirst(first, 10);
    first = insertatend(first, 30);
    first = insertatindex(first, 20, 2);
    display(first);

    first = deleteatfirst(first);


    searchelement(first, 30);
    // searchelement(first, 20);
    // searchelement(first, 30);

}
