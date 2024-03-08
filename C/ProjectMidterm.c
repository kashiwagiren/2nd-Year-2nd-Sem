#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Prototypes
void menu();
void cls();
void array();

// Start Main
int main() {
    // Starting Screen/Main
    cls();

    printf("Welcome to Data Structure!\n\nPress any key to start...");
    getchar();

    cls();

    menu();

    return 0;
}
// End Main

// Start Menu
void menu() {
    int choice;

    do
    {
        printf("Please choose an operations\n1. Array\n2. Linked List\n3. Stack\n4. Help\n5. Exit\nPlease enter your choice of number: ");

        // Reads user input
        if (scanf("%d", &choice) != 1) {
            cls();
            printf("Invalid input. Please enter a number.\n"); usleep(2e+6); cls();
            while (getchar() != '\n'); // Clears input buffer
            continue;
        }

        // Checks if choice is within range
        if (choice < 1 || choice > 5) {
            cls();
            printf("Invalid choice. Please choose a number between 1 and 5.\n"); usleep(2e+6); cls();
            continue;
        }

        switch (choice) {
            case 1:
                // goes to array
                array();
                cls();
                break;
            case 2:
                // goes to linked list
                break;
            case 3:
                // goes to stack
                break;
            case 4:
                
                break;
            case 5:
                cls();
                exit(0);
                break;
        }
    } while (choice != 5);
}
// End Menu

// Clear Screen
void cls() {
    printf("\e[1;1H\e[2J");
}

// Start Array
void array() {
    int size, choice;

    cls();
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size < 1) {
        cls();
        printf("Invalid input. The size must be a positive integer or not equal to zero.\n"); usleep(2e+6); cls();
        return; // Exits the function if input is invalid
    }
    
    int array[size];
    
    for (size_t i = 0; i < size; i++)
    {
        printf("Enter element [%zu]: ", i + 1);
        scanf("%d", &array[i]);
    }

    while (1) {
        cls();
        printf("Please choose an operations\n1. Traverse\n2. Insertion\n3. Deletion\n4. Search\n5. Update\n6. Display\n7. Clear Array and Input New\n8. Back\nPlease enter your choice of number: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            /* code */
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            for (size_t i = 0; i < size; i++) {
                array[i] = 0;
            }
            printf("Array Cleared.\n");
            usleep(2e+6);
            for (size_t i = 0; i < size; i++) {
                printf("Enter element [%zu]: ", i + 1);
                scanf("%d", &array[i]);
            }
            break;
        case 8:
            for (size_t i = 0; i < size; i++) {
                array[i] = 0;
            }
            usleep(1e+6);
            cls();
            menu();
            break;
        }
    }
}
// End Array