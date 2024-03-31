#include "Utility.hpp"

int util::randomize(int min, int max)
{
        static std::random_device rd;
        static std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> dis(min,max);
    
        return dis(gen);
}

void util::parse_json_file(std::string& json_buffer, const std::string& file_name)
{
        std::ifstream ist{file_name};
        std::string s;

        if (!ist) {
                throw std::runtime_error{"Cannot open the file" + file_name};
                return;
        }

        while (true) {
                ist >> s; 

                if (ist) 
                        json_buffer += s;

                if (ist.eof())
                        break;
                
                if (ist.bad())
                        ist.clear();
        }
}
