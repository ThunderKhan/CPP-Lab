#include <iostream>

int main() {
    char character1{'a'};
    char character2{'y'};
    char character3{'a'};
    char character4{'n'};

    std::cout << character1;
    std::cout << character2;
    std::cout << character3;
    std::cout << character4 << std::endl;

    char value = 65;
    std::cout << "Value: " << value << std::endl;
    std::cout << "Integer Value: " << static_cast<int>(value) << std::endl;
    return 0;
}