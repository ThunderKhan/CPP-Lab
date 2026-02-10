#include <iostream>
#include <random>
#include <limits>

int takeUserInput() {
    int guess;
    
    while (true) {
        std::cout << "Enter a Number (1 - 100): ";
        if (!(std::cin >> guess)) {
            std::cout << "Please enter a valid integer only.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (guess < 1 || guess > 100) {
            std::cout << "Number must be between 1 and 100.\n";
            continue;
        }
        break;
    }
    return guess;
}

int generateRandomInteger() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);    
    int randNumber = dist(gen);

    return randNumber;
}

int main() {
    int randomInteger = generateRandomInteger();
    int attempts{0};
   
    while(true) {
        int guess = takeUserInput();
        attempts++;

        if (guess > randomInteger) {
            std::cout << "Too big! Try a smaller number." << std::endl;
            std::cout << "Current number of attempts: " << attempts << std::endl;
            std::cout << "\n";
        } else if (guess < randomInteger) {
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