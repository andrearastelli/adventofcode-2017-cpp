#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>


auto fill_spiral(int size) {
    std::cout << size << std::endl;



    return 0;
}


auto manhattan_spiral(int last_step) {
    auto size = std::sqrt(last_step) + 1;

    auto spiral = fill_spiral(size);

    return 0;
}


auto spiral_incremental(int last_step) {
    return 0;
}



int main() {
    assert(manhattan_spiral(1) == 0);
    // assert(manhattan_spiral(12) == 3);

    std::cout << manhattan_spiral(277678) << std::endl;
}