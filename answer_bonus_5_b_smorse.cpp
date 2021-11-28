#include "answer_bonus_5_b_smorse.hpp"
#include "bonus_smorse.hpp"

std::vector<std::string> answer_smorse::answer_bonus_5_b(std::string infilename, unsigned int length)
{
    std::vector<std::string> words = smorse::istrings(infilename);
    std::map<std::string, std::string> word_code_map = smorse::map_smorse(words);
    return smorse::unused_codes_in_map(word_code_map, smorse::all_pseudo_codes_of_length(length));
}
