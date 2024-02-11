#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

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

void deleteFirstOccurrence(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void deleteAllOccurrences(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current != NULL) {
        if (current->data == key) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            current = prev == NULL ? *head : prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    displayReverse(head->next);
    printf("%d -> ", head->data);
}

void search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    int found = 0;
    printf("Element %d found at positions: ", key);
    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d ", position);
            found = 1;
        }
        temp = temp->next;
        position++;
    }
    if (!found) {
        printf("Not found");
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key, position;
    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First Occurrence\n");
        printf("5. Delete All Occurrences\n");
        printf("6. Display\n");
        printf("7. Display Reverse\n");
        printf("8. Search\n");
        printf("9. Exit\n");
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
                deleteFirstOccurrence(&head, key);
                break;
            case 5:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                deleteAllOccurrences(&head, key);
                break;
            case 6:
                display(head);
                break;
            case 7:
                printf("Linked List in Reverse: ");
                displayReverse(head);
                printf("NULL\n");
                break;
            case 8:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 9.\n");
        }
    } while (choice != 9);
    return 0;
}
