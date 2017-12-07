#include <iostream>
#include <fstream>
#include <string>


/**
 * Generates the inverse captcha function.
 *
 * From an input file with a single line string that contains numbers,
 * this captcha checks the numeric value of each character with the next one
 * and if they are equal,
 *
 * @param line numeric string line to parse
 * @return the sum resulting value
 */
auto inverse_captcha(const std::string line, std::size_t step) {

    auto counter = 0;

    std::cout << "Line length: " << line.length() << std::endl;

    for(std::size_t i=0; i<line.length(); ++i) {
        auto c1 = line.substr(i, 1);
        std::size_t idx2 = (i + step) % line.length();
        auto c2 = line.substr(idx2, 1);
        auto i1 = std::stoi(c1);
        auto i2 = std::stoi(c2);

        if (i1 == i2) {
            counter += i1;
        }
    }

    return counter;

}


int main() {

    std::string line;

    std::ifstream input_file("day01/input.txt");
    if (input_file.is_open()) {
        while(getline(input_file, line)) {
            std::cout << inverse_captcha(line, 1) << std::endl;
            std::size_t halfway = static_cast<std::size_t >(line.length() / 2);
            std::cout << inverse_captcha(line, halfway) << std::endl;
        }
        input_file.close();
    }

}
