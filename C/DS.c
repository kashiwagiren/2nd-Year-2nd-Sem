#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);
void deleteFirstElement(struct Node** head, int key, int deleteFirst);
void deleteAtPosition(struct Node** head, int position);
void deleteAllElements(struct Node** head);
void deleteLastElement(struct Node** head);
void traverse(struct Node* head);
void traverseInReverse(struct Node* head);
void search(struct Node* head, int key);

int main() {
    struct Node* head = NULL;
    int choice, choice1, choice2, data, key, position;
    do {
        printf("\e[1;1H\e[2J");
        printf("\n");
        printf(" _________________________________ \n");
        printf("/                                 \\\n");
        printf("|        Operations Menu:         |\n");
        printf("|     Press '1' for Insertion     |\n");
        printf("|     Press '2' for Deletion      |\n");
        printf("|     Press '3' to Traverse       |\n");
        printf("|     Press '4' to Search         |\n");
        printf("|     Press '5' to Exit           |\n");
        printf("\\_________________________________/\n");
        printf("\n");
        printf("   Enter your choice of number: ");
        scanf("%d", &choice);
        printf("\e[1;1H\e[2J");
        switch (choice) {
            case 1:
                if (head == NULL) {
                    printf("\nList is empty. Nothing to insert.\n");
                    usleep(2000000);
                    printf("\e[1;1H\e[2J");
                    break;
                }
                do {
                    printf("\n1. Insert at Beginning\n");
                    printf("2. Insert at End\n");
                    printf("3. Insert at Position\n");
                    printf("4. Return to menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice1);
                    printf("\e[1;1H\e[2J");
                    switch (choice1) {
                        case 1:
                            printf("\nEnter the element to insert: ");
                            scanf("%d", &data);
                            insertAtBeginning(&head, data);
                            break;
                        case 2:
                            printf("\nEnter the element to insert: ");
                            scanf("%d", &data);
                            insertAtEnd(&head, data);
                            break;
                        case 3:
                            printf("\nEnter the element to insert: ");
                            scanf("%d", &data);
                            printf("\nEnter the position to insert: ");
                            scanf("%d", &position);
                            insertAtPosition(&head, data, position);
                            break;
                        case 4:
                            printf("\e[1;1H\e[2J");
                            break;
                        default:
                            printf("\e[1;1H\e[2J");
                            printf("Invalid choice! Please enter a number between 1 and 4\n");
                    }
                } while (choice1 != 4);
                break;
            case 2:
                if (head == NULL) {
                    printf("\nList is empty. Nothing to delete.\n");
                    usleep(2000000);
                    printf("\e[1;1H\e[2J");
                    break;
                }
                do {
                    printf("\n1. Delete an Element\n");
                    printf("2. Delete Element at Beginning\n");
                    printf("3. Delete Element at Position\n");
                    printf("4. Delete All Elements\n");
                    printf("5. Delete Element at the End\n");
                    printf("6. Return to menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice1);
                    printf("\e[1;1H\e[2J");
                    switch (choice1) {
                        case 1:
                            printf("\nEnter the element to delete: ");
                            scanf("%d", &key);
                            deleteFirstElement(&head, key, 0);
                            break;
                        case 2:
                            deleteFirstElement(&head, 0, 1);
                            break;
                        case 3:
                            printf("\nEnter the position of the element: ");
                            scanf("%d", &position);
                            deleteAtPosition(&head, position);
                            break;
                        case 4:
                            deleteAllElements(&head);
                            break;
                        case 5:
                            deleteLastElement(&head);
                            break;
                        case 6:
                            printf("\e[1;1H\e[2J");
                            break;
                        default:
                            printf("\e[1;1H\e[2J");
                            printf("Invalid choice! Please enter a number between 1 and 3\n");
                    }
                } while (choice1 != 6);
                break;
            case 3:
                do {
                    printf("\n1. Append List\n");
                    printf("2. Traverse\n");
                    printf("3. Traverse Reverse\n");
                    printf("4. Return to menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice1);
                    printf("\e[1;1H\e[2J");
                    switch (choice1) {
                        case 1:
                            printf("\nEnter the element: ");
                            scanf("%d", &data);
                            insertAtBeginning(&head, data);
                            break;
                        case 2:
                            printf("\n");
                            traverse(head);
                            printf("Press 1 to return menu, 2 if not\n");
                            scanf("%d", &choice2);
                            printf("\e[1;1H\e[2J");
                            break;
                        case 3:
                            printf("\nTraverse in Reverse: ");
                            traverseInReverse(head);
                            printf("NULL\n");
                            printf("Press 1 to return menu, 2 if not\n");
                            scanf("%d", &choice2);
                            printf("\e[1;1H\e[2J");
                            break;
                        case 4:
                            printf("\e[1;1H\e[2J");
                            break;
                        default:
                            printf("\e[1;1H\e[2J");
                            printf("Invalid choice! Please enter a number between 1 and 3\n");
                    }
                } while (choice1 != 4 && choice2 != 1);
                break;
            case 4:
                if (head == NULL) {
                    printf("\nList is empty. Nothing to search.\n");
                    usleep(2000000);
                    printf("\e[1;1H\e[2J");
                    break;
                }
                do {
                    printf("\n1. Search\n");
                    printf("2. Return to menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice1);
                    printf("\e[1;1H\e[2J");
                    switch (choice1) {
                        case 1:
                            printf("\nEnter the element to search: ");
                            scanf("%d", &key);
                            search(head, key);
                            break;
                        case 2:
                            printf("\e[1;1H\e[2J");
                            break;
                        default:
                            printf("\e[1;1H\e[2J");
                            printf("Invalid choice! Please enter a number between 1 and 2.\n");
                    }
                } while (choice1 != 2);
                break;
            case 5:
                printf("\e[1;1H\e[2J");
                break;
            default:
                printf("\e[1;1H\e[2J");
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        usleep(2000000);
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
    printf("\nNode inserted.\n");
    usleep(2000000);
    printf("\e[1;1H\e[2J");
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
    printf("\nNode inserted.\n");
    usleep(2000000);
    printf("\e[1;1H\e[2J");
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        sleep(1);
        printf("\e[1;1H\e[2J");
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
            usleep(2000000);
            printf("\e[1;1H\e[2J");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("\nNode inserted.\n");
        usleep(2000000);
        printf("\e[1;1H\e[2J");
    }
}

void deleteFirstElement(struct Node** head, int key, int deleteFirst) {
    if (*head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        usleep(2000000);
        printf("\e[1;1H\e[2J");
        return;
    }
    
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if(deleteFirst){
        *head = temp->next;
        free(temp);
        printf("\nNode deleted.\n");
        usleep(2000000);
        printf("\e[1;1H\e[2J");
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        usleep(2000000);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        usleep(2000000);
        printf("\e[1;1H\e[2J");
        return;
    }
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        usleep(2000000);
        printf("\e[1;1H\e[2J");
        return;
    }
    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("\nNode deleted.\n");
        usleep(2000000);
        printf("\e[1;1H\e[2J");
        return;
    }
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        usleep(2000000);
        printf("\e[1;1H\e[2J");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("\nNode deleted.\n");
    usleep(2000000);
    printf("\e[1;1H\e[2J");
}

void deleteAllElements(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        usleep(2000000);
        printf("\e[1;1H\e[2J");
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
    usleep(2000000);
    printf("\e[1;1H\e[2J");
}

void deleteLastElement(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        usleep(2000000);
        printf("\e[1;1H\e[2J");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
    printf("\nNode deleted.\n");
    usleep(2000000);
    printf("\e[1;1H\e[2J");
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    printf("Arrays: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseInReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    traverseInReverse(head->next);
    printf("%d -> ", head->data);
}

void search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    int found = 0;
    printf("Element %d found at position: ", key);
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