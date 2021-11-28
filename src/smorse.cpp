#include "smorse.hpp"
#include "coding.hpp"

std::string smorse::smorse(std::string in)
{
    std::string result;
    for (size_t s = 0ul; s < in.size(); s++)
    {
        result += smorse::coding.at(in[s]);
    }
    return result;
}
