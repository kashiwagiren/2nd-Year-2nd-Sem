// Start Linked List
#ifndef LinkedList_H
#define LinkedList_H

void clearScreenLL();
void singlyLL();
void doublyLL();
void circularLL();

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
            printf("\033[1;31mInvalid input. Please enter a number.\033[0m\n");
            usleep(2e+6);
            clearScreenLL();
            while(getchar() != '\n');
            continue;
        }
        if(choice < 1 || choice > 5) {
            printf("\033[1;31mInvalid choice. Please choose a number between 1 and 5.\033[0m\n");
            usleep(2e+6);
            clearScreenLL();
            continue;
        }
        switch(choice) {
            case 1:
                singlyLL();
                clearScreenLL();
                break;
            case 2:
                doublyLL();
                clearScreenLL();
                break;
            case 3:
                circularLL();
                clearScreenLL();
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
                clearScreenLL();
                break;
            case 5:
                clearScreenLL();
                break;
        }
    } while(choice != 5);
}

void clearScreenLL() {
    printf("\033[0m");
}

#endif
// End Linked List
