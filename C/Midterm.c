#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Array.h"
#include "SLL.h"
#include "DLL.h"
#include "CLL.h"
#include "Stack.h"

// Prototypes
void cls();
void array();
void linkedlist();
void singlyLL();
void doublyLL();
void circularLL();
void stack();

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
                cls();
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

// Start Linked List Menu
void linkedlist() {
    int choice;

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
                doublyLL();
                cls();
                break;
            case 3:
                circularLL();
                cls();
                break;
            case 4:
                break;
            case 5:
                cls();
                break;
        }
    } while(choice != 5);
}
// End Linked List Menu