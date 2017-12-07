#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>


/**
 * Compute the difference between the min and max value from a list of int.
 *
 * @param line
 * @return
 */
auto line_difference_minmax(std::vector<int> line) {
    std::sort(line.begin(), line.end());

    return line.at(line.size() - 1) - line.at(0);
}


/**
 * Return the value of the division between the only two evenly divisible numbers in the list.
 *
 * @param line
 * @return
 */
auto evenly_divisible_value(std::vector<int> line) {
    for (std::size_t idx1=0; idx1<line.size()-1; ++idx1) {
        for (std::size_t idx2=1; idx2<line.size(); ++idx2) {
            auto v1 = line.at(idx1);
            auto v2 = line.at(idx2);

            if ((v1 % v2 == 0) && (v1 / v2 != 1)) {
                return v1 / v2;
            }
        }
    }

    return 0;
}


int main() {

    auto line = std::string();
    auto input_file = std::ifstream("day02/input.txt");

    if (input_file.is_open()) {

        auto count1 = 0;
        auto count2 = 0;

//        while(getline(input_file, line)) {
//            auto ilineit = std::istringstream(line);
//            auto num_list = std::vector<std::string>(
//                    std::istream_iterator<std::string>{ilineit},
//                    std::istream_iterator<std::string>{}
//            );
//
//            auto num_list_int = std::vector<int>();
//            for (std::string c :num_list) {
//                num_list_int.push_back(std::stoi(c));
//            }
//
//            count1 += line_difference_minmax(num_list_int);
//            count2 += evenly_divisible_value(num_list_int);
//
//        }
//
//        std::cout << count1 << std::endl;
//        std::cout << count2 << std::endl;
    }

}