#include <iostream>

int main() {
    auto var1{12};      // Integer Value
    auto var2{6.7};     // Double Value
    auto var3{14.67f};  // Float Value
    auto var4{15.0l};   // Long Valur
    auto var5{'e'};     // Character Value

    // Auto with modifier suffixes
    auto var6{123u};    // Unsigned
    auto var7{123ul};   // Unsigned long
    auto var8{123ll};   // Long Long

    std::cout  << "Var1 occupies: " << sizeof(var1) << " bytes" << std::endl;
    std::cout  << "Var2 occupies: " << sizeof(var2) << " bytes" << std::endl;
    std::cout  << "Var3 occupies: " << sizeof(var3) << " bytes" << std::endl;
    std::cout  << "Var4 occupies: " << sizeof(var4) << " bytes" << std::endl;
    std::cout  << "Var5 occupies: " << sizeof(var5) << " bytes" << std::endl;
    std::cout  << "Var6 occupies: " << sizeof(var6) << " bytes" << std::endl;
    std::cout  << "Var7 occupies: " << sizeof(var7) << " bytes" << std::endl;
    std::cout  << "Var8 occupies: " << sizeof(var8) << " bytes" << std::endl;

    return 0;
}