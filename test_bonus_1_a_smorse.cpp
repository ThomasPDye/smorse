#include "test_bonus_1_a_smorse.hpp"
#include "bonus_smorse.hpp"
#include "smorse.hpp"

int test_smorse::bonus_test_1_a(std::string infilename, std::string code, std::vector<std::string> words)
{
    std::vector<std::string> words_in;
    words_in = smorse::istrings(infilename);
    std::map<std::string, std::string> word_code_map = smorse::map_smorse(words_in);
    std::vector<std::string> matches;
    for (std::map<std::string, std::string>::iterator wci = word_code_map.begin(); wci != word_code_map.end(); wci++)
    {
        if (wci->second == code)
        {
            matches.push_back(wci->first);
        }
    }
    if (matches.size() == words.size())
    {
        bool found_all = true;
        for (std::vector<std::string>::iterator i = matches.begin(); i != matches.end(); i++)
        {
            bool found = false;
            for (std::vector<std::string>::iterator j = words.begin(); j != words.end(); j++)
            {
                if (*i.base() == *j.base())
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                found_all = false;
                break;
            }
        }
        if (found_all)
            return 0;
    }
    return -1;
}
