#pragma once
#include <random>
#include <fstream>
#include <memory>

#define clocked_msg(message) \
        std::cout << "[" << clocked_time << "] " << (message) << ".\n"

#define clocked_debug(message, var) \
        std::cout << "[" << clocked_time << "] " << (message) << ": " << (var) << "\n"

namespace util
{
        int randomize(int min, int max);
        void parse_json_file(std::string &json_buffer, const std::string &file_name);
}
