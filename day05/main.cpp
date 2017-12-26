#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>

template <typename T>
void print_list(std::vector<T> list) {
    for (std::size_t i=0; i<list.size(); ++i)
        std::cout << i << ": " << list[i] << "; ";
    std::cout << std::endl;
}


auto maze_jumps(std::vector<int> maze_items, bool offset) {

    auto exit = false;
    auto idx = 0;
    auto step = 0;

    while (!exit) {

        auto tmp_idx = maze_items[idx];

        if (offset)
            if (tmp_idx >= 3)
                maze_items[idx]--;
            else
                maze_items[idx]++;
        else
            maze_items[idx]++;

        step++;

        if ((idx + tmp_idx) >= maze_items.size())
            exit = true;
        else
            idx += tmp_idx;

        //print_list(maze_items);
//        std::cout << "Step: " << step << "; ";
//        std::cout << "Current IDX (and array val): " << tmp_idx << "; ";
//        std::cout << "Next IDX: " << idx << "; ";
//        std::cout << "Array at next: " << maze_items[idx] << "; ";
//        std::cout << "Array size: " << maze_items.size() << "; ";
//        std::cout << "Next step will exit --> " << exit;
//        std::cout << std::endl;

    }

    return step;

}


int main() {

    auto v = {0, 3, 0, 1, -3};
    assert(maze_jumps(v, false) == 5);
    assert(maze_jumps(v, true) == 10);


    auto line = std::string();
    auto in_file = std::ifstream("day05/input.txt");

    auto maze_items = std::vector<int>();

    if (in_file.is_open()) {

        while (getline(in_file, line)) {

            maze_items.push_back(std::stoi(line));

        }

    }

    std::cout << maze_jumps(maze_items, false) << std::endl;
    std::cout << maze_jumps(maze_items, true) << std::endl;

}