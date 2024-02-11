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

// Function to insert a new node at the end of the linked list
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

    // Insertion
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    // Display
    display(head);

    // Deletion
    deleteNode(&head, 20);
    deleteNode(&head, 50); // Element not in the list

    // Display after deletion
    display(head);

    // Search
    search(head, 30);
    search(head, 50); // Element not in the list

    return 0;
}
