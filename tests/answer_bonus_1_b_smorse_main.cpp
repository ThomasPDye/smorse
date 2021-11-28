#include "answer_bonus_1_b_smorse.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        std::string ifname(argv[1]);
        std::string numstr(argv[2]);
        unsigned int num = (unsigned int)std::stoi(numstr);
        std::map<std::string, std::vector<std::string>> answer_map = answer_smorse::answer_bonus_1_b(ifname, num);
        for (std::map<std::string, std::vector<std::string>>::iterator ai = answer_map.begin(); ai != answer_map.end(); ai++)
        {
            std::cout << ai->first << " " << ai->second.size() << " ";
            for (std::vector<std::string>::iterator wi = ai->second.begin(); wi != ai->second.end(); wi++)
            {
                std::cout << " " << *wi.base();
            }
            std::cout << std::endl;
        }
        return 0;
    }
    return -1;
}
