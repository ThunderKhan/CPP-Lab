#include <iostream>

void showMenu() {
    std::cout << "\n--- Welcome to the Calculator! ---\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "0. To exit\n";
    std::cout << "Choose an operation: ";
}

int readChoice() {
    int choice;
    std::cin >> choice;
    return choice;
}

void readNumbers(double &a, double &b) {
    std::cout << "Enter first number: ";
    std::cin >> a;
    
    std::cout << "Enter second number: ";
    std::cin >> b;
}

double calculate(int choice, double a, double b) {
    switch(choice) {
        case 1: return a + b;
        case 2: return a - b;
        case 3: return a * b;
        case 4:
            if (b == 0) {
                std::cerr << "Error: Division by Zero is not allowed.\n";
                return 0;
            }
            return a / b;
        default:
            std::cout << "Invalid oprtation.\n";
            return 0;
    }
}

int main() {
    while (true) {
        showMenu();
        int choice = readChoice();

        if (choice == 0) {
            std::cout << "Goodbye\n";
            break;
        }

        if (choice < 1 || choice > 4) {
            std::cout << "Invalid Choice.\n";
            continue;
        }

        double x, y;
        readNumbers(x, y);

        double result = calculate(choice, x, y);
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}