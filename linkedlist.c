// Linked list operations
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than zero.\n");
        return;
    }

    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    printf("\nLinked list created successfully.\n");
}

void insertNode(int data, int position) {
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;

        for (i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Position out of range.\n");
            free(newNode);
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Node inserted successfully.\n");
}

void deleteNode(int position) {
    struct Node *temp, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    if (position == 1) {
        head = head->next;
        free(temp);
    } else {
        prev = NULL;

        for (i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Position out of range.\n");
            return;
        }

        prev->next = temp->next;
        free(temp);
    }

    printf("Node deleted successfully.\n");
}

// Display the linked list
void traverseList() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Traverse List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList(n);
            break;

        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insertNode(data, pos);
            break;

        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteNode(pos);
            break;

        case 4:
            traverseList();
            break;

        case 5:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
