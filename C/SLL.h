// Start Singly Linked List
#ifndef SLL_H
#define SLL_H

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);

// Prototypes for SLL
void clearScreenSLL();
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);
void deleteANode(struct Node** head, int key, int deleteANode);
void deleteFirstNode(struct Node** head, int key, int deleteFirst);
void deleteLastNode(struct Node** head);
void deleteAtPosition(struct Node** head, int position);
void deleteAllNodes(struct Node** head);
void traverse(struct Node* head);
void search(struct Node* head, int key);

void singlyLL() {
    struct Node* head = NULL;
    int choice, choiceInsertion, choiceDeletion, choiceTraverse, choiceSearch, data, key, position;
    clearScreenSLL();
    do {
        printf("     Please choose an operations");
        printf("\n");
        printf(" _________________________________ \n");
        printf("/                                 \\\n");
        printf("|        Operations Menu:         |\n");
        printf("|     Press '1' for Insertion     |\n");
        printf("|     Press '2' for Deletion      |\n");
        printf("|     Press '3' to Traverse       |\n");
        printf("|     Press '4' to Search         |\n");
        printf("|     Press '5' to go Back        |\n");
        printf("\\_________________________________/\n");
        printf("\n");
        printf("   Enter your choice of number: ");
        if(scanf("%d", &choice) != 1) {
            clearScreenSLL();
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            clearScreenSLL();
            while(getchar() != '\n');
            continue;
        }
        if(choice < 1 || choice > 5) {
            clearScreenSLL();
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
            usleep(2e+6);
            clearScreenSLL();
            continue;
        }
        switch(choice) {
            case 1:
                clearScreenSLL();
                // Insertion
                if(head == NULL) {
                    printf("\nList is empty. Nothing to insert.\n");
                    usleep(2e+6);
                    clearScreenSLL();
                    break;
                }
                do {
                    printf("\n1. Insert a Node at Beginning\n");
                    printf("2. Insert a Node at End\n");
                    printf("3. Insert at a specified Node\n");
                    printf("4. Return to menu\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &choiceInsertion) != 1) {
                        clearScreenSLL();
                        printf("Invalid input. Please enter a number.\n");
                        usleep(2e+6);
                        clearScreenSLL();
                        while(getchar() != '\n');
                        continue;
                    }
                    if(choiceInsertion < 1 || choiceInsertion > 4) {
                        clearScreenSLL();
                        printf("Invalid choice. Please choose a number between 1 and 4.\n");
                        usleep(2e+6);
                        clearScreenSLL();
                        continue;
                    }
                    switch(choiceInsertion) {
                        case 1:
                            printf("\nEnter the item which you want to insert: ");
                            scanf("%d", &data);
                            insertAtBeginning(&head, data);
                            break;
                        case 2:
                            printf("\nEnter the item which you want to insert: ");
                            scanf("%d", &data);
                            insertAtEnd(&head, data);
                            break;
                        case 3:
                            printf("\nEnter the item which you want to insert: ");
                            scanf("%d", &data);
                            printf("\nEnter the position of the node to insert: ");
                            scanf("%d", &position);
                            insertAtPosition(&head, data, position);
                            break;
                        case 4:
                            clearScreenSLL();
                            break;
                    }
                } while(choiceInsertion != 4);
                break;
            case 2:
                clearScreenSLL();
                // Deletion
                if(head == NULL) {
                    printf("\nList is empty. Nothing to delete.\n");
                    usleep(2e+6);
                    clearScreenSLL();
                    break;
                }
                do {
                    printf("\n1. Delete a Node\n");
                    printf("2. Delete a Node at the Beginning\n");
                    printf("3. Delete a Node at the End\n");
                    printf("4. Delete at a specified Node\n");
                    printf("5. Delete all Nodes\n");
                    printf("6. Back\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &choiceDeletion) != 1) {
                        clearScreenSLL();
                        printf("Invalid input. Please enter a number.\n");
                        usleep(2e+6);
                        clearScreenSLL();
                        while(getchar() != '\n');
                        continue;
                    }
                    if(choiceDeletion < 1 || choiceDeletion > 6) {
                        clearScreenSLL();
                        printf("Invalid choice. Please choose a number between 1 and 6.\n");
                        usleep(2e+6);
                        clearScreenSLL();
                        continue;
                    }
                    switch(choiceDeletion) {
                        case 1:
                            printf("\nEnter the node to delete: ");
                            scanf("%d", &key);
                            deleteANode(&head, key, 0);
                            break;
                        case 2:
                            deleteFirstNode(&head, 0, 1);
                            break;
                        case 3:
                            deleteLastNode(&head);
                            break;
                        case 4:
                            printf("\nEnter the position of the node to delete: ");
                            scanf("%d", &position);
                            deleteAtPosition(&head, position);
                            break;
                        case 5:
                            deleteAllNodes(&head);
                            break;
                        case 6:
                            clearScreenSLL();
                            break;
                    }
                } while(choiceDeletion != 6);
                break;
            case 3:
                clearScreenSLL();
                // Traverse
                do {
                    printf("\n1. Append List\n");
                    printf("2. Traverse\n");
                    printf("3. Back\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &choiceTraverse) != 1) {
                        clearScreenSLL();
                        printf("Invalid input. Please enter a number.\n");
                        usleep(2e+6);
                        clearScreenSLL();
                        while(getchar() != '\n');
                        continue;
                    }
                    if(choiceTraverse < 1 || choiceTraverse > 3) {
                        clearScreenSLL();
                        printf("Invalid choice. Please choose a number between 1 and 3.\n");
                        usleep(2e+6);
                        clearScreenSLL();
                        continue;
                    }
                    switch(choiceTraverse) {
                        case 1:
                            printf("\nEnter the node: ");
                            scanf("%d", &data);
                            insertAtBeginning(&head, data);
                            break;
                        case 2:
                            clearScreenSLL();
                            traverse(head);
                            printf("Press any key to go back...\n");
                            getchar();
                            char input = getchar();
                            clearScreenSLL();
                            break;
                        case 3:
                            clearScreenSLL();
                            break;
                    }
                } while(choiceTraverse != 3);
                break;
            case 4:
                clearScreenSLL();
                // Search
                if(head == NULL) {
                    printf("\nList is empty. Nothing to search.\n");
                    usleep(2e+6);
                    clearScreenSLL();
                    break;
                }
                do {
                    printf("1. Search\n");
                    printf("2. Back\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &choiceSearch) != 1) {
                        clearScreenSLL();
                        printf("Invalid input. Please enter a number.\n");
                        usleep(2e+6);
                        clearScreenSLL();
                        while(getchar() != '\n');
                        continue;
                    }
                    if(choiceSearch < 1 || choiceSearch > 2) {
                        clearScreenSLL();
                        printf("Invalid choice. Please choose a number between 1 and 2.\n");
                        usleep(2e+6);
                        clearScreenSLL();
                        continue;
                    }
                    switch(choiceSearch) {
                        case 1:
                            clearScreenSLL();
                            printf("\nEnter the node to search: ");
                            scanf("%d", &key);
                            search(head, key);
                            break;
                        case 2:
                            clearScreenSLL();
                            break;
                    }
                } while(choiceSearch != 2);
                break;
            case 5:
                clearScreenSLL();
                break;
        }
    } while(choice != 5);
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        usleep(2e+6);
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void clearScreenSLL() {
    printf("\e[1;1H\e[2J");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode -> next = *head;
    *head = newNode;
    printf("\nNode inserted.\n");
    usleep(2e+6);
    clearScreenSLL();
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp -> next != NULL) {
            temp = temp->next;
        }
        temp -> next = newNode;
    }
    printf("\nNode inserted.\n");
    usleep(2e+6);
    clearScreenSLL();
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        usleep(1e+6);
        clearScreenSLL();
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
            usleep(2e+6);
            clearScreenSLL();
            return;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
        printf("\nNode inserted.\n");
        usleep(2e+6);
        clearScreenSLL();
    }
}

void deleteANode(struct Node** head, int key, int deleteANode) {
    if (*head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(deleteANode){
        *head = temp->next;
        free(temp);
        printf("\nNode deleted.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    while (temp != NULL && temp -> data != key) {
        prev = temp;
        temp = temp -> next;
    }
    if (temp == NULL) {
        printf("Node %d not found in the list.\n", key);
        usleep(2e+6);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void deleteFirstNode(struct Node** head, int key, int deleteFirst) {
    if (*head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(deleteFirst){
        *head = temp -> next;
        free(temp);
        printf("\nNode deleted.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    while (temp != NULL && temp -> data != key) {
        prev = temp;
        temp = temp -> next;
    }
    if (temp == NULL) {
        printf("Node %d not found in the list.\n", key);
        usleep(2e+6);
        return;
    }
    if (prev == NULL) {
        *head = temp -> next;
    } else {
        prev -> next = temp -> next;
    }
    free(temp);
}

void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp -> next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
    printf("\nNode deleted.\n");
    usleep(2e+6);
    clearScreenSLL();
}

void deleteAtPosition(struct Node** head, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("\nNode deleted.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("\nNode deleted.\n");
    usleep(2e+6);
    clearScreenSLL();
}

void deleteAllNodes(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        usleep(2e+6);
        clearScreenSLL();
        return;
    }
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("\nAll nodes deleted.\n");
    usleep(2e+6);
    clearScreenSLL();
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    printf("Linked Lists: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    int found = 0;
    clearScreenSLL();
    printf("Node %d found at position: ", key);
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
    usleep(2e+6);
    printf("Press any key to go back...\n");
    getchar();
    char input = getchar();
    clearScreenSLL();
}
#endif /* SLL_H */
// End Singly Linked List
