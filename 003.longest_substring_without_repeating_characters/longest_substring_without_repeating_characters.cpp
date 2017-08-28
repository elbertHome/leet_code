//============================================================================
// Name        : longest_substring_without_repeating_characters
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 3. Longest Substring Without Repeating Characters
/*****************************************************************************
 Given a string, find the length of the longest substring without repeating characters.
 Examples:
 Given "abcabcbb", the answer is "abc", which the length is 3.
 Given "bbbbb", the answer is "b", with the length of 1.
 Given "pwwkew", the answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 ******************************************************************************/
//============================================================================
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <iostream>

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string longest;
        unordered_map<char, size_t> char_map;
        size_t max_length = 0;
        size_t length = 1;
        size_t i = 0;
        size_t j = 0;


        while (i < s.size())
        {
            length = 1;
            char_map.clear();
            char_map[s[i]] = i;

            for(j = i + 1; j < s.size(); ++j)
            {
                if (char_map.count(s[j]) > 0)
                {
                    break;
                }
                else
                {
                    char_map[s[j]] = j;
                    ++length;
                }
            }

            max_length = length > max_length ? length : max_length;
            if (j < s.size())
            {
                i = char_map[s[j]] + 1;
                if (s.size() - i <= max_length)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return max_length;
    }
};

int main(int argc, char **argv)
{
    string str{};
    cout << "input string to caculte longest substring:" << endl;
    cin >> str;

    cout << Solution().lengthOfLongestSubstring(str) << endl;
    return EXIT_SUCCESS;
}
