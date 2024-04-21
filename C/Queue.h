// Start Queue
#ifndef Queue_H
#define Queue_H
#define ArrayQueueMaxSize 5

struct NodeQueue {
    int data;
    struct NodeQueue* next;
};
struct NodeQueue* front;
struct NodeQueue* rear;

void clearScreenQueue();
void arrayQueue();
void linkedListQueue();

void queue() {
    int select;
    clearScreenQueue();
    do {
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \033[1;35mPlease choose an operations\033[0m\033[1;34m\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t _________________________________ \n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t/                                 \\\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|        Operations Menu:         |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|      Press '1' for Array        |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|    Press '2' for Linked List    |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|     Press '3' to go Back        |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\_________________________________/\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlease enter your choice of number:\033[0m ");
        if(scanf("%d", &select) != 1) {
            clearScreenQueue();
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            clearScreenQueue();
            while(getchar() != '\n');
            continue;
        }
        if(select < 1 || select > 3) {
            clearScreenQueue();
            printf("Invalid choice. Please choose a number between 1 and 3.\n");
            usleep(2e+6);
            clearScreenQueue();
            continue;
        }
        switch(select) {
            case 1:
                arrayQueue();
                clearScreenQueue();
                break;
            case 2:
                linkedListQueue();
                clearScreenQueue();
                break;
            case 3:
                clearScreenQueue();
                break;
        }
    } while(select != 3);
}

void clearScreenQueue() {
    printf("\e[1;1H\e[2J");
}

void arrayQueue() {
    int front = -1, rear = -1, choiceArrayQueue, item;
    int arrayQueue[ArrayQueueMaxSize];

    clearScreenQueue();
    
    printf("Enter the number of elements in the queue: ");
    if(scanf("%d", &arrayQueue) != 1) {
        clearScreenQueue();
        printf("Invalid input. Please enter a number.\n");
        usleep(2e+6);
    }
    
    printf("Queue operations using array\n");
    do {
        clearScreenQueue();
        printf("Chose one from the below options...\n\n1. Insert an element\n2. Delete an element\n3. Display the queue\n4. Back\n");
        printf("\nEnter your choice: ");
        if(scanf("%d", &choiceArrayQueue) != 1) {
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            clearScreenQueue();
            while(getchar() != '\n');
            continue;
        }
        if(choiceArrayQueue < 1 || choiceArrayQueue > 4) {
            printf("Invalid choice. Please choose a number between 1 and 4.\n");
            usleep(2e+6);
            clearScreenQueue();
            continue;
        }
        switch(choiceArrayQueue) {
            case 1:
                {
                    printf("Enter the element: ");
                    scanf("%d", &item);
                    if(rear == ArrayQueueMaxSize - 1) {
                        printf("OVERFLOW");
                        usleep(2e+6);
                        return;
                    }
                    if(front == -1 && rear == -1) {
                        front = 0;
                        rear = 0;
                    } else {
                        rear = rear + 1;
                    }
                    arrayQueue[rear] = item;
                }
                break;
            case 2:
                {
                    if(front == -1 || front > rear) {
                        printf("UNDERFLOW");
                        return;
                    } else {
                        item = arrayQueue[front];
                        if(front == rear) {
                            front = -1;
                            rear = -1;
                        } else {
                            front = front + 1;
                        }
                    }
                }
                break;
            case 3:
                {
                    int i;
                    if(rear == -1) {
                        printf("Empty");
                    } else {
                        printf("printing values...\n");
                        for(i = front; i <= rear; i++) {
                            printf("%d ", arrayQueue[i]);
                        }
                        usleep(2e+6);
                        printf("\nPress any key to go back...\n");
                        getchar();
                        char input = getchar();
                        clearScreenQueue();
                    }
                }
                break;
            case 4:
                break;
        }
    } while(choiceArrayQueue != 4);
}

void linkedListQueue() {
    int choiceLinkedListQueue; 
    int item;

    clearScreenQueue();

    printf("Enter the number of elements in the queue: ");
    if(scanf("%d", &item) != 1) {
        clearScreenQueue();
        printf("Invalid input. Please enter a number.\n");
        usleep(2e+6);
    }

    printf("Queue operations using Linked List\n");
    do {
        clearScreenQueue();
        printf("Chose one from the below options...\n\n1. Insert an element\n2. Delete an element\n3. Display the queue\n4. Back\n");
        printf("\nEnter your choice: ");
        if(scanf("%d", &choiceLinkedListQueue) != 1) {
            printf("Invalid input. Please enter a number.\n");
            usleep(2e+6);
            clearScreenQueue();
            while(getchar() != '\n');
            continue;
        }
        if(choiceLinkedListQueue < 1 || choiceLinkedListQueue > 4) {
            printf("Invalid choice. Please choose a number between 1 and 4.\n");
            usleep(2e+6);
            clearScreenQueue();
            continue;
        }
        switch(choiceLinkedListQueue) {
            case 1:
                {
                    struct NodeQueue* ptr;
                    ptr = (struct NodeQueue*)malloc(sizeof(struct NodeQueue));
                    if(ptr == NULL) {
                        printf("OVERFLOW");
                        usleep(2e+6);
                        return;
                    } else {
                        printf("Enter value: ");
                        scanf("%d", &item);

                        ptr -> data = item;
                        if(front == NULL) {
                            front = ptr;
                            rear = ptr;
                            front -> next = NULL;
                            rear -> next = NULL;
                        } else {
                            rear -> next = ptr;
                            rear = ptr;
                            rear -> next = NULL;
                        }
                    }
                }
                break;
            case 2:
                {
                    struct NodeQueue* ptr;
                    if(front == NULL) {
                        printf("UNDERFLOW");
                        usleep(2e+6);
                        return;
                    } else {
                        ptr = front;
                        front = front -> next;
                        free(ptr);
                    }
                }
                break;
            case 3:
                {
                    struct NodeQueue* ptr;
                    ptr = front;
                    if(front == NULL) {
                        printf("Empty");
                        usleep(2e+6);
                    } else {
                        printf("printing values...\n");
                        while(ptr != NULL) {
                            printf("%d ", ptr -> data);
                            ptr = ptr -> next;
                        }
                        usleep(2e+6);
                        printf("\nPress any key to go back...\n");
                        getchar();
                        char input = getchar();
                        clearScreenQueue();
                    }
                }
                break;
            case 4:
                clearScreenQueue();
                break;
        }
    } while(choiceLinkedListQueue != 4);
}

#endif /* Queue_H */
// End Queue
