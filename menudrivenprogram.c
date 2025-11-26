//MENU DRIVEN PROGRAM
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == SIZE - 1) {
        printf("\nQueue is Full (Overflow)!\n");
    } else {
        printf("Enter element to insert: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("Inserted %d into queue.\n", item);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty (Underflow)!\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void traverse() {
    int i;
    if (front == -1) {
        printf("\nQueue is Empty!\n");
    } else {
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
