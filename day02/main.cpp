#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>


auto line_difference_minmax(std::vector<std::string> line) {
    std::min(line);
    std::max(line);
}


auto spreadsheet_checksum() {
    return "";
}


int main() {

    auto line = std::string();
    auto input_file = std::ifstream("day02/input.txt");

    if (input_file.is_open()) {
        while(getline(input_file, line)) {
            auto ilineit = std::istringstream(line);
            auto num_list = std::vector<std::string>(
                    std::istream_iterator<std::string>{ilineit},
                    std::istream_iterator<std::string>{});

            for (std::string c :num_list) {
                std::cout << c << " ";
            }
            std::cout << std::endl;
        }
    }

}