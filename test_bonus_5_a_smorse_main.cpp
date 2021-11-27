#include "test_bonus_5_a_smorse.hpp"

int main(int argc, char **argv)
{
    int result = -1;
    if (argc == 3)
    {
        std::string ifn(argv[1]);
        std::string code(argv[2]);
        result = test_smorse::test_bonus_5_a(ifn, code);
    }
    return result;
}
