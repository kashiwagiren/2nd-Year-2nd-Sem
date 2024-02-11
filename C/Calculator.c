#include <stdio.h>

int main() {

    int num1, num2, res;
    char operator;

    printf("Choose an operator: +, -, *, /\n");
    scanf("%c", &operator);

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (operator) {
        case '+':
            res = num1 + num2;
            printf("Total: %d", res);
            break;
        case '-':
            res = num1 - num2;
            printf("Total: %d", res);
            break;
        case '*':
            res = num1 * num2;
            printf("Total: %d", res);
            break;
        case '/':
            res = num1 / num2;
            printf("Total: %d", res);
            break;

        default:
            printf("Invalid operator!");
            break;
    }

    return 0;
}