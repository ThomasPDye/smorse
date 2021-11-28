#pragma once

#include <map>
#include <vector>
#include <string>
#include <utility>

namespace smorse
{
    std::vector<std::string> istrings(std::string infilename);
    std::map<std::string, std::string> map_smorse(std::vector<std::string> words);
    std::map<std::string, unsigned int> map_smorse_occurences(std::map<std::string, std::string> word_code_map);
    std::vector<std::string> find_smorse_words(std::map<std::string, std::string> word_code_map, std::string code);
    unsigned int max_in_a_row(std::string s, char c);
    unsigned int count(std::string s, char c);
    std::pair<unsigned int, unsigned int> count2(std::string s, char c1, char c2);
    bool code_balanced(std::string code);
    bool palindrome(std::string s);
    std::vector<std::string> all_pseudo_codes_of_length(std::size_t l);
    std::vector<std::string> all_actual_codes_of_length(std::size_t l);
    std::vector<std::string> unused_codes_in_map(std::map<std::string, std::string> word_code_map, std::vector<std::string> codes);
} // namespace smorse
