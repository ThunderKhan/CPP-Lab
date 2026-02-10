#include <iostream>

int main() {
    int value1{5};

    value1 = value1 + 1;
    std::cout << "The increased value is: " << value1 << std::endl;

    int value2{3};

    value2 = value2 - 1;
    std::cout << "The increased value is: " << value2 << std::endl;

    std::cout << "\n==Postfix increment and decrement==\n" << std::endl;

    int value3{5};
    std::cout << "The current value is: " << value3 << std::endl;
    std::cout << "The value while incrementing: " << value3++ << std::endl;
    std::cout << "The value after incrementing: " << value3 << std::endl;
    
    int value4{1};
    std::cout << "\nThe current value is: " << value4 << std::endl;
    std::cout << "The value while decrementing: " << value4-- << std::endl;
    std::cout << "The value after decrementing: " << value4 << std::endl;
    
    std::cout << "\n==Prefix increment and decrement==\n" << std::endl;

    int value5{5};
    std::cout << "The current value is: " << value5 << std::endl;
    std::cout << "The value while incrementing: " << ++value5 << std::endl;
    std::cout << "The value after incrementing: " << value5 << std::endl;
    
    int value6{1};
    std::cout << "\nThe current value is: " << value6 << std::endl;
    std::cout << "The value while decrementing: " << --value6 << std::endl;
    std::cout << "The value after decrementing: " << value6 << std::endl;

    return 0;
}