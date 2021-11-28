#include "test_bonus_2_a_smorse.hpp"
#include "bonus_smorse.hpp"
#include "smorse.hpp"

int test_smorse::test_bonus_2_a(std::string word, char c, unsigned int in_a_row)
{
    int result = -1;
    std::string code = smorse::smorse(word);
    unsigned int max_in_row = smorse::max_in_a_row(code, c);
    if (max_in_row == in_a_row)
        result = 0;
    return result;
}
