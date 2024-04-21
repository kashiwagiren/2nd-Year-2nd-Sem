// Start Doubly Linked List
#ifndef DLL_H
#define DLL_H

struct Nodes {
    int data;
    struct Nodes* next;
    struct Nodes* prev;
};

struct Nodes* createNodes(int data);

// Prototypes for DLL
void clearScreenDLL();
void insertAtBeginningDoubly(struct Nodes** head, int data);
void insertAtEndDoubly(struct Nodes** head, int data);
void insertAtPositionDoubly(struct Nodes** head, int data, int position);
void deleteANodeDoubly(struct Nodes** head, int key);
void deleteFirstNodeDoubly(struct Nodes** head);
void deleteLastNodeDoubly(struct Nodes** head);
void deleteAtPositionDoubly(struct Nodes** head, int position);
void deleteAllNodesDoubly(struct Nodes** head);
void traverseForwardDoubly(struct Nodes* head);
void traverseBackwardDoubly(struct Nodes* head);
void searchDoubly(struct Nodes* head, int key);

void doublyLL() {
    struct Nodes* head = NULL;
    int choice, choiceInsertion, choiceDeletion, choiceTraverse, choiceSearch, data, key, position;
    clearScreenDLL();
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
            clearScreenDLL();
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            clearScreenDLL();
            while(getchar() != '\n');
            continue;
        }
        if(choice < 1 || choice > 5) {
            clearScreenDLL();
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
            usleep(2e+6);
            clearScreenDLL();
            continue;
        }
        switch(choice) {
            case 1:
                clearScreenDLL();
                // Insertion
                if(head == NULL) {
                    printf("\nList is empty. Nothing to insert.\n");
                    usleep(2e+6);
                    clearScreenDLL();
                    break;
                }
                do {
                    printf("\n1. Insert a Node at Beginning\n");
                    printf("2. Insert a Node at End\n");
                    printf("3. Insert at a specified Node\n");
                    printf("4. Return to menu\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &choiceInsertion) != 1) {
                        clearScreenDLL();
                        printf("Invalid input. Please enter a number.\n");
                        usleep(2e+6);
                        clearScreenDLL();
                        while(getchar() != '\n');
                        continue;
                    }
                    if(choiceInsertion < 1 || choiceInsertion > 4) {
                    clearScreenDLL();
                    printf("Invalid choice. Please choose a number between 1 and 4.\n");
                    usleep(2e+6);
                    clearScreenDLL();
                    continue;
                    }
                    switch(choiceInsertion) {
                        case 1:
                            printf("\nEnter the item which you want to insert: ");
                            scanf("%d", &data);
                            insertAtBeginningDoubly(&head, data);
                            break;
                        case 2:
                            printf("\nEnter the item which you want to insert: ");
                            scanf("%d", &data);
                            insertAtEndDoubly(&head, data);
                            break;
                        case 3:
                            printf("\nEnter the item which you want to insert: ");
                            scanf("%d", &data);
                            printf("\nEnter the position of the node to insert: ");
                            scanf("%d", &position);
                            insertAtPositionDoubly(&head, data, position);
                            break;
                        case 4: 
                            clearScreenDLL();
                            break;
                    }
                } while(choiceInsertion != 4);
                break;
            case 2:
                clearScreenDLL();
                // Deletion
                if(head == NULL) {
                    printf("\nList is empty. Nothing to delete.\n");
                    usleep(2e+6);
                    clearScreenDLL();
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
                        clearScreenDLL();
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
                            deleteANodeDoubly(&head, key);
                            break;
                        case 2:
                            deleteFirstNodeDoubly(&head);
                            break;
                        case 3:
                            deleteLastNodeDoubly(&head);
                            break;
                        case 4:
                            printf("\nEnter the position of the node to delete: ");
                            scanf("%d", &position);
                            deleteAtPositionDoubly(&head, position);
                            break;
                        case 5:
                            deleteAllNodesDoubly(&head);
                            break;
                        case 6:
                            clearScreenDLL();
                            break;
                    }
                } while(choiceDeletion != 6);
                break;
            case 3:
                clearScreenDLL();
                // Traverse
                do {
                    printf("\n1. Append List\n");
                    printf("2. Traverse\n");
                    printf("3. Back\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &choiceTraverse) != 1) {
                        clearScreenDLL();
                        printf("Invalid input. Please enter a number.\n");
                        usleep(2e+6);
                        clearScreenDLL();
                        while(getchar() != '\n');
                        continue;
                    }
                    if(choiceTraverse < 1 || choiceTraverse > 3) {
                        clearScreenDLL();
                        printf("Invalid choice. Please choose a number between 1 and 3.\n");
                        usleep(2e+6);
                        clearScreenDLL();
                        continue;
                    }
                    switch(choiceTraverse) {
                        case 1:
                            printf("\nEnter the node: ");
                            scanf("%d", &data);
                            insertAtBeginningDoubly(&head, data);
                            break;
                        case 2:
                            clearScreenDLL();
                            traverseForwardDoubly(head);
                            printf("Press any key to go back...\n");
                            getchar();
                            char input = getchar();
                            clearScreenDLL();
                            break;
                        case 3:
                            clearScreenDLL();
                            break;
                    }
                } while(choiceTraverse != 3);
                break;
            case 4:
                clearScreenDLL();
                // Search
                if(head == NULL) {
                    printf("\nList is empty. Nothing to search.\n");
                    usleep(2e+6);
                    clearScreenDLL();
                    break;
                }
                do {
                    printf("1. Search\n");
                    printf("2. Back\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &choiceSearch) != 1) {
                        clearScreenDLL();
                        printf("Invalid input. Please enter a number.\n");
                        usleep(2e+6);
                        clearScreenDLL();
                        while(getchar() != '\n');
                        continue;
                    }
                    if(choiceSearch < 1 || choiceSearch > 2) {
                        clearScreenDLL();
                        printf("Invalid choice. Please choose a number between 1 and 2.\n");
                        usleep(2e+6);
                        clearScreenDLL();
                        continue;
                    }
                    switch(choiceSearch) {
                        case 1:
                            clearScreenDLL();
                            printf("\nEnter the node to search: ");
                            scanf("%d", &key);
                            searchDoubly(head, key);
                            break;
                        case 2:
                            clearScreenDLL();
                            break;
                    }
                } while(choiceSearch != 2);
                break;
            case 5:
                clearScreenDLL();
        }
    } while(choice != 5);
}

struct Nodes* createNodes(int data) {
    struct Nodes* newNodes = (struct Nodes*)malloc(sizeof(struct Nodes));
    if(newNodes == NULL) {
        printf("Memory allocation failed.\n");
        usleep(2e+6);
        exit(1);
    }
    newNodes -> data = data;
    newNodes -> next = NULL;
    return newNodes;
}

void clearScreenDLL() {
    printf("\e[1;1H\e[2J");
}

void insertAtBeginningDoubly(struct Nodes** head, int data) {
    struct Nodes* newNodes = createNodes(data);
    if(*head == NULL) {
        *head = newNodes;
        return;
    }
    newNodes -> next = *head;
    (*head) -> prev = newNodes;
    *head = newNodes;
    printf("\nNode inserted.\n");
    usleep(2e+6);
    clearScreenDLL();
}

void insertAtEndDoubly(struct Nodes** head, int data) {
    struct Nodes* newNodes = createNodes(data);
    struct Nodes* temp = *head;
    if(*head == NULL) {
        *head = newNodes;
        return;
    }
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNodes;
    newNodes -> prev = temp;
    printf("\nNode inserted.\n");
    usleep(2e+6);
    clearScreenDLL();
}

void insertAtPositionDoubly(struct Nodes** head, int data, int position) {
    if(position < 1) {
        printf("Invalid position.\n");
        usleep(1e+6);
        clearScreenDLL();
        return;
    }

    struct Nodes* newNodes = createNodes(data);
    struct Nodes* temp = *head;
    int count = 1;

    if(position == 1) {
        insertAtBeginningDoubly(head, data);
        return;
    }

    while(temp != NULL && count < position) {
        temp = temp -> next;
        count++;
    }

    if(temp == NULL) {
        printf("Position exceeds the length of the list.\n");
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    newNodes -> next = temp;
    newNodes -> prev = temp -> prev;
    temp -> prev -> next = newNodes;
    temp -> prev = newNodes;
}

void deleteANodeDoubly(struct Nodes** head, int key) {
    struct Nodes* temp = *head;

    if(*head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    while(temp != NULL && temp -> data != key) {
        temp = temp -> next;
    }

    if(temp == NULL) {
        printf("Node with key %d not found.\n", key);
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    if(temp -> prev != NULL) {
        temp -> prev -> next = temp -> next;
    }
    if(temp -> next != NULL) {
        temp -> next -> prev = temp -> prev;
    }

    if(temp == *head) {
        *head = temp -> next;
    }

    free(temp);
}

void deleteFirstNodeDoubly(struct Nodes** head) {
    if(*head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    struct Nodes* temp = *head;
    *head = (*head) -> next;
    if(*head != NULL) {
        (*head) -> prev = NULL;
    }
    free(temp);
}

void deleteLastNodeDoubly(struct Nodes** head) {
    if(*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    struct Nodes* temp = *head;

    if(temp -> next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> prev -> next = NULL;
    free(temp);
}

void deleteAtPositionDoubly(struct Nodes** head, int position) {
    if(*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    if(position < 1) {
        printf("Invalid position.\n");
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    struct Nodes* temp = *head;
    int count = 1;

    while(temp != NULL && count < position) {
        temp = temp -> next;
        count++;
    }

    if(temp == NULL) {
        printf("Position exceeds the length of the list.\n");
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    if(temp -> prev != NULL) {
        temp -> prev -> next = temp -> next;
    }
    if(temp -> next != NULL) {
        temp -> next -> prev = temp -> prev;
    }

    if(temp == *head) {
        *head = temp -> next;
    }
    free(temp);
}

void deleteAllNodesDoubly(struct Nodes** head) {
    struct Nodes* current = *head;
    struct Nodes* next;

    while(current != NULL) {
        next = current -> next;
        free(current);
        current = next;
    }

    *head = NULL;
    printf("All nodes deleted.\n");
    usleep(2e+6);
    clearScreenDLL();
}

void traverseForwardDoubly(struct Nodes* head) {
    struct Nodes* current = head;

    if(current == NULL) {
        printf("List is empty.\n");
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    printf("Linked Lists: ");
    while(current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

void traverseBackwardDoubly(struct Nodes* head) {
    struct Nodes* current = head;

    if(current == NULL) {
        printf("List is empty.\n");
        usleep(2e+6);
        clearScreenDLL();
        return;
    }

    while(current -> next != NULL) {
        current = current -> next;
    }

    printf("Linked Lists in reverse order: ");
    while(current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> prev;
    }
    printf("NULL\n");
}

void searchDoubly(struct Nodes* head, int key) {
    struct Nodes* current = head;
    int position = 1;
    bool found = false;

    if(current == NULL) {
        printf("List is empty. Cannot search.\n");
        return;
    }

    while(current != NULL) {
        if(current->data == key) {
            found = true;
            break;
        }

        current = current -> next;
        position++;
    }

    if(found) {
        printf("Node with key %d found at position %d.\n", key, position);
    } else {
        printf("Node with key %d not found in the list.\n", key);
    }
}

#endif /* DLL_H */
// End Doubly Linked List 
