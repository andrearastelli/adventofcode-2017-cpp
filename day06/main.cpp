#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>


auto memory_redistribution(std::vector<int> memory_bank) {

    auto max = std::max_element(memory_bank.begin(), memory_bank.end());

    for (int iters{std::exchange(*max, 0)}; iters--; ++*max) {
        if (++max == memory_bank.end())
            max = memory_bank.begin();
    }

    return memory_bank;

}


auto memory_redistribution_step(std::vector<int> memory_bank) {

    auto step = std::pair<std::vector<int>, std::vector<int>>(
            memory_redistribution(memory_bank),
            memory_redistribution(memory_redistribution(memory_bank))
    );

    auto step0 = step.first;
    auto step1 = step.second;

    while (step0 != step1) {
        step0 = memory_redistribution(step0);
        step1 = memory_redistribution(memory_redistribution(step1));
    }

    auto mu = 0;

    for (step0 = memory_bank; step0 != step1; step0 = memory_redistribution(step0), step1 = memory_redistribution(step1)) {
        ++mu;
    }

    auto lambda = 1;

    for (step1 = memory_redistribution(step0); step0 != step1; step1 = memory_redistribution(step1)) {
        ++lambda;
    }

    return std::pair<int, int>(mu, lambda);

}


int main() {

    auto memory_banks = std::vector<int>({0, 5, 10, 0, 11, 14, 13, 4, 11, 8, 8, 7, 1, 4, 12, 11});

    auto p = memory_redistribution_step(memory_banks);

    std::cout << p.first << " - " << p.second << std::endl;

    std::cout << p.first + p.second << std::endl;

}