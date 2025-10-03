#include <iostream>
#include "libmath.h"

int main() {
    int sum = add(5, 3);
    int diff = subtract(10, 4);
    std::cout << "5 + 3 = " << sum << std::endl;
    std::cout << "10 - 4 = " << diff << std::endl;
    return 0;
}
