//SORTING ELEMENTS 
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* createList()
 {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(0);
        }

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    return head;
}
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List Elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void sortList(struct Node *head)
 {
    struct Node *current, *index;
    int temp;

    if (head == NULL)
    {
        printf("List is empty. Nothing to sort.\n");
        return;
    }

    for (current = head; current->next != NULL; current = current->next)
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}
void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    struct Node *head = NULL;

    head = createList();

    printf("\nBefore sorting:");
    displayList(head);

    sortList(head);

    printf("\nAfter sorting (ascending order):");
    displayList(head);

    freeList(head);

    return 0;
}
