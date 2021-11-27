#include "answer_bonus_1_b_smorse.hpp"
#include "bonus_smorse.hpp"

std::map<std::string, std::vector<std::string>> answer_smorse::answer_bonus_1_b(std::string infilename, unsigned int num_words)
{
    std::map<std::string, std::vector<std::string>> results;
    std::vector<std::string> codes;
    std::vector<std::string> words = smorse::istrings(infilename);
    std::map<std::string, std::string> word_code_map = smorse::map_smorse(words);
    std::map<std::string, unsigned int> code_occurence_map = smorse::map_smorse_occurences(word_code_map);
    for (std::map<std::string, unsigned int>::iterator iocc = code_occurence_map.begin(); iocc != code_occurence_map.end(); iocc++)
    {
        if (iocc->second == num_words)
        {
            codes.push_back(iocc->first);
        }
    }
    for (std::vector<std::string>::iterator c = codes.begin(); c != codes.end(); c++)
    {
        for (std::map<std::string, std::string>::iterator wci = word_code_map.begin(); wci != word_code_map.end(); wci++)
        {
            if(wci->second == *c.base())
                results[*c.base()].push_back(wci->first);
        }
    }
    return results;
}
