#include "test_bonus_5_a_smorse.hpp"
#include "bonus_smorse.hpp"

int test_smorse::test_bonus_5_a(std::string infilename, std::string code)
{
    int result = -1;
    std::vector<std::string> words = smorse::istrings(infilename);
    std::map<std::string, std::string> word_code_map = smorse::map_smorse(words);
    std::vector<std::string> codes = {code};
    std::vector<std::string> unused = smorse::unused_codes_in_map(word_code_map, codes);
    if (codes == unused)
    {
        result = 0;
    }
    return result;
}
