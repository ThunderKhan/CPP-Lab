#include <iostream>
#include <string>

int main() {
    std::string firstPart;

    std::cout << "Enter a string that ends with '#': ";
    std::getline(std::cin, firstPart, '#');

    std::cout << firstPart << std::endl;
    return 0;
}