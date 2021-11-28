#include "answer_bonus_4_b_smorse.hpp"
#include "bonus_smorse.hpp"

std::map<std::string, std::vector<std::string>> answer_smorse::answer_bonus_4_b(std::string infilename, unsigned int word_length)
{
    std::map<std::string, std::vector<std::string>> answer_map;
    std::vector<std::string> words = smorse::istrings(infilename);
    std::vector<std::string> words_of_length;
    std::map<std::string, std::string> word_code_map;
    for (std::vector<std::string>::iterator wi = words.begin(); wi != words.end(); wi++)
    {
        if (wi->size() == word_length)
        {
            words_of_length.push_back(*wi.base());
        }
    }
    word_code_map = smorse::map_smorse(words_of_length);
    for (std::map<std::string, std::string>::iterator wci = word_code_map.begin(); wci != word_code_map.end(); wci++)
    {
        if (smorse::palindrome(wci->second))
        {
            answer_map[wci->second].push_back(wci->first);
        }
    }
    return answer_map;
}
