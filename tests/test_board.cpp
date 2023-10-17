#include <iostream>
#include "board.hpp"
#include "game.hpp"

int this_passes() {
    if (2 + 3 == 5) {
        std::cout << "Test passed";
        return 0;
    }
    else {
        std::cout << "Test failed";
        return 1;
    }
}

int this_fails() {
    if (2 + 3 == 6) {
        std::cout << "Test passed";
        return 0;
    }
    else {
        std::cout << "Test failed";
        return 1;
    }
}

int main() {
    return this_passes() || 
           this_fails();
}