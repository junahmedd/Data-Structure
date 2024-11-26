#include <stdio.h>
#include <stdlib.h>

int qsize = 4;
int front = 0;
int rear = -1;

void enqueue(int q[qsize], int *r, int item) {
    if (*r == qsize - 1) {
        printf("Queue Overflow\n");
    }
    else {
        int j = *r;
        while (j >= 0 && item < q[j]) {
            q[j + 1] = q[j];
            j--;
        }
        q[j + 1] = item;
        *r += 1;
    }
}

int dequeue(int q[qsize], int *f, int *r) {
    if (*f > *r) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        int item = q[(*f)++];
        return item;
    }
}

void display(int q[qsize], int *f, int *r) {
    if (*f > *r) {
        printf("Queue Underflow\n");
    }
    else {
        printf("Queue Elements are\n");
        for (int i = *f; i <= *r; i++) {
            printf("%d\t", q[i]);
        }
    }
}

void main() {
    int q[qsize], choice, item;
    while (1) {
        printf("\nEnter choice\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1 : 
                printf("enter item");
                scanf("%d", &item);
                enqueue(q, &rear, item);
                break;
            case 2 :
                item = dequeue(q, &front, &rear);
                printf("%d deleted\n", item);
                break;
            case 3 :
                display(q, &front, &rear);
                break;
            case 4 :
                exit(0);
            default : printf("Invalid\n");
            break;  
        }
    }
}
