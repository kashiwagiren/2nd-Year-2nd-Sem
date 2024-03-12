// Start Stack
#ifndef Stack_H
#define Stach_H

struct NodeStack {
    int val;
    struct NodeStack *next;
};

struct NodeLinked {
    int val;
    struct NodeLinked *next;
};

struct NodeStack *head;

struct NodeLinked *heads;

void clearScreenStack();
void arrayStack();
void linkedlistStack();

void stack() {
    int select;
    clearScreenStack();
    do {
        printf("Please choose an operations\n1. Array\n2. Linked List\n3. Back\nEnter your choice: ");
        if(scanf("%d", &select) != 1) {
            clearScreenStack();
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            clearScreenStack();
            while(getchar() != '\n');
            continue;
        }
        if(select < 1 || select > 3) {
            clearScreenStack();
            printf("Invalid choice. Please choose a number between 1 and 3.\n");
            usleep(2e+6);
            clearScreenStack();
            continue;
        }
        switch(select) {
            case 1:
                arrayStack();
                clearScreenStack();
                break;
            case 2:
                linkedlistStack();
                clearScreenStack();
                break;
            case 3:
                clearScreenStack();
                break;
        }
    } while(select != 3);
}

void clearScreenStack() {
    printf("\e[1;1H\e[2J");
}

void arrayStack() {
    int stack[100], i, j, choiceArrayStack = 0, n, top = -1;
    clearScreenStack();
    printf("Enter the number of elements in the stack: ");
    if(scanf("%d", &n) != 1) {
        clearScreenStack();
        printf("Invalid input. Please enter a number.\n");
        usleep(2e+6);
    }
    printf("Stack operations using array\n");
    do {
        clearScreenStack();
        printf("Chose one from the below options...\n\n1. Push\n2. Pop\n3. Show\n4. Back\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choiceArrayStack) != 1) {
            clearScreenStack();
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            clearScreenStack();
            while(getchar() != '\n');
            continue;
        }
        if(choiceArrayStack < 1 || choiceArrayStack > 4) {
            clearScreenStack();
            printf("Invalid choice. Please choose a number between 1 and 4.\n");
            usleep(2e+6);
            clearScreenStack();
            continue;
        }
        switch(choiceArrayStack) {
            case 1:
                {
                    int val;
                    if(top == n) {
                        clearScreenStack();
                        printf("Overflow\n");
                        usleep(2e+6);
                        clearScreenStack();
                    } else {
                        printf("Enter the value: ");
                        scanf("%d", &val);
                        top = top + 1;
                        stack[top] = val;
                    }
                    break;
                }
            case 2:
                {
                    if(top == -1) {
                        clearScreenStack();
                        printf("Underflow\n");
                        usleep(2e+6);
                        clearScreenStack();
                    } else {
                        top = top - 1;
                    }
                    break;
                }
            case 3:
                {
                    clearScreenStack();
                    for(i = top; i >= 0; i--) {
                        printf(" ______________\n");
                        printf("|     [%d]     |\n", stack[i]);
                        printf("\\______________/\n");
                    }
                    if(top == -1) {
                        clearScreenStack();
                        printf("Stack is empty\n");
                        usleep(2e+6);
                        clearScreenStack();
                    }
                    
                    printf("\n\n");
                    printf("Press any key to go back...\n");
                    getchar();
                    char input = getchar();
                    clearScreenStack();
                    break;
                }
            case 4:
                break;
        }
    } while(choiceArrayStack != 4);
}

void linkedlistStack() {
    int choiceLinkedListStack = 0;
    clearScreenStack();
    printf("Stack operations using linked list\n");
    do {
        clearScreenStack();
        printf("Chose one from the below options...\n\n1. Push\n2. Pop\n3. Show\n4. Back\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choiceLinkedListStack) != 1) {
            clearScreenStack();
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            clearScreenStack();
            while(getchar() != '\n');
            continue;
        }
        if(choiceLinkedListStack < 1 || choiceLinkedListStack > 4) {
            clearScreenStack();
            printf("Invalid choice. Please choose a number between 1 and 4.\n");
            usleep(2e+6);
            clearScreenStack();
            continue;
        }
        switch(choiceLinkedListStack) {
            case 1:
                int val;
                struct NodeLinked *ptr = (struct NodeLinked*)malloc(sizeof(struct NodeLinked));
                if(ptr == NULL) {
                    clearScreenStack();
                    printf("Not able to push element");
                    usleep(2e+6);
                    clearScreenStack();
                } else {
                    printf("Enter the value: ");
                    scanf("%d", &val);
                    if(heads == NULL) {
                        ptr -> val = val;
                        ptr -> next = NULL;
                        heads = ptr;
                    } else {
                        ptr -> val = val;
                        ptr -> next = heads;
                        heads = ptr;
                    }
                    printf("Item pushed.\n");
                    usleep(2e+6);
                    clearScreenStack();
                }
                break;
            case 2:
                int item;
                if(heads == NULL) {
                    clearScreenStack();
                    printf("Underflow\n");
                    usleep(2e+6);
                    clearScreenStack();
                } else {
                    item = heads -> val;
                    ptr = heads;
                    heads = heads -> next;
                    free(ptr);
                    printf("Item popped.\n");
                    usleep(2e+6);
                    clearScreenStack();
                }
                break;
            case 3:
                int i;
                ptr = heads;
                if(ptr == NULL) {
                    printf("Stack is empty.\n");
                    usleep(2e+6);
                    clearScreenStack();
                } else {
                    clearScreenStack();
                    printf("Printing Stack elements\n");
                    while(ptr != NULL) {
                        printf(" ______________\n");
                        printf("|     [%d]     |\n", ptr -> val);
                        printf("\\______________/\n");
                        ptr = ptr -> next;
                    }

                    printf("\n\n");
                    printf("Press any key to go back...\n");
                    getchar();
                    char input = getchar();
                    clearScreenStack();
                }
                break;
            case 4:
                break;
        }
    } while(choiceLinkedListStack != 4);
}

#endif /* Stack_H */
// End Stack