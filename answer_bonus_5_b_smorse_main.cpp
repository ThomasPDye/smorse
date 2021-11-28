#include "answer_bonus_5_b_smorse.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    int result = -1;
    if (argc == 3)
    {
        std::string ifn(argv[1]);
        std::string lenstr(argv[2]);
        unsigned int l = (unsigned int)std::stoi(lenstr);
        std::vector<std::string> unused_codes = answer_smorse::answer_bonus_5_b(ifn, l);
        std::cout << unused_codes.size() << " ";
        for (std::vector<std::string>::iterator uc = unused_codes.begin(); uc != unused_codes.end(); uc++)
        {
            std::cout << " " << *uc.base();
        }
        std::cout << std::endl;
        result = 0;
    }
    return result;
}
