#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a new node at a specific position in the linked list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
    } else {
        struct Node* newNode = createNode(data);
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node with a given key from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a key in the linked list
void search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
        position++;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
    } else {
        printf("Element %d found at position %d.\n", key, position);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, key, position;

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7);

    return 0;
}
