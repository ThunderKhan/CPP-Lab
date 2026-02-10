#include <iostream>
#include <random>

int main() {
    // Random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);    
    int x = dist(gen);

    int attempts{0};
   
    // Game loop
    while(true) {
        // Prompt the user
        int number;
        std::cout << "Enter a Number (1 - 100): ";
        std::cin >> number;

        attempts++;

        // Game logic
        if (number > x) {
            std::cout << "Too big! Try a smaller number." << std::endl;
            std::cout << "Current number of attempts: " << attempts << std::endl;
            std::cout << "\n";
        } else if (number < x) {
            std::cout << "Too small, try a larger number." << std::endl;
            std::cout << "Current number of attempts: " << attempts << std::endl;
            std::cout << "\n";
        } else {
            std::cout << "Congratulations! you found the target number." << std::endl;
            std::cout << "Total number of attempts: " << attempts << std::endl;
            std::cout << "\n";
            std::cout << "Thank you for playing!" << std::endl;
            break;
        }
    }  
    return 0;
}