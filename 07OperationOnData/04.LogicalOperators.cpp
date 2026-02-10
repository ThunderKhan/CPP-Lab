#include <iostream>

int main() {
    bool a{true};
    bool b{false};
    bool c{true};

    std::cout << std::boolalpha;
    std::cout << "a: "  << a << std::endl;
    std::cout << "b: "  << b << std::endl;
    std::cout << "c: "  << c << std::endl;

    // AND: Evaluates to ture when all operarands are true.
    //      A single false operand will drag the entire
    //      expression to evaluating false.

    std::cout << std::endl;
    std::cout << "Basic AND operations\n" << std::endl;

    std::cout << "a AND b: " << (a && b) << std::endl;
    std::cout << "a AND c: " << (a && c) << std::endl;
    std::cout << "a AND b AND c: " << (a && b && c) << std::endl;
    
    // OR: Evaluates to true when at least one operarands is true.
    //     A single true operand will drag the entire
    //     expression to evaluating true.

    std::cout << std::endl;
    std::cout << "Basic OR operations\n" << std::endl;

    std::cout << "a OR b: " << (a || b) << std::endl;
    std::cout << "a OR c: " << (a || c) << std::endl;
    std::cout << "a OR b OR c: " << (a || b || c) << std::endl;
    
    // NOT: Negates the operadnd and flips thier value.

    std::cout << std::endl;
    std::cout << "Basic NOT operations\n" << std::endl;

    std::cout << "NOT a: " << (!a) << std::endl;
    std::cout << "NOT b: " << (!b) << std::endl;
    std::cout << "NOT c: " << (!c) << std::endl;
    
    std::cout << std::endl;
    std::cout << "Combined operations\n" << std::endl;

    std::cout << "NOT(a AND b) OR c: " << (!(a && b) || c) << std::endl;

    return 0;
}