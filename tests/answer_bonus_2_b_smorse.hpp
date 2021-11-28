#pragma once

#include <map>
#include <vector>
#include <string>

namespace answer_smorse
{
    std::map<std::string, std::vector<std::string>> answer_bonus_2_b(std::string infilename, char c, unsigned int c_in_a_row);
} // namespace answer_smorse
