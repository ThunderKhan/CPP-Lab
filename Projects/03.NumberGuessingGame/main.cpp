#include <iostream>
#include <random>

int main() {
    // Random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);    
    int x = dist(gen);
   
    // Prompt the user
    int number;
    std::cout << "Enter a Number (1 - 100): ";
    std::cin >> number;
    std::cout << std::endl;        

    return 0;
}