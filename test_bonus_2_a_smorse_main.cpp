#include "test_bonus_2_a_smorse.hpp"

int main(int argc, char ** argv)
{
    int result = -1;
    if (argc == 4)
    {
        std::string word(argv[1]);
        std::string charstr(argv[2]);
        std::string countstr(argv[3]);
        char ccount;
        unsigned int ncount = (unsigned int) std::stoi(countstr);
        if (charstr.size() == 1ul) {
            ccount = charstr[0];
            result = test_smorse::test_bonus_2_a(word, ccount, ncount);
        }
    }
    return result;
}
