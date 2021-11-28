#include "test_bonus_4_a_smorse.hpp"
#include "bonus_smorse.hpp"
#include "smorse.hpp"

int test_smorse::test_bonus_4_a(std::string s)
{
    int result = -1;
    std::string code = smorse::smorse(s);
    if (smorse::palindrome(code))
    {
        result = 0;
    }
    return result;
}
