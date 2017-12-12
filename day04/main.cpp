#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cassert>


auto check_passphrase_duplicate(std::vector<std::string> passphrase_list) {

    auto passphrase_map = std::map<std::string, int>();

    for (const std::string item:passphrase_list) {
        ++passphrase_map[item];

        if (passphrase_map[item] > 1) {
            return false;
        }
    }

    return true;
}


auto check_passphrase_rearranged(std::vector<std::string> passphrase_list) {

    for (const std::string item : passphrase_list) {

    }

    return false;
}


int main() {

    assert(check_passphrase_duplicate({"aa", "bb", "cc", "dd"}));
    assert(!check_passphrase_duplicate({"aa", "bb", "cc", "dd", "aa"}));
    assert(check_passphrase_duplicate({"aa", "bb", "cc", "dd", "aaa"}));

    // assert(check_passphrase_rearranged({"abcde", "fghij"}));

    auto line = std::string();
    auto in_file = std::ifstream("day04/input.txt");

    auto count_valid = 0;
    auto count_rearranged = 0;

    if (in_file.is_open())
        while(getline(in_file, line)) {

            auto token = std::string();
            auto token_stream = std::istringstream(line);
            auto tokens = std::vector<std::string>();

            while(std::getline(token_stream, token, ' ')) {
                tokens.push_back(token);
            }

            count_valid += check_passphrase_duplicate(tokens);
            count_rearranged += check_passphrase_rearranged(tokens);

        }

    in_file.close();

    std::cout << count_valid << std::endl;
    std::cout << count_rearranged << std::endl;

}