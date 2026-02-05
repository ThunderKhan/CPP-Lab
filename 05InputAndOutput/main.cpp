#include <iostream>
#include <string>

int main() {
    // std::cout << "Hello C++23!" << std::endl;
    
    // int age{21}; // Brace initialization.
    // std::cout << "Age: " << age << std::endl;

    // // Prints an Error
    // std::cerr << "Error 404: Cuteness not found!" << std::endl;

    // // Prints a log entry.
    // std::clog << "Log 01: This works!" << std::endl;

    // int age1;
    // std::string name;

    // std::cout << "Please type your name and age: " << std::endl;

    // std::cin >> name >> age1;

    // std::cout << "Hello " << name << " you are " << age1 << " years old!" << std::endl;

    std::string fullName;
    int age3;

    std::cout << "Please type in your full name and age: ";
    std::getline(std::cin, fullName);
    std::cin >> age3;

    std::cout << "Hello " << fullName 
            << " you are " << age3 << " years old!" << std::endl;

    return 0;
}
