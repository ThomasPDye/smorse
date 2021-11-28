#include "answer_bonus_3_a_smorse.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    int result = -1;
    if (argc == 3)
    {
        std::string ifname(argv[1]);
        std::string lstr(argv[2]);
        unsigned int l = (unsigned int) std::stoi(lstr);
        std::vector<std::string> word_results = answer_smorse::answer_bonus_3_a(ifname, l);
        for (std::vector<std::string>::iterator wi = word_results.begin(); wi != word_results.end(); wi++)
        {
            std::cout << *wi.base() << " ";
        }
        std::cout << std::endl;
        result = 0;
    }
    return result;
}
