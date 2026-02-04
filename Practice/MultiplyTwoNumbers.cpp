#include <iostream>

int multiplyNumbers(int num1, int num2) {
    return num1 * num2;
}

int main() {
    int a = 57;
    int b = 78;

    int result = multiplyNumbers(a, b);
    std::cout << "Result: " << result << std::endl;
    return 0;
}