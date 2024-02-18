#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insert(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void display(struct Node* head);
void search(struct Node* head, int key);

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    do {
        printf("\e[1;1H\e[2J");
        printf("\nLinked List Operations:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traverse\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\e[1;1H\e[2J");

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                printf("\e[1;1H\e[2J");
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                printf("\e[1;1H\e[2J");
                break;
            case 3:
                display(head);
                usleep(3000000);
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                search(head, key);
                printf("\e[1;1H\e[2J");
                break;
            case 5:
                printf("\e[1;1H\e[2J");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        printf("\e[1;1H\e[2J");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int data) {
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
        printf("\e[1;1H\e[2J");
        usleep(1000000);
        return;
    }
    prev->next = temp->next;
    free(temp);
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

void search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
        position++;
    }
    if (temp == NULL) {
        printf("\e[1;1H\e[2J");
        printf("Element %d not found in the list.\n", key);
        usleep(3000000);
    } else {
        printf("\e[1;1H\e[2J");
        printf("Element %d found at position %d.\n", key, position);
        usleep(3000000);
    }
}