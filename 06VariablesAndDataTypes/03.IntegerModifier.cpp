#include <iostream>

int main() {
    signed int value1{10};
    signed int value2{-300};

    std::cout << "Value 1: " << value1 << std::endl;
    std::cout << "Value 2: " << value2 << std::endl;

    std::cout << "\nSize of Value 1: " << sizeof(value1) << std::endl;
    std::cout << "Size of Value 2: " << sizeof(value2) << std::endl;

    unsigned int value3{4};
    // unsigned int value4{-5}; // Compiler Error.
}