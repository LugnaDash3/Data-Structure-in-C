//SEARCHING ELEMENT 
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
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int i;
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
void searchElement(struct Node *head, int key)
{
    int pos = 1;
    int found = 0;

    while (head != NULL)
    {
        if (head->data == key)
            {
            printf("\nElement %d found at position %d.\n", key, pos);
            found = 1;
            break;
        }
        head = head->next;
        pos++;
    }

    if (!found)
        printf("\nElement %d not found in the list.\n", key);
}
int main()
 {
    struct Node *head = NULL;
    int key;

    head = createList();
    displayList(head);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    searchElement(head, key);

    return 0;
}
