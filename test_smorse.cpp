#include "test_smorse.hpp"
#include "smorse.hpp"

int test_smorse::test_smorse(std::string i, std::string o)
{
    std::string r = smorse::smorse(i);
    return !(r == o);
}
