#include "test_smorse.hpp"
#include "smorse.hpp"

int morse::test_smorse(std::string i, std::string o)
{
    std::string r = smorse(i);
    return !(r == o);
}
