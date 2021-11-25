#include "smorse.hpp"
#include "coding.hpp"

std::string morse::smorse(std::string in)
{
    std::string result;
    for (size_t s = 0ul; s < in.size(); s++)
    {
        result += morse::coding.at(in[s]);
    }
    return result;
}
