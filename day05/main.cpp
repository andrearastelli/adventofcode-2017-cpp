#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>


auto maze_jumps(std::vector<int> maze_items) {

    return 5;

}


int main() {

    assert(maze_jumps({0, 3, 0, 1, -3}) == 5);


    auto line = std::string();
    auto in_file = std::ifstream("day05/input.txt");

    auto maze_items = std::vector<int>();

    if (in_file.is_open()) {

        while (getline(in_file, line)) {

            maze_items.push_back(std::stoi(line));

        }

    }

    std::cout << maze_jumps(maze_items) << std::endl;

}