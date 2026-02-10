#include <iostream>

int main() {
    int value{45};
    std::cout << "The initial value is: " << value << std::endl;

    value += 5; // Same as value = value + 5;
    std::cout << "The value is: " << value << std::endl;
    
    value -= 5; // Same as value = value - 5;
    std::cout << "The value is: " << value << std::endl;
    
    value *= 2; // Same as value = value * 2;
    std::cout << "The value is: " << value << std::endl;
    
    value /= 3; // Same as value = value / 3;
    std::cout << "The value is: " << value << std::endl;
    
    value %= 11; // Same as value = value % 11;
    std::cout << "The value is: " << value << std::endl;

    return 0;
}