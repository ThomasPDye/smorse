#include "test_bonus_4_a_smorse.hpp"

int main(int argc, char **argv)
{
    int result = -1;
    if (argc == 2)
    {
        std::string word(argv[1]);
        result = test_smorse::test_bonus_4_a(word);
    }
    return result;
}
