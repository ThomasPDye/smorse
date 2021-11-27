#include "answer_bonus_2_b_smorse.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    int result = -1;
    if (argc == 4)
    {
        std::string ifname(argv[1]);
        std::string charstr(argv[2]);
        std::string countstr(argv[3]);
        if (charstr.size() == 1ul)
        {
            char c = charstr[0];
            unsigned int count = (unsigned int)std::stoi(countstr);
            std::map<std::string, std::vector<std::string>> answer_map = answer_smorse::answer_bonus_2_b(ifname, c, count);
            for (std::map<std::string, std::vector<std::string>>::iterator ai = answer_map.begin(); ai != answer_map.end(); ai++)
            {
                std::cout << ai->first << " " << ai->second.size() << " ";
                for (std::vector<std::string>::iterator wi = ai->second.begin(); wi != ai->second.end(); wi++)
                {
                    std::cout << " " << *wi.base();
                }
                std::cout << std::endl;
            }
            result = 0;
        }
    }
    return result;
}
