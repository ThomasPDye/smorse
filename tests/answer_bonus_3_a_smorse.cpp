#include "answer_bonus_3_a_smorse.hpp"
#include "bonus_smorse.hpp"

std::vector<std::string> answer_smorse::answer_bonus_3_a(std::string ifname, unsigned int word_length)
{
    std::vector<std::string> results;
    std::vector<std::string> all_words = smorse::istrings(ifname);
    std::map<std::string, std::string> word_code_map = smorse::map_smorse(all_words);
    for (std::map<std::string, std::string>::iterator wci = word_code_map.begin(); wci != word_code_map.end(); wci++)
    {
        if (wci->first.size() == word_length && smorse::code_balanced(wci->second))
        {
            results.push_back(wci->first);
        }
    }
    return results;
}
