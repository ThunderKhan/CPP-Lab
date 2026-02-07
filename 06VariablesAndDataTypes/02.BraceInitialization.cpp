#include <iostream>

int main() {
    int elephantCount; // Variable is initialized with grarbage value.

    int lionCount{}; // Initializes to Zero.
    int dogCount{10}; // Initializes to 10.
    int catCount{5}; // Initializes to 5.

    int domesticatedCount{dogCount + catCount}; // Can add values.

    // This throws an error because we are using a float initialized as int.
    int narrowingConversion{2.9};

    return 0;
}