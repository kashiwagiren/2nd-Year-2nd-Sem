#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Prototypes
void cls();
void menu();
void array();
void linkedlist();
void singlyLL();

int isInitialized = 0;
int hasElements = 0;

// Start Main
int main() {
    cls();
    printf("Welcome to Data Structure!\n\nPress any key to start...\n");
    getchar();
    cls();
    menu();
    return 0;
}
// End Main

void cls() {
    printf("\e[1;1H\e[2J");
}

// Start Menu
void menu() {
    int choice;
    do {
        printf("Please choose an operations\n1. Array\n2. Linked List\n3. Stack\n4. Help\n5. Exit\nPlease enter your choice of number: ");
        if(scanf("%d", &choice) != 1) {
            cls();
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            cls();
            while(getchar() != '\n');
            continue;
        }
        if(choice < 1 || choice > 5) {
            cls();
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
            usleep(2e+6);
            cls();
            continue;
        }
        switch(choice) {
            case 1:
                cls();
                array();
                break;
            case 2:
                linkedlist();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                cls();
                exit(0);
                break;
        }
    } while(choice != 5);
}
// End Menu

// Start Array
void array() {
    int size, choice;
    int* arr = NULL;

    if(!isInitialized) {
        cls();
        printf("Enter the size of the array: ");
        if(scanf("%d", &size) != 1 || size < 1) {
            cls();
            printf("Invalid input. The size must be a positive integer or not equal to zero.\n");
            usleep(2e+6);
            cls();
            return;
        }
        isInitialized = 1;
    }

    arr = (int*)malloc(size * sizeof(int));
    if(arr == NULL) {
        cls();
        printf("Error: Memory allocation failed.\n");
        usleep(2e+6);
        cls();
        exit(1);
    }

    if(!hasElements) {
        for(size_t i = 0; i < size; i++) {
            printf("Enter element [%zu]: ", i );
            scanf("%d", &arr[i]);
        }
        hasElements = 1;
    }

    while(1) {
        cls();
        printf("Please choose an operations\n1. Traverse\n2. Insertion\n3. Deletion\n4. Search\n5. Update\n6. Display\n7. Clear all Arrays\n8. Back\nPlease enter your choice of number: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Traverse
                if(!hasElements || arr == NULL) {
                    cls();
                    printf("Array is empty.\n");
                    usleep(2e+6);
                    printf("Going back to menu...\n");
                    usleep(2e+6);
                    cls();
                    menu();
                    break;
                }
                cls();
                printf("Array elements:\n");
                usleep(1e+6);
                for(size_t i = 0; i < size; i++) {
                    printf("Index [%zu] Element [%d]\n", i, arr[i]);
                    usleep(1e+6);
                }
                printf("\n");
                usleep(2e+6);
                printf("Press any key to go back...\n");
                getchar();
                char input = getchar();
                break;

            case 2:
                // Insertion
                if(!isInitialized) {
                    cls();
                    printf("Array is not initialized. Please initialize the array first.\n");
                    usleep(2e+6);
                    printf("Going back to menu...\n");
                    usleep(2e+6);
                    cls();
                    menu();
                    break;
                }

                int insertChoice;
                cls();
                printf("Please choose insertion type:\n1. Beginning\n2. End\n3. At Index\n");
                printf("Enter your choice: ");
                if(scanf("%d", &insertChoice) != 1 || (insertChoice < 1 || insertChoice > 3)) {
                    cls();
                    printf("Invalid choice. Please enter a valid option (1, 2, or 3).\n");
                    usleep(2e+6);
                    cls();
                    break;
                }

                int element, index;
                switch(insertChoice) {
                    case 1:
                        cls();
                        printf("Enter the element to insert at the beginning: ");
                        scanf("%d", &element);
                        arr = (int*)realloc(arr, (size + 1) * sizeof(int));
                        if(arr == NULL) {
                            printf("Memory allocation failed.\n");
                            exit(1);
                        }
                        for(size_t i = size; i > 0; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[0] = element;
                        size++;
                        printf("Element inserted at the beginning.\n");
                        break;
                    case 2:
                        cls();
                        printf("Enter the element to insert at the end: ");
                        scanf("%d", &element);
                        arr = (int*)realloc(arr, (size + 1) * sizeof(int));
                        if(arr == NULL) {
                            printf("Memory allocation failed.\n");
                            exit(1);
                        }
                        arr[size++] = element;
                        printf("Element inserted at the end.\n");
                        break;
                    case 3:
                        cls();
                        printf("Enter the index to insert at [0 to %d]: ", size);
                        scanf("%d", &index);
                        if(index < 0 || index > size) {
                            printf("Invalid index. Index must be between 0 and %d.\n", size);
                            usleep(2e+6);
                            break;
                        }
                        printf("Enter the element to insert at index [%d]: ", index);
                        scanf("%d", &element);
                        arr = (int*)realloc(arr, (size + 1) * sizeof(int));
                        if(arr == NULL) {
                            printf("Memory allocation failed.\n");
                            exit(1);
                        }
                        for(size_t i = size; i > index; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[index] = element;
                        size++;
                        printf("Element inserted at index [%d].\n", index);
                        break;
                    default:
                        break;
                }

                usleep(2e+6);
                break;

            case 3:
                // Deletion
                if(!hasElements || arr == NULL) {
                    cls();
                    printf("Array is empty.\n");
                    usleep(2e+6);
                    printf("Going back to menu...\n");
                    usleep(2e+6);
                    cls();
                    menu();
                    break;
                }

                int deleteChoice;
                cls();
                printf("Please choose deletion type:\n1. Beginning\n2. End\n3. At Index\n");
                printf("Enter your choice: ");
                if(scanf("%d", &deleteChoice) != 1 || (deleteChoice < 1 || deleteChoice > 3)) {
                    cls();
                    printf("Invalid choice. Please enter a valid option (1, 2, or 3).\n");
                    usleep(2e+6);
                    cls();
                    break;
                }

                switch(deleteChoice) {
                    case 1:
                        for(size_t i = 0; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        arr = (int *)realloc(arr, (size - 1) * sizeof(int));
                        if(arr == NULL && size > 1) {
                            printf("Memory reallocation failed.\n");
                            exit(1);
                        }
                        size--;
                        printf("Element deleted from the beginning.\n");
                        break;
                    case 2:
                        arr = (int *)realloc(arr, (size - 1) * sizeof(int));
                        if(arr == NULL && size > 1) {
                            printf("Memory reallocation failed.\n");
                            exit(1);
                        }
                        size--;
                        printf("Element deleted from the end.\n");
                        break;
                    case 3:
                        int deleteIndex;
                        cls();
                        printf("Enter the index to delete [0 to %d]: ", size - 1);
                        scanf("%d", &deleteIndex);
                        if(deleteIndex < 0 || deleteIndex >= size) {
                            printf("Invalid index. Index must be between [0 and %d].\n", size - 1);
                            usleep(2e+6);
                            break;
                        }
                        for(size_t i = deleteIndex; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        arr = (int *)realloc(arr, (size - 1) * sizeof(int));
                        if(arr == NULL && size > 1) {
                            printf("Memory reallocation failed.\n");
                            exit(1);
                        }
                        size--;
                        printf("Element at index [%d] deleted successfully.\n", deleteIndex);
                        break;
                    default:
                        break;
                }

                usleep(2e+6);
                break;

            case 4:
                // Search
                if(!hasElements || arr == NULL) {
                    cls();
                    printf("Array is empty.\n");
                    usleep(2e+6);
                    printf("Going back to menu...\n");
                    usleep(2e+6);
                    cls();
                    menu();
                    break;
                }

                int searchChoice;
                cls();
                printf("Please choose search type:\n1. By Index\n2. By Element\n");
                printf("Enter your choice: ");
                if(scanf("%d", &searchChoice) != 1 || (searchChoice < 1 || searchChoice > 2)) {
                    cls();
                    printf("Invalid choice. Please enter a valid option (1 or 2).\n");
                    usleep(2e+6);
                    cls();
                    break;
                }

                switch(searchChoice) {
                    case 1:
                        int searchIndex;
                        cls();
                        printf("Enter the index to search [0 to %d]: ", size - 1);
                        scanf("%d", &searchIndex);
                        if(searchIndex < 0 || searchIndex >= size) {
                            printf("Invalid index. Index must be between [0 and %d].\n", size - 1);
                            usleep(2e+6);
                            break;
                        }
                        printf("Element at index [%d] is: %d\n", searchIndex, arr[searchIndex]);
                        break;
                    case 2:
                        int searchElement;
                        cls();
                        printf("Enter the element to search: ");
                        scanf("%d", &searchElement);
                        for(size_t i = 0; i < size; i++) {
                            if(arr[i] == searchElement) {
                                printf("Element [%d] found at index [%zu].\n", searchElement, i);
                                break;
                            }
                            if(i == size - 1) {
                                printf("Element [%d] not found in the array.\n", searchElement);
                            }
                        }
                        break;
                    default:
                        break;
                }

                usleep(2e+6);
                break;

            case 5:
                // Update
                if(!hasElements || arr == NULL) {
                    cls();
                    printf("Array is empty.\n");
                    usleep(2e+6);
                    printf("Going back to menu...\n");
                    usleep(2e+6);
                    cls();
                    menu();
                    break;
                }

                int updateIndex, newValue;
                cls();
                printf("Enter the index to update [0 to %d]: ", size - 1);
                scanf("%d", &updateIndex);
                if(updateIndex < 0 || updateIndex >= size) {
                    printf("Invalid index. Index must be between [0 and %d].\n", size - 1);
                    usleep(2e+6);
                    break;
                }
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                arr[updateIndex] = newValue;
                printf("Element at index [%d] updated successfully.\n", updateIndex);

                usleep(2e+6);
                break;

            case 6:
                // Display
                if(!hasElements || arr == NULL) {
                    cls();
                    printf("Array is empty.\n");
                    usleep(2e+6);
                    printf("Going back to menu...\n");
                    usleep(2e+6);
                    cls();
                    menu();
                    break;
                }
                cls();
                printf("Array elements:\n");
                usleep(1e+6);
                for(size_t i = 0; i < size; i++) {
                    printf("Index [%zu] Element [%d]\n", i, arr[i]);
                }
                printf("\n");
                usleep(2e+6);
                printf("Press any key to go back...\n");
                getchar();
                char inputChar = getchar();
                break;

            case 7:
                // Clear all Arrays
                isInitialized = 0;
                hasElements = 0;
                free(arr);
                arr = NULL;
                cls();
                printf("The arrays have been cleared.\n");
                usleep(2e+6);
                break;
            
            case 8:
                // Back
                cls();
                printf("Note: if you go back, it will reset your data and will not be preserved.\n[y / n]: ");
                char option;
                while(1) {
                    scanf(" %c", &option);
                    if(option == 'y' || option == 'Y') {
                        isInitialized = 0;
                        hasElements = 0;
                        cls();
                        menu();
                    } else if(option == 'n'|| option == 'N') {
                        cls();
                        break;
                    } else {
                        cls();
                        printf("Invalid input. Please enter 'y' or 'n'.\n");
                        usleep(1e+6);
                        cls();
                        printf("Note: if you go back, it will reset your data and will not be preserved.\n[y / n]: ");
                        cls();
                    }
                }
                cls();
                break;
        }
    }
}
// End Array

// Start Linked List
void linkedlist() {
    int choice;

    cls();
    do {
        printf("Please choose a Linked List Type\n1. Singly\n2. Doubly\n3. Circular\n4. Help\n5. Back\nPlease enter your choice of number: ");
        if(scanf("%d", &choice) != 1) {
            cls();
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            cls();
            while(getchar() != '\n');
            continue;
        }
        if(choice < 1 || choice > 5) {
            cls();
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
            usleep(2e+6);
            cls();
            continue;
        }
        switch(choice) {
            case 1:
                singlyLL();
                cls();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                cls();
                break;
        }
    } while(choice != 5);
}
// End Linked List

// Start Singly Linked List
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);

// Prototypes for SLL
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);

void singlyLL() {
    struct Node* head = NULL;
    int choice, choiceInsertion, data, key, position;
    cls();
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
            cls();
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            cls();
            while(getchar() != '\n');
            continue;
        }
        if(choice < 1 || choice > 5) {
            cls();
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
            usleep(2e+6);
            cls();
            continue;
        }
        switch(choice) {
            case 1:
                // Insertion
                if(head == NULL) {
                    printf("\nList is empty. Nothing to insert.\n");
                    usleep(2e+6);
                    cls();
                    break;
                }
                do {
                    printf("\n1. Insert at Beginning\n");
                    printf("2. Insert at End\n");
                    printf("3. Insert at specified Node\n");
                    printf("4. Return to menu\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &choiceInsertion) != 1) {
                        cls();
                        printf("Invalid input. Please enter a number.\n");
                        usleep(2e+6);
                        cls();
                        while(getchar() != '\n');
                        continue;
                    }
                    if(choice < 1 || choiceInsertion > 4) {
                    cls();
                    printf("Invalid choice. Please choose a number between 1 and 4.\n");
                    usleep(2e+6);
                    cls();
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
                            cls();
                            break;
                    }
                } while(choiceInsertion != 4);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    } while(choice != 5);
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        usleep(2e+6);
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
    usleep(2e+6);
    cls();
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
    usleep(2e+6);
    cls();
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        usleep(1e+6);
        cls();
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
            cls();
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("\nNode inserted.\n");
        usleep(2e+6);
        cls();
    }
}
// End Singly Linked List