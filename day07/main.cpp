#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <map>
#include <vector>
#include <tuple>


auto program_tree(std::map<std::string, std::vector<std::string>> program_map) {

    for (const auto &program: program_map) {

        for (const auto &subprogram: program.second) {

            auto program_list = program_map[subprogram];

            if (program_list.size() > 0) {
                std::cout << program.first << " - " << program_list.size() << std::endl;
            }

        }

    }

    return 0;

}


int main() {

    auto line = std::string();
    auto in_file = std::ifstream("day07/input.txt");

    // ^([\w]+)\s\(([\d]+)\)(?:\s\-\>\s)?([\w\,?\s?]*)?$
    auto found = std::regex(R"(^([\w]+)\s\(([\d]+)\)(?:\s\-\>\s)?([\w\,?\s?]*)?$)");
    auto m = std::smatch();

    auto program_list = std::map<std::string, std::vector<std::string>>();

    if (in_file.is_open())
        while(getline(in_file, line)) {

            auto result = std::regex_search(line, m, found);

            if (result) {
                auto process_weight = std::stoi(m[2]);
                auto subprocess_list = std::vector<std::string>();

                if (m.size() > 2) {
                    auto s = std::string();
                    auto is = std::istringstream(m[3]);

                    while (std::getline(is, s, ',')) {
                        s.erase(
                                s.begin(),
                                std::find_if(s.begin(), s.end(), [](int ch){ return !std::isspace(ch); })
                        );
                        subprocess_list.push_back(s);
                    }
                }

                program_list.emplace(m[1], subprocess_list);
            }
        }

    in_file.close();

    auto main_program = program_tree(program_list);

}