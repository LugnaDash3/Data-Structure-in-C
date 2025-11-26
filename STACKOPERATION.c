//STACK OPERATION 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node *stack;

int IsEmpty(stack);
stack Push(stack, int);
stack Pop(stack);
void Display(stack);

int main() {
    stack s = NULL;
    int x;
    char ch = '1';

    while (ch != '4') {
        printf("\n 1 - PUSH");
        printf("\n 2 - POP");
        printf("\n 3 - DISPLAY");
        printf("\n 4 - QUIT");
        printf("\n\nEnter your choice: ");

        scanf(" %c", &ch);  

        switch (ch) {
            case '1':
                printf("\nEnter the element to be pushed: ");
                scanf("%d", &x);
                s = Push(s, x);
                break;

            case '2':
                s = Pop(s);
                break;

            case '3':
                Display(s);
                break;

            case '4':
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nWrong choice! Try Again.\n");
        }
    }

    return 0;
}

int IsEmpty(stack s) {
    return (s == NULL);
}

stack Push(stack s, int x) {
    stack temp = (stack)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\nOut of memory space!");
        exit(0);
    }
    temp->info = x;
    temp->next = s;
    s = temp;
    return s;
}

stack Pop(stack s) {
    stack temp;
    int x;

    if (IsEmpty(s)) {
        printf("\nStack is empty, cannot pop!\n");
        return s;   
    }

    temp = s;
    x = s->info;
    printf("\nPopped element is: %d\n", x);
    s = s->next;
    free(temp);

    return s;
}

void Display(stack s) {
    stack ptr = s;

    if (IsEmpty(s)) {
        printf("\nStack is empty\n");
        return;
    }

    printf("\nThe elements in the stack are:\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->info);
        ptr = ptr->next;
    }
}
