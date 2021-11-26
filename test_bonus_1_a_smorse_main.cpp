#include "test_bonus_1_a_smorse.hpp"

int main(int argc, char **argv)
{
    int result = -1;
    if (argc >= 4)
    {
        std::string ifname(argv[1]);
        std::string code(argv[2]);
        std::vector<std::string> words;
        for (int ai = 3; ai < argc; ai++)
        {
            words.push_back(argv[ai]);
        }
        result = test_smorse::bonus_test_1_a(ifname, code, words);
    }
    return result;
}
