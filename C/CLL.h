// Start Circular Linked List
#ifndef CLL_H
#define CLL_H

struct NodeCircular {
    int data;
    struct NodeCircular* next;
};

struct NodeCircular* createNodeCircular(int data);

// Prototypes for CLL
void clearScreenCLL();
void insertAtBeginningCircular(struct NodeCircular** head, int data);
void insertAtEndCircular(struct NodeCircular** head, int data);
void deleteFromBeginningCircular(struct NodeCircular** head);
void deleteFromEndCircular(struct NodeCircular** head);
void searchCircular(struct NodeCircular* head, int key);
void traverseCircular(struct NodeCircular* head);

void circularLL() {
    struct NodeCircular* head = NULL;
    int choice, data, key;

    do {
        clearScreenCLL();
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Search\n");
        printf("6. Traverse\n");
        printf("7. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtBeginningCircular(&head, data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtEndCircular(&head, data);
                break;
            case 3:
                deleteFromBeginningCircular(&head);
                break;
            case 4:
                deleteFromEndCircular(&head);
                break;
            case 5:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                searchCircular(head, key);
                break;
            case 6:
                clearScreenCLL();
                traverseCircular(head);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7);
}

void clearScreenCLL() {
    printf("\e[1;1H\e[2J");
}

struct NodeCircular* createNodeCircular(int data) {
    struct NodeCircular* newNodeCircular = (struct NodeCircular*)malloc(sizeof(struct NodeCircular));
    if(newNodeCircular == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNodeCircular->data = data;
    newNodeCircular->next = NULL;
    return newNodeCircular;
}

void insertAtBeginningCircular(struct NodeCircular** head, int data) {
    struct NodeCircular* newNodeCircular = createNodeCircular(data);
    if (*head == NULL) {
        *head = newNodeCircular;
        newNodeCircular->next = *head;
    } else {
        struct NodeCircular* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNodeCircular;
        newNodeCircular->next = *head;
        *head = newNodeCircular;
    }
}

void insertAtEndCircular(struct NodeCircular** head, int data) {
    struct NodeCircular* newNodeCircular = createNodeCircular(data);
    if (*head == NULL) {
        *head = newNodeCircular;
        newNodeCircular->next = *head;
    } else {
        struct NodeCircular* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNodeCircular;
        newNodeCircular->next = *head;
    }
}

void deleteFromBeginningCircular(struct NodeCircular** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct NodeCircular* temp = *head;
    struct NodeCircular* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    if (*head == (*head)->next) {
        *head = NULL;
    } else {
        *head = (*head)->next;
        last->next = *head;
    }

    free(temp);
}

void deleteFromEndCircular(struct NodeCircular** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct NodeCircular* temp = *head;
    struct NodeCircular* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        *head = NULL;
    } else {
        prev->next = *head;
    }

    free(temp);
}

void searchCircular(struct NodeCircular* head, int key) {
    if (head == NULL) {
        printf("List is empty. Cannot search.\n");
        return;
    }

    struct NodeCircular* current = head;
    bool found = false;
    do {
        if (current->data == key) {
            found = true;
            break;
        }
        current = current->next;
    } while (current != head);

    if (found) {
        printf("Node with key %d found in the list.\n", key);
    } else {
        printf("Node with key %d not found in the list.\n", key);
    }
}

void traverseCircular(struct NodeCircular* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct NodeCircular* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("NULL\n\n");
    usleep(2e+6);
    printf("Press any key to go back...\n");
    getchar();
    char input = getchar();
    clearScreenCLL();
}

#endif /* CLL_H */
// End Circular Linked List