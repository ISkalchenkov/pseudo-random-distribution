//
// Created by antarctica on 17.10.2020.
//

#include <getopt.h>
#include <cstdlib>
#include <stdexcept>
#include <climits>
#include <iostream>

#include "utils.hpp"

ulong utils::parameter_to_long(const char* string) {
    long val = strtol(string, nullptr, 0);

    if ((val == LONG_MAX || val == LONG_MIN) && errno == ERANGE) {
        throw std::range_error("prd: numerical parameter out of range");
    }

    return val;
}

void utils::display_usage() {
    std::cout << "prd - the program evenly and deterministically"
                 " outputs to the console a line from the file"
                 " and the number of the exam ticket.\n" << std::endl;
    std::cout << "Usage: ./prd --file <filename> --numtickets <N> --parameter <N>\n" << std::endl;
    std::cout << "Description:" << std::endl;
    std::cout << "-f, --file" << std::endl;
    std::cout << "\tfile" << std::endl;
    std::cout << "-n, --numtickets" << std::endl;
    std::cout << "\tnumber of tickets" << std::endl;
    std::cout << "-p --parameter" << std::endl;
    std::cout << "\tpermutation parameter" << std::endl;
    std::cout << "-h --help" << std::endl;
    std::cout << "\tdisplay this help" << std::endl;
}

utils::Options utils::parse_args(int argc, char *argv[]) {
    const char *optString = "f:n:p:h";
    const struct option longOpts[] = {
        {"file",       required_argument, nullptr, 'f'},
        {"numtickets", required_argument, nullptr, 'n'},
        {"parameter",  required_argument, nullptr, 'p'},
        {"help",       no_argument,       nullptr, 'h'},
        {nullptr,      no_argument,       nullptr,  0}
    };

    int opt = 0;
    int longIndex = 0;
    utils::Options options{};
    while ((opt = getopt_long(argc, argv, optString, longOpts, &longIndex)) != -1) {
        switch(opt) {
            case 'f':
                options.file_path = optarg;
                break;
            case 'n':
                options.num_tickets = parameter_to_long(optarg);
                break;
            case 'p':
                options.parameter = parameter_to_long(optarg);
                break;
            case'h':
                display_usage();
                exit(EXIT_SUCCESS);
            default:
                throw std::invalid_argument("prd: unrecognized option");
        }
    }

    if (options.file_path.empty() || options.num_tickets <= 0) {
        throw std::invalid_argument("prd: invalid arguments");
    }

    return options;
}

size_t utils::generate_number(const std::string& name, long num_tickets, long parameter) {
    size_t hash = std::hash<std::string>{}(name + std::to_string(parameter));
    return hash % num_tickets + 1;
}
