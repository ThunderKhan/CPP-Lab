#include <iostream>
#include <random>

int main() {
    // Random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);    
    int x = dist(gen);
   
    while(true) {
        // Prompt the user
        int number;
        std::cout << "Enter a Number (1 - 100): ";
        std::cin >> number;
        std::cout << std::endl;

        // Game loop
        if (number > x) {
            std::cout << "Too big! Try a smaller number." << std::endl;
        } else if (number < x) {
            std::cout << "Too small, try a larger number." << std::endl;
        } else {
            std::cout << "Congratulations! you found the target number." << std::endl;
            std::cout << "Thank you for playing!" << std::endl;
            break;
        }
    }  

    return 0;
}