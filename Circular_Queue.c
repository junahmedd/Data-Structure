#include <stdio.h>
#include <stdlib.h>

int front = 0, rear = -1, qsize = 4, count = 0;

void enqueue(int q[qsize], int item) {
    if (count == qsize) {
        printf("Queue Overflow\n");
    }
    else {
        rear = (rear + 1) % qsize;
        q[rear] = item;
        count++;
    }
}

int dequeue(int q[qsize]) {
    if (count == 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        int item = q[front];
        front = (front + 1) % qsize;
        count--;
        return item;
    }
}

void display(int q[qsize]) {
    if (count == 0) {
        printf("Queue Empty\n");
    }
    else {
        printf("Queue Elements are\n");
        int temp = front;
        for (int i = 1; i <= count; i++) {
            printf("%d\t", q[temp]);
            temp = (temp + 1) % qsize;
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
                enqueue(q, item);
                break;
            case 2 :
                item = dequeue(q);
                printf("%d deleted\n", item);
                break;
            case 3 :
                display(q);
                break;
            case 4 :
                exit(0);
            default : printf("Invalid\n");
            break;  
        }
    }
}
