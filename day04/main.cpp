#include <iostream>
#include <fstream>
#include <string>
#include <list>


auto check_passphrase_duplicate(std::list<std::string> passphrase_list) {



    return false;
}


int main() {

    auto line = std::string();
    auto in_file = std::ifstream("day04/input.txt");

    if (in_file.is_open())
        while(getline(in_file, line)) {

            std::cout << line << std::endl;

        }

    in_file.close();

}