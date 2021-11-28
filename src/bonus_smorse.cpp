#include "bonus_smorse.hpp"
#include "smorse.hpp"
#include "coding.hpp"
#include <cmath>
#include <fstream>

std::vector<std::string> smorse::istrings(std::string infilename)
{
    std::ifstream in(infilename);
    std::vector<std::string> strings;
    while (!in.eof())
    {
        std::string word;
        in >> word;
        if (!word.empty())
            strings.push_back(word);
    }
    in.close();
    return strings;
}

std::map<std::string, std::string> smorse::map_smorse(std::vector<std::string> words)
{
    std::map<std::string, std::string> cw_map;
    for (std::vector<std::string>::iterator wi = words.begin(); wi != words.end(); wi++)
    {
        std::string w(wi->data());
        if (cw_map.count(w) == 0ul)
        {
            cw_map[w] = smorse::smorse(w);
        }
    }
    return cw_map;
}

std::map<std::string, unsigned int> smorse::map_smorse_occurences(std::map<std::string, std::string> word_code_map)
{
    std::map<std::string, unsigned int> oc_map;
    for (std::map<std::string, std::string>::iterator i = word_code_map.begin(); i != word_code_map.end(); i++)
    {
        if (oc_map.count(i->second) == 0ul)
        {
            oc_map[i->second] = 1;
        }
        else
        {
            oc_map[i->second]++;
        }
    }
    return oc_map;
}

std::vector<std::string> smorse::find_smorse_words(std::map<std::string, std::string> word_code_map, std::string code)
{
    std::vector<std::string> results;
    for (std::map<std::string, std::string>::iterator i = word_code_map.begin(); i != word_code_map.end(); i++)
    {
        if (i->second == code)
        {
            results.push_back(i->first);
        }
    }
    return results;
}

unsigned int smorse::max_in_a_row(std::string s, char c)
{
    unsigned int count = 0u;
    unsigned int max_count = 0u;
    for (std::string::iterator i = s.begin(); i != s.end(); i++)
    {
        if (*i.base() == c)
        {
            count++;
        }
        else
        {
            count = 0u;
        }
        if (count > max_count)
        {
            max_count = count;
        }
    }
    return max_count;
}

unsigned int smorse::count(std::string s, char c)
{
    unsigned int count = 0u;
    for (std::string::iterator i = s.begin(); i != s.end(); i++)
    {
        if (*i.base() == c)
        {
            count++;
        }
    }
    return count;
}

std::pair<unsigned int, unsigned int> smorse::count2(std::string s, char c1, char c2)
{
    std::pair<unsigned int, unsigned int> result(0u, 0u);
    for (std::string::iterator i = s.begin(); i != s.end(); i++)
    {
        if (*i.base() == c1)
        {
            result.first++;
        }
        if (*i.base() == c2)
        {
            result.second++;
        }
    }
    return result;
}

bool smorse::code_balanced(std::string code)
{
    std::pair<unsigned int, unsigned int> counts = smorse::count2(code, '.', '-');
    return counts.first == counts.second;
}

bool smorse::palindrome(std::string s)
{
    bool result = true;
    for (std::size_t i = 0ul; i < s.size() / 2; i++)
    {
        std::size_t j = s.size() - 1 - i;
        if (s[i] != s[j])
        {
            result = false;
            break;
        }
    }
    return result;
}

std::map<std::string, std::string> smorse::map_smorse_if_code(std::vector<std::string> words, bool (*keep_func)(std::string))
{
    std::map<std::string, std::string> cw_map;
    for (std::vector<std::string>::iterator wi = words.begin(); wi != words.end(); wi++)
    {
        std::string w(wi->data());
        if (cw_map.count(w) == 0ul)
        {
            std::string code = smorse::smorse(w);
            if (keep_func(code))
            {
                cw_map[w] = code;
            }
        }
    }
    return cw_map;
}

std::vector<std::string> smorse::all_pseudo_codes_of_length(std::size_t l)
{
    std::vector<std::string> pseudo_codes;
    std::size_t N = (std::size_t)std::pow(2ul, l);
    for (std::size_t n = 0ul; n < N; n++)
    {
        std::string p_code = "";
        for (std::size_t i = 0ul; i < l; i++)
        {
            if ((n >> i & 1ul) != 0ul)
            {
                p_code.insert(i, 1, '-');
            }
            else
            {
                p_code.insert(i, 1, '.');
            }
        }
        pseudo_codes.push_back(p_code);
    }
    return pseudo_codes;
}

std::vector<std::string> smorse::all_actual_codes_of_length(std::size_t l)
{
    std::vector<std::string> codes;
    std::map<char, std::string> coding = smorse::coding;
    std::map<std::size_t, char> num_char_map;
    std::size_t minl = 0xffUL, maxl = 0ul;
    std::size_t n = 0ul;
    for (std::map<char, std::string>::iterator ci = coding.begin(); ci != coding.end(); ci++)
    {
        num_char_map[n] = ci->first;
        n++;
        std::size_t length = ci->second.size();
        if (length < minl)
            minl = length;
        if (length > maxl)
            maxl = length;
    }
    std::size_t coding_size = coding.size();
    std::size_t maxc = (coding_size + minl - 1) / minl, minc = (coding_size - maxl + 1) / maxl > 0l ? (coding_size - maxl + 1) / maxl : 0ul;
    for (std::size_t ccount = minc; ccount < maxc; ccount++)
    {
        std::string word = "";
        word.resize(ccount, num_char_map[0ul]);
        for (std::size_t counter = 0ul; counter < ccount * coding_size; counter++)
        {
            std::size_t remainder = counter;
            for (std::size_t c = 0ul; c < ccount; c++)
            {
                std::size_t cv = remainder % coding_size;
                remainder -= cv;
                remainder = remainder / coding_size;
                word[c] = num_char_map[cv];
            }
            std::string code = smorse::smorse(word);
            if (code.size() == l)
                codes.push_back(code);
        }
    }
    return codes;
}

std::vector<std::string> smorse::unused_codes_in_map(std::map<std::string, std::string> word_code_map, std::vector<std::string> codes)
{
    std::vector<std::string> unused = codes, unused_only;
    unused_only.reserve(codes.size());
    for (std::map<std::string, std::string>::iterator wci = word_code_map.begin(); wci != word_code_map.end(); wci++)
    {
        for (std::vector<std::string>::iterator uci = unused.begin(); uci != unused.end(); uci++)
        {
            if (wci->second.size() >= uci->size())
            {
                if (wci->second.find(*uci.base()) != std::string::npos)
                {
                    uci->erase();
                }
            }
        }
    }
    for (std::vector<std::string>::iterator uci = unused.begin(); uci != unused.end(); uci++)
    {
        if (!uci->empty())
            unused_only.push_back(*uci.base());
    }
    return unused_only;
}
