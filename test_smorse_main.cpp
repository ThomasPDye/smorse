#include "test_smorse.hpp"

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        std::string i(argv[1]), o(argv[2]);
        return test_smorse::test_smorse(i, o);
    }
    else
    {
        return -1;
    }
}
