#include <iostream>
#include <fstream>
#include <string>

auto inverse_captcha(const std::string line) {

    auto counter = 0;

    std::cout << "Line length: " << line.length() << std::endl;

    for(std::size_t i=0; i<line.length()-1; ++i) {
        auto c1 = line.substr(i, 1);
        auto c2 = line.substr(i + 1, 1);
        auto i1 = std::stoi(c1);
        auto i2 = std::stoi(c2);

        if (i1 == i2) {
            counter += i1;
        }
    }

    auto f = line.substr(0, 1);
    auto l = line.substr(line.length()-1, 1);
    if (std::stoi(f) == std::stoi(l)) {
        counter += std::stoi(f);
    }

    return counter;

}


int main() {

    std::string line;

    std::cout << inverse_captcha("1111") << std::endl;

    std::ifstream input_file("day01/input.txt");
    if (input_file.is_open()) {
        while(getline(input_file, line)) {
            std::cout << inverse_captcha(line) << std::endl;
        }
        input_file.close();
    }

}
