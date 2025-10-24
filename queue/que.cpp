#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue Operation
void enqueue(int value) {
    if(rear == SIZE-1) {
        printf("Queue is Full!\n");
    } else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d added to queue\n", value);
    }
}

// Dequeue Operation  
int dequeue() {
    if(front == -1) {
        printf("Queue is Empty!\n");
        return -1;
    } else {
        int value = queue[front];
        front++;
        if(front > rear) { // Reset when queue becomes empty
            front = rear = -1;
        }
        return value;
    }
}

// Display Queue
void display() {
    if(front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue: ");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}