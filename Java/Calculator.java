package Java;

import java.util.Scanner;

public class Calculator {
    
    public static void main(String[] args) {
        
        char operator;
        Double num1, num2, res;

        Scanner input = new Scanner(System.in);

        System.out.println("Choose an operator: +, -, *, or /");
        operator = input.next().charAt(0);

        System.out.println("Enter first number: ");
        num1 = input.nextDouble();

        System.out.println("Enter second number: ");
        num2 = input.nextDouble();

        switch (operator) {
            case '+':
                res = num1 + num2;
                System.out.println(num1 + " + " + num2 + " = " + res);
                break;
            case '-':
                res = num1 - num2;
                System.out.println(num1 + " - " + num2 + " = " + res);
                break;
            case '*':
                res = num1 * num2;
                System.out.println(num1 + " * " + num2 + " = " + res);
                break;
            case '/':
                res = num1 + num2;
                System.out.println(num1 + " / " + num2 + " = " + res);
                break;
        
            default:
                System.out.println("Invalid operator!");
                break;
        }

        input.close();
    }
}
