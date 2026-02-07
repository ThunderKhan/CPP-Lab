#include <iostream>

int main() {
    // Standard use of boolean values.
    bool red_light{true};
    bool green_light{false};

    if (red_light == true)  {
        std::cout << "Stop!" << std::endl;
    } else {
        std::cout << "Go through!" << std::endl;
    }

    if (green_light) {
        std::cout << "The light is green!" << std::endl;
    } else {
        std::cout << "The light is NOT green!" << std::endl;
    }


    // Printing bool.
    std::cout << "Size of bool: " << sizeof(bool) << std::endl;
    std::cout << "Red light: " << red_light << std::endl;
    std::cout << "Green light: " << green_light << std::endl;

    // Printing bool as True or False.
    std::cout << std::boolalpha;
    std::cout << "Red light: " << red_light << std::endl;
    std::cout << "Green light: " << green_light << std::endl;

    return 0;
}