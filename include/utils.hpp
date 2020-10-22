//
// Created by antarctica on 17.10.2020.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace utils {

struct Options {
    std::string file_path;
    long num_tickets;
    long parameter;
};
using Options = struct Options;

Options parse_args(int argc, char *argv[]);
ulong parameter_to_long(const char* string);
void display_usage();

size_t generate_number(const std::string& name, long num_tickets, long parameter);

} // namespace utils

#endif // UTILS_H
