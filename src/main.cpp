//
// Created by antarctica on 17.10.2020.
//

#include <stdexcept>
#include <iostream>
#include <fstream>

#include "utils.hpp"

int main(int argc, char *argv[]) {
    std::string help_msg("Usage: ./prd --file <filename> --numtickets <N> --parameter <N>");
    utils::Options options{};
    try {
        options = utils::parse_args(argc, argv);
    } catch (std::range_error &err) {
        std::cerr << err.what() << std::endl;
        std::cout << help_msg << std::endl;
        return EXIT_FAILURE;
    } catch (std::invalid_argument &err) {
        std::cerr << err.what() << std::endl;
        std::cout << help_msg << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream file(options.file_path);
    if (!file.is_open()) {
        std::cerr << "prd: can't open the file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string name;
    while (std::getline(file, name)) {
        size_t number = utils::generate_number(name, options.num_tickets, options.parameter);
        std::cout << name << " " << number << std::endl;
    }
}
