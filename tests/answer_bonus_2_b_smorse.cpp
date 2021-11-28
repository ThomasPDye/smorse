#include "answer_bonus_2_b_smorse.hpp"
#include "bonus_smorse.hpp"

std::map<std::string, std::vector<std::string>> answer_smorse::answer_bonus_2_b(std::string infilename, char c, unsigned int c_in_a_row)
{
    std::map<std::string, std::vector<std::string>> results;
    std::vector<std::string> all_words = smorse::istrings(infilename);
    std::map<std::string, std::string> word_code_map = smorse::map_smorse(all_words);
    for (std::map<std::string, std::string>::iterator wci = word_code_map.begin(); wci != word_code_map.end(); wci++)
    {
        if (smorse::max_in_a_row(wci->second,c) == c_in_a_row)
        {
            results[wci->second].push_back(wci->first);
        }
    }
    return results;
}
