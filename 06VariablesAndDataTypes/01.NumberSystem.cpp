#include <iostream>

int main() {
    int a{15};           // Decimal
    int b{017};          // Octal
    int c{0x0F};         // Hexadecimal
    int d{0b00001111};   // Binary

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    return 0;
}