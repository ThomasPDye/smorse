#include "answer_bonus_4_b_smorse.hpp"
#include <iostream>

int main (int argc, char ** argv)
{
    int result = -1;
    if (argc == 3)
    {
        std::string ifn(argv[1]);
        std::string nstr(argv[2]);
        unsigned int l = (unsigned int) std::stoi(nstr);
        std::map<std::string, std::vector<std::string>> answers = answer_smorse::answer_bonus_4_b(ifn, l);
        for (std::map<std::string, std::vector<std::string>>::iterator ai = answers.begin(); ai != answers.end(); ai++)
        {
            std::cout << ai->first << " " << ai->second.size();
            for (std::vector<std::string>::iterator wi = ai->second.begin(); wi != ai->second.end(); wi++)
            {
                std::cout << " " << *wi.base();
            }
            std::cout << std::endl;
        }
    }
    return result;
}
