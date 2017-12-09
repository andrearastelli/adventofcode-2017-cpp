#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>


void print(std::vector<std::vector<int>> m) {
    for (auto i = 0; i < m.size(); ++i) {
        for (auto j = 0; j < m.size(); ++j) {
            std::cout << std::setw(4) << std::left <<  m[i][j];
        }
        std::cout << std::endl;
    }
}


auto fill_spiral(int size) {
    auto c = 1;
    auto m = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    // auto idx = {1, 0, -1, 0};
    // auto idy = {0, 1, 0, -1};

    for (auto i = 0; i < size; ++i) {
        for (auto j = 0; j < size; ++j) {
            // auto x = idx[i % 4];
            // auto y = idy[i % 4];
            // m[x][y] = c++;
        }
    }

    // print(m);

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

    std::cout << manhattan_spiral(12) << std::endl;
}