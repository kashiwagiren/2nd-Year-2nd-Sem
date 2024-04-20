/*
    By: Kieth Wilbur J. Chua
            BSCPE - 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "Array.h"
#include "SLL.h"
#include "DLL.h"
#include "CLL.h"
#include "Stack.h"

// Aaaaaaambooot
void cls();
void array();
void linkedlist();
void singlyLL();
void doublyLL();
void circularLL();
void stack();
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
void insertAtBeginningCircular(struct NodeCircular** head, int data);
void insertAtEndCircular(struct NodeCircular** head, int data);
void deleteFromBeginningCircular(struct NodeCircular** head);
void deleteFromEndCircular(struct NodeCircular** head);
void searchCircular(struct NodeCircular* head, int key);
void traverseCircular(struct NodeCircular* head);
void arrayStack();
void linkedlistStack();

// Start Main
int main() {
    cls();
    printf("\033[1;35m ________  ________  _________  ________      ________  _________  ________  ___  ___  ________ _________  ___  ___  ________  _______    ________  \n");
    printf("|\\   ___ \\|\\   __  \\|\\___   ___|\\   __  \\    |\\   ____\\|\\___   ___|\\   __  \\|\\  \\|\\  \\|\\   ____|\\___   ___|\\  \\|\\  \\|\\   __  \\|\\  ___ \\  |\\   ____\\   \n");
    printf("\\ \\  \\_|\\ \\ \\  \\|\\  \\|___ \\  \\_\\ \\  \\|\\  \\   \\ \\  \\___|\\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\___\\|___ \\  \\_\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\   __/| \\ \\  \\___|\\   \n");
    printf(" \\ \\  \\ \\\\ \\ \\   __  \\   \\ \\  \\ \\ \\   __  \\   \\ \\_____  \\   \\ \\  \\ \\ \\   _  _\\ \\  \\\\\\  \\ \\  \\       \\ \\  \\ \\ \\  \\\\\\  \\ \\   _  _\\ \\  \\_|/__\\ \\_____  \\  \n");
    printf("  \\ \\  \\_\\\\ \\ \\  \\ \\  \\   \\ \\  \\ \\ \\  \\ \\  \\ __\\|____|\\  \\   \\ \\  \\ \\ \\  \\\\  \\\\ \\  \\\\\\  \\ \\  \\____   \\ \\  \\ \\ \\  \\\\\\  \\ \\  \\\\  \\\\ \\  \\_|\\ \\\\|____|\\  \\ \n");
    printf("   \\ \\_______\\ \\__\\ \\__\\   \\ \\__\\ \\ \\__\\ \\__|\\__\\____\\_\\  \\   \\ \\__\\ \\ \\__\\\\ _\\\\ \\_______\\ \\_______\\  \\ \\__\\ \\ \\_______\\ \\__\\\\ _\\\\ \\_______\\\\____\\_\\  \\\n");
    printf("    \\|_______|\\|__|\\|__|    \\|__|  \\|__|\\|__\\|__|\\_________\\   \\|__|  \\|__|\\|__|\\|_______|\\|_______|   \\|__|  \\|_______|\\|__|\\|__|\\|_______||\\_________\\\n");
    printf("                                                \\|_________|                                                                                \\|_________|\033[0m\n");
    printf("\t\t\t\t\t\033[1;31m        _  _                                         _  _\n");
    printf("\t\t\t\t\t  ___ (~ )( ~)                                     (~ )( ~) ___\n");
    printf("\t\t\t\t\t /   \\_\\ \\/ /                 Welcome               \\ \\/ /_/   \\\n");
    printf("\t\t\t\t\t|   D_ ]\\ \\/                    To                   \\/ /[ _S   |\n");
    printf("\t\t\t\t\t|   D _]/\\ \\              Data Structures!           / /\\[_ S   |\n");
    printf("\t\t\t\t\t \\___/ / /\\ \\                                       / /\\ \\ \\___/\n");
    printf("\t\t\t\t\t   \033[1;32mby\033[0m\033[1;31m (_ )( _)                                     (_ )( _)\033[0m\033[1;32m Kieth\033[0m\033[1;31m\n");
    printf("\t\t\t\t\t        ~  ~           Press any Key to start...     ~  ~\n");
    printf("\t\t\t\t\t                             \n");
    printf("\t\t\t\t\t                           \033[0m\033[1;35m->\033[0m ");
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
        printf("\t\t\t\t\t\t\t\t    \033[1;35mPlease choose an operations\033[0m\n");
        printf("\033[1;36m");
        printf("\t\t\t\t\t\t\t\t _________________________________ \n");
        printf("\t\t\t\t\t\t\t\t/                                 \\\n");
        printf("\t\t\t\t\t\t\t\t|        Operations Menu:         |\n");
        printf("\t\t\t\t\t\t\t\t|      Press '1' for Array        |\n");
        printf("\t\t\t\t\t\t\t\t|    Press '2' for Linked List    |\n");
        printf("\t\t\t\t\t\t\t\t|      Press '3' to Stack         |\n");
        printf("\t\t\t\t\t\t\t\t|     Press '4' to get Help       |\n");
        printf("\t\t\t\t\t\t\t\t|       Press '5' to Exit         |\n");
        printf("\t\t\t\t\t\t\t\t\\_________________________________/\n");
        printf("\n\t\t\t\t\t\t\t\tPlease enter your choice of number: ");
        printf("\033[0m");
        if(scanf("%d", &choice) != 1) {
            printf("\n\t\t\t\t\t\t\t\t\033[1;31mInvalid input. Please enter a number.\033[0m\n");
            usleep(2e+6);
            cls();
            while(getchar() != '\n');
            continue;
        }
        if(choice < 1 || choice > 5) {
            printf("\n\t\t\t\t\t\t\t\033[1;31mInvalid choice. Please choose a number between 1 and 5.\033[0m\n");
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
                cls();
                stack();
                break;
            case 4:
                int j;
                char loading[31] = "   Bro, figure it out yourself";
                printf("\033[1;31m\t\t\t\t\t\t\t\t");
                for(j = 0; j < 30; j++) {
                    printf("%c", loading[j]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\033[0m\n\t\t\t\t\t\t\t\t");
                usleep(1e+6);
                cls();
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
        printf(" \033[1;35mPlease choose a Linked List Type\033[0m\n");
        printf("\033[1;32m");
        printf(" _________________________________ \n");
        printf("/                                 \\\n");
        printf("|         Operations Menu:        |\n");
        printf("|       Press '1' for Singly      |\n");
        printf("|       Press '2' for Doubly      |\n");
        printf("|      Press '3' for Circular     |\n");
        printf("|      Press '4' to get Help      |\n");
        printf("|       Press '5' to go Back      |\n");
        printf("\\_________________________________/\n");
        printf("\nPlease enter your choice of number:\033[0m ");
        if(scanf("%d", &choice) != 1) {
            cls();
            printf("\033[1;31mInvalid input. Please enter a number.\033[0m\n");
            usleep(2e+6);
            cls();
            while(getchar() != '\n');
            continue;
        }
        if(choice < 1 || choice > 5) {
            cls();
            printf("\033[1;31mInvalid choice. Please choose a number between 1 and 5.\033[0m\n");
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
                int k;
                char loading[31] = "   Bro, figure it out yourself";
                printf("\033[1;31m");
                for(k = 0; k < 30; k++) {
                    printf("%c", loading[k]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\033[0m");
                usleep(1e+6);
                cls();
                break;
            case 5:
                cls();
                break;
        }
    } while(choice != 5);
}
// End Linked List Menu
