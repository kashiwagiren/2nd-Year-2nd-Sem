/*
    By: Kieth Wilbur J. Chua
            BSCPE - 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "Art.h"
#include "Array.h"
#include "LinkedList.h"
#include "SLL.h"
#include "DLL.h"
#include "CLL.h"
#include "Stack.h"
#include "Queue.h"

// Function Prototypes
void cls();
void art();
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
void queue();

// Start Main
int main() {
    art();
    getchar();
    cls();
    menu();
    return 0;
}
// End Main

// Start Clear Screen
void cls() {
    printf("\e[1;1H\e[2J");
}
// End Clear Screen

// Start Menu
void menu() {
    int choice;

    int centerOffset = 20;
    do {

        printf("%*s\033[1;35mCHOOSE A DATA STRUCTURE\033[0m\n",      centerOffset + 51, "");
        printf("%*s\033[1;36m _________________________________ \n", centerOffset + 44, "");
                  printf("%*s/                                 \\\n",centerOffset + 44, "");
                  printf("%*s|        Operations Menu:         |\n", centerOffset + 44, "");
                  printf("%*s|        Press '1' Array          |\n", centerOffset + 44, "");
                  printf("%*s|        Press '2' Linked List    |\n", centerOffset + 44, "");
                  printf("%*s|        Press '3' Stack          |\n", centerOffset + 44, "");
                  printf("%*s|        Press '4' Queue          |\n", centerOffset + 44, "");
                  printf("%*s|        Press '5' Tree           |\n", centerOffset + 44, "");
                  printf("%*s|        Press '6' Graph          |\n", centerOffset + 44, "");
                  printf("%*s|        Press '7' Help           |\n", centerOffset + 44, "");
                  printf("%*s|        Press '8' Exit           |\n", centerOffset + 44, "");
                 printf("%*s\\_________________________________/\n", centerOffset + 44, "");
                printf("\n%*sPlease enter your choice of number: \033[0m", centerOffset + 44, "");
        
        if(scanf("%d", &choice) != 1) {
            printf("\n%*s\033[1;31mInvalid input. Please enter a number.\033[0m\n", centerOffset + 44, "");
            usleep(2e+6);
            cls();
            while(getchar() != '\n');
            continue;
        }
        if(choice < 1 || choice > 8) {
            printf("\n%*s\033[1;31mInvalid choice. Please choose a number between 1 and 8.\033[0m\n", centerOffset + 35, "");
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
                cls();
                queue();
                break;
            case 5:
                printf("\n\033[1;31m%*sStill in Progress...\033[0m", centerOffset + 52, "");
                usleep(2e+6);
                cls();
                break;
            case 6:
                printf("\n\033[1;31m%*sStill in Progress...\033[0m", centerOffset + 52, "");
                usleep(2e+6);
                cls();
                break;
            case 7:
                int j;
                char loading[31] = "   Bro, figure it out yourself";
                printf("\033[1;31m%*s", centerOffset + 45, "");
                for(j = 0; j < 30; j++) {
                    printf("%c", loading[j]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\033[0m\n%*s", centerOffset + 45, "");
                usleep(1e+6);
                cls();
                break;
            case 8:
                cls();
                printf("%*s\033[1;31mARE YOU SURE YOU WANT TO QUIT ?\033[0m\n", centerOffset + 47, "");
                printf("%*s\033[1;36m[\033[0m\033[1;31mY\033[0m / \033[1;32mN\033[0m\033[1;36m]\033[0m: ", centerOffset + 57, "");
                char option;
                while(1) {
                    scanf(" %c", &option);
                    if(option == 'y' || option == 'Y') {
                        cls();
                        exit(0);
                    } else if(option == 'n'|| option == 'N') {
                        cls();
                        menu();
                    } else {
                        printf("\n%*s\033[1;31mInvalid input. Please enter 'y' or 'n'.\033[0m", centerOffset + 44, "");
                        usleep(2e+6);
                        cls();
                    }
                    printf("%*s\033[1;31mARE YOU SURE YOU WANT TO QUIT ?\033[0m\n", centerOffset + 47, "");
                    printf("%*s\033[1;36m[\033[0m\033[1;31mY\033[0m / \033[1;32mN\033[0m\033[1;36m]\033[0m: ", centerOffset + 57, "");
                }
                break;
        }
    } while(choice != 8);
}
// End Menu
