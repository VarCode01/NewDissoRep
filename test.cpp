#include <iostream>
#include <cstring> // For strcpy

void calculator() {
    char operation[10];
    char input1[5], input2[5];

    std::cout << "Enter operation (add, sub, mul, div): ";
    std::cin >> operation;

    std::cout << "Enter first number: ";
    std::cin >> input1;

    std::cout << "Enter second number: ";
    std::cin >> input2;

    char buffer[5];
    strcpy(buffer, input1); // Vulnerable: No bounds checking on input1

    int num1 = atoi(input1);
    int num2 = atoi(input2);

    if (strcmp(operation, "add") == 0) {
        std::cout << "Result: " << num1 + num2 << std::endl;
    } else if (strcmp(operation, "sub") == 0) {
        std::cout << "Result: " << num1 - num2 << std::endl;
    } else if (strcmp(operation, "mul") == 0) {
        std::cout << "Result: " << num1 * num2 << std::endl;
    } else if (strcmp(operation, "div") == 0) {
        if (num2 != 0) {
            std::cout << "Result: " << num1 / num2 << std::endl;
        } else {
            std::cout << "Error: Division by zero!" << std::endl;
        }
    } else {
        std::cout << "Invalid operation!" << std::endl;
    }
}

int main() {
    calculator();
    return 0;
}