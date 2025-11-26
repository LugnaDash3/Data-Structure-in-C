//MERGING OF LIST 
#include <stdio.h>
#include <stdlib.h>

struct link
{
    int info;
    struct link *next;
};

void CreateList(struct link *node);
void Merge(struct link *node1, struct link *node2, struct link *node3);
void Display(struct link *node);

int main()
{
    struct link *node1, *node2, *node3;

    node1 = (struct link *)malloc(sizeof(struct link));
    node2 = (struct link *)malloc(sizeof(struct link));
    node3 = (struct link *)malloc(sizeof(struct link));

    if (!node1 || !node2 || !node3)
    {
        printf("\nOut of memory space\n");
        exit(0);
    }

    printf("\nCreating first list\n");
    CreateList(node1);

    printf("\nCreating second list\n");
    CreateList(node2);

    printf("\nMerging both lists...\n");
    Merge(node1, node2, node3);

    printf("\nFirst list:\n");
    Display(node1);

    printf("\nSecond list:\n");
    Display(node2);

    printf("\nMerged list:\n");
    Display(node3);

    return 0;
}

void CreateList(struct link *node)
{
    char ch;
    int i = 1;

    do
    {
        printf("\nEnter the value for node %d: ", i);
        scanf("%d", &node->info);
        node->next = NULL;
        i++;

        printf("\nPress 'n' to quit, any other key to continue: ");
        scanf(" %c", &ch);
        if (ch != 'n')
        {
            node->next = (struct link *)malloc(sizeof(struct link));
            node = node->next;
        }
    }
    while (ch != 'n');
}

void Merge(struct link *node1, struct link *node2, struct link *node3)
{
    struct link *temp = node3;

    while (node1 != NULL)
        {
        temp->info = node1->info;
        node1 = node1->next;
        if (node1 != NULL || node2 != NULL)
        {
            temp->next = (struct link *)malloc(sizeof(struct link));
            temp = temp->next;
        }
    }

    while (node2 != NULL)
        {
        temp->info = node2->info;
        node2 = node2->next;
        if (node2 != NULL)
         {
            temp->next = (struct link *)malloc(sizeof(struct link));
            temp = temp->next;
        }
    }

    temp->next = NULL;
}

void Display(struct link *node)
{
    while (node != NULL)
    {
        printf("%d ", node->info);
        node = node->next;
    }
    printf("\n");
}
