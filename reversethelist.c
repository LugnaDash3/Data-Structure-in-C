//REVERSE THE LIST 
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

    for (i = 0; i < n; i++)
        {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
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
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List Elements: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct Node* reverseList(struct Node *head)
 {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
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

    printf("\nOriginal list:");
    displayList(head);

    head = reverseList(head);

    printf("\nReversed list:");
    displayList(head);

    freeList(head);

    return 0;
}
