// Start Array
#ifndef Array_H
#define Array_H

int isInitialized = 0;
int hasElements = 0;

void clearScreenArray();
void menu();

void array() {
    int size, choice;
    int* arr = NULL;

    if(!isInitialized) {
        clearScreenArray();
        printf("\t\t\t\t\t\t\t\t\033[1;35mEnter the size of the array:\033[0m ");
        if(scanf("%d", &size) != 1 || size < 1) {
            printf("\t\t\t\t\t\t\033[1;31mInvalid input. The size must be a positive integer or not equal to zero.\033[0m\n");
            usleep(2e+6);
            clearScreenArray();
            return;
        }
        isInitialized = 1;
    }

    arr = (int*)malloc(size * sizeof(int));
    if(arr == NULL) {
        clearScreenArray();
        printf("\n\n\n\t\t\t\t\t\t\t\t\033[1;31mError: Memory allocation failed.\033[0m\n");
        usleep(2e+6);
        clearScreenArray();
        exit(1);
    }
    printf("\n");
    if(!hasElements) {
        for(size_t i = 0; i < size; i++) {
            printf("\t\t\t\t\t\t\t\t\033[1;33mEnter element [\033[0m\033[1;32m%zu\033[0m\033[1;33m]\033[0m: ", i);
            scanf("%d", &arr[i]);
        }
        hasElements = 1;
    }

    while(1) {
        clearScreenArray();
        do {
            printf("\t\t\t\t\t\t\t\t   \033[1;35mPlease choose an operations\033[0m\n");
            printf("\033[1;37m");
            printf("\t\t\t\t\t\t\t\t _________________________________ \n");
            printf("\t\t\t\t\t\t\t\t/                                 \\\n");
            printf("\t\t\t\t\t\t\t\t|         Operations Menu:        |\n");
            printf("\t\t\t\t\t\t\t\t|      Press '1' to Traverse      |\n");
            printf("\t\t\t\t\t\t\t\t|     Press '2' for Insertion     |\n");
            printf("\t\t\t\t\t\t\t\t|      Press '3' for Deletion     |\n");
            printf("\t\t\t\t\t\t\t\t|       Press '4' to Search       |\n");
            printf("\t\t\t\t\t\t\t\t|       Press '5' to Update       |\n");
            printf("\t\t\t\t\t\t\t\t|      Press '6' to Display       |\n");
            printf("\t\t\t\t\t\t\t\t|  Press '7' to Clear all Arrays  |\n");
            printf("\t\t\t\t\t\t\t\t|      Press '8' to go Back       |\n");
            printf("\t\t\t\t\t\t\t\t\\_________________________________/\n");
            printf("\n\t\t\t\t\t\t\t\t");
            printf("   Enter your choice of number:\033[0m ");
            if(scanf("%d", &choice) != 1) {
                printf("\033[1;31m\n\t\t\t\t\t\t\t\tInvalid input. Please enter a number.\033[0m\n");
                usleep(2e+6);
                clearScreenArray();
                while(getchar() != '\n');
                continue;
            }
            if(choice < 1 || choice > 8) {
                printf("\033[1;31m\n\t\t\t\t\t\t\tInvalid choice. Please choose a number between 1 and 8.\033[0m\n");
                usleep(2e+6);
                clearScreenArray();
                continue;
            }
            switch(choice) {
                case 1:
                    // Traverse
                    if(!hasElements || arr == NULL) {
                        clearScreenArray();
                        printf("\033[1;31mArray is empty.\033[0m\n");
                        usleep(2e+6);
                        printf("Going back to menu...\n");
                        usleep(2e+6);
                        clearScreenArray();
                        menu();
                        break;
                    }
                    clearScreenArray();
                    printf("\t\t\t\t\t\t\t\t        Array elements:\n\n");
                    usleep(1e+6);
                    printf("\033[1;36m");
                    printf("\t\t\t\t\t\t\t\t _________________________________ \n");
                    printf("\t\t\t\t\t\t\t\t/                                 \\\n");
                    for(size_t i = 0; i < size; i++) {
                        printf("\t\t\t\t\t\t\t\t      Index [%zu] Element [%d]      \n", i, arr[i]);
                        usleep(1e+6);
                    }
                    printf("\t\t\t\t\t\t\t\t\\_________________________________/\033[0m\n");
                    usleep(2e+6);
                    printf("\n\n    \t\t\t\t\t\t\t\t    Press any key to go back...");
                    getchar();
                    char input = getchar();
                    clearScreenArray();
                    break;
                case 2:
                    // Insertion
                    if(!isInitialized) {
                        clearScreenArray();
                        printf("Array is not initialized. Please initialize the array first.\n");
                        usleep(2e+6);
                        printf("Going back to menu...\n");
                        usleep(2e+6);
                        clearScreenArray();
                        menu();
                        break;
                    }
                    int insertChoice;
                    clearScreenArray();
                    printf("\t\t\t\t\t\t\t\tPlease choose insertion type:\n\t\t\t\t\t\t\t\t1. Beginning\n\t\t\t\t\t\t\t\t2. End\n\t\t\t\t\t\t\t\t3. At Index\n");
                    printf("\t\t\t\t\t\t\t\tEnter your choice: ");
                    if(scanf("%d", &insertChoice) != 1 || (insertChoice < 1 || insertChoice > 3)) {
                        clearScreenArray();
                        printf("Invalid choice. Please enter a valid option (1, 2, or 3).\n");
                        usleep(2e+6);
                        clearScreenArray();
                        break;
                    }
                    int element, index;
                    switch(insertChoice) {
                        case 1:
                            clearScreenArray();
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
                            printf("\nElement inserted at the beginning.\n");
                            usleep(2e+6);
                            clearScreenArray();
                            break;
                        case 2:
                            clearScreenArray();
                            printf("Enter the element to insert at the end: ");
                            scanf("%d", &element);
                            arr = (int*)realloc(arr, (size + 1) * sizeof(int));
                            if(arr == NULL) {
                                printf("Memory allocation failed.\n");
                                usleep(2e+6);
                                clearScreenArray();
                                exit(1);
                            }
                            arr[size++] = element;
                            printf("\nElement inserted at the end.\n");
                            usleep(2e+6);
                            clearScreenArray();
                            break;
                        case 3:
                            clearScreenArray();
                            printf("Enter the index to insert at [0 to %d]: ", size);
                            scanf("%d", &index);
                            if(index < 0 || index > size) {
                                printf("Invalid index. Index must be between 0 and %d.\n", size);
                                usleep(2e+6);
                                clearScreenArray();
                                break;
                            }
                            printf("Enter the element to insert at index [%d]: ", index);
                            scanf("%d", &element);
                            arr = (int*)realloc(arr, (size + 1) * sizeof(int));
                            if(arr == NULL) {
                                printf("Memory allocation failed.\n");
                                usleep(2e+6);
                                clearScreenArray();
                                exit(1);
                            }
                            for(size_t i = size; i > index; i--) {
                                arr[i] = arr[i - 1];
                            }
                            arr[index] = element;
                            size++;
                            printf("\nElement inserted at index [%d].\n", index);
                            usleep(2e+6);
                            clearScreenArray();
                            break;
                        default:
                            break;
                    }
                    usleep(2e+6);
                    break;
                case 3:
                    // Deletion
                    if(!hasElements || arr == NULL) {
                        clearScreenArray();
                        printf("Array is empty.\n");
                        usleep(2e+6);
                        printf("Going back to menu...\n");
                        usleep(2e+6);
                        clearScreenArray();
                        menu();
                        break;
                    }
                    int deleteChoice;
                    clearScreenArray();
                    printf("Please choose deletion type:\n1. Beginning\n2. End\n3. At Index\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &deleteChoice) != 1 || (deleteChoice < 1 || deleteChoice > 3)) {
                        clearScreenArray();
                        printf("Invalid choice. Please enter a valid option (1, 2, or 3).\n");
                        usleep(2e+6);
                        clearScreenArray();
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
                                usleep(2e+6);
                                clearScreenArray();
                                exit(1);
                            }
                            size--;
                            printf("\nElement deleted from the beginning.\n");
                            break;
                        case 2:
                            arr = (int *)realloc(arr, (size - 1) * sizeof(int));
                            if(arr == NULL && size > 1) {
                                printf("Memory reallocation failed.\n");
                                usleep(2e+6);
                                clearScreenArray();
                                exit(1);
                            }
                            size--;
                            printf("\nElement deleted from the end.\n");
                            break;
                        case 3:
                            int deleteIndex;
                            clearScreenArray();
                            printf("Enter the index to delete [0 to %d]: ", size - 1);
                            scanf("%d", &deleteIndex);
                            if(deleteIndex < 0 || deleteIndex >= size) {
                                printf("Invalid index. Index must be between [0 and %d].\n", size - 1);
                                usleep(2e+6);
                                clearScreenArray();
                                break;
                            }
                            for(size_t i = deleteIndex; i < size - 1; i++) {
                                arr[i] = arr[i + 1];
                            }
                            arr = (int *)realloc(arr, (size - 1) * sizeof(int));
                            if(arr == NULL && size > 1) {
                                printf("\nMemory reallocation failed.\n");
                                usleep(2e+6);
                                clearScreenArray();
                                exit(1);
                            }
                            size--;
                            printf("Element at index [%d] deleted successfully.\n", deleteIndex);
                            break;
                        default:
                            break;
                    }
                    usleep(2e+6);
                    clearScreenArray();
                    break;
                case 4:
                    // Search
                    if(!hasElements || arr == NULL) {
                        clearScreenArray();
                        printf("Array is empty.\n");
                        usleep(2e+6);
                        printf("Going back to menu...\n");
                        usleep(2e+6);
                        clearScreenArray();
                        menu();
                        break;
                    }
                    int searchChoice;
                    clearScreenArray();
                    printf("Please choose search type:\n1. By Index\n2. By Element\n");
                    printf("Enter your choice: ");
                    if(scanf("%d", &searchChoice) != 1 || (searchChoice < 1 || searchChoice > 2)) {
                        clearScreenArray();
                        printf("Invalid choice. Please enter a valid option (1 or 2).\n");
                        usleep(2e+6);
                        clearScreenArray();
                        break;
                    }
                    switch(searchChoice) {
                        case 1:
                            int searchIndex;
                            clearScreenArray();
                            printf("Enter the index to search [0 to %d]: ", size - 1);
                            scanf("%d", &searchIndex);
                            if(searchIndex < 0 || searchIndex >= size) {
                                printf("Invalid index. Index must be between [0 and %d].\n", size - 1);
                                usleep(2e+6);
                                clearScreenArray();
                                break;
                            }
                            printf("\nElement at index [%d] is: %d\n", searchIndex, arr[searchIndex]);
                            break;
                        case 2:
                            int searchElement;
                            clearScreenArray();
                            printf("Enter the element to search: ");
                            scanf("%d", &searchElement);
                            for(size_t i = 0; i < size; i++) {
                                if(arr[i] == searchElement) {
                                    printf("\nElement [%d] found at index [%zu].\n", searchElement, i);
                                    break;
                                }
                                if(i == size - 1) {
                                    printf("\nElement [%d] not found in the array.\n", searchElement);
                                }
                            }
                            break;
                        default:
                            break;
                    }
                    usleep(2e+6);
                    clearScreenArray();
                    break;
                case 5:
                    // Update
                    if(!hasElements || arr == NULL) {
                        clearScreenArray();
                        printf("Array is empty.\n");
                        usleep(2e+6);
                        printf("Going back to menu...\n");
                        usleep(2e+6);
                        clearScreenArray();
                        menu();
                        break;
                    }
                    int updateIndex, newValue;
                    clearScreenArray();
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
                    printf("\nElement at index [%d] updated successfully.\n", updateIndex);

                    usleep(2e+6);
                    clearScreenArray();
                    break;
                case 6:
                    // Display
                    if(!hasElements || arr == NULL) {
                        clearScreenArray();
                        printf("Array is empty.\n");
                        usleep(2e+6);
                        printf("Going back to menu...\n");
                        usleep(2e+6);
                        clearScreenArray();
                        menu();
                        break;
                    }
                    clearScreenArray();
                    printf("Array elements:\n\n");
                    usleep(1e+6);
                    for(size_t i = 0; i < size; i++) {
                        printf("Index [%zu] Element [%d]\n", i, arr[i]);
                    }
                    printf("\n");
                    usleep(2e+6);
                    printf("Press any key to go back...\n");
                    getchar();
                    char inputChar = getchar();
                    clearScreenArray();
                    break;
                case 7:
                    // Clear all Arrays
                    isInitialized = 0;
                    hasElements = 0;
                    free(arr);
                    arr = NULL;
                    clearScreenArray();
                    printf("The arrays have been cleared.\n");
                    usleep(2e+6);
                    clearScreenArray();
                    break;
                case 8:
                    // Back
                    clearScreenArray();
                    printf("Note: if you go back, it will reset your data and will not be preserved.\n[y / n]: ");
                    char option;
                    while(1) {
                        scanf(" %c", &option);
                        if(option == 'y' || option == 'Y') {
                            isInitialized = 0;
                            hasElements = 0;
                            clearScreenArray();
                            menu();
                        } else if(option == 'n'|| option == 'N') {
                            clearScreenArray();
                            break;
                        } else {
                            clearScreenArray();
                            printf("Invalid input. Please enter 'y' or 'n'.\n");
                            usleep(1e+6);
                            clearScreenArray();
                        }
                        printf("Note: if you go back, it will reset your data and will not be preserved.\n[y / n]: ");
                    }
                    clearScreenArray();
                    break;
            }
        } while(choice != 8);
    }
}

void clearScreenArray() {
    printf("\e[1;1H\e[2J");
}

#endif /* Array_H */
// End Array
