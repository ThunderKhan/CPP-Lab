#include <iostream>

int main() {
    int a{6};
    int b{3};
    int c{8};
    int d{9};
    int e{3};
    int f{2};
    int g{5};

    int result1 = a + b * c - d / e - f + g;
    std::cout << "Result 1: " << result1 << std::endl;

    int result2 = a / b * c + d - e + f;
    std::cout << "Result 2: " << result2 << std::endl;

    int result3 = a + (b * c) - (d / e) - f + g;
    std::cout << "Result 3: " << result3 << std::endl;
    
    int result4 = (a + b) * c - d / e - f + g;
    std::cout << "Result 4: " << result4 << std::endl;

    return 0;
}