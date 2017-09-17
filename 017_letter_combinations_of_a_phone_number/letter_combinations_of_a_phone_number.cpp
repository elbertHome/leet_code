//============================================================================
// Name        : 17. Letter Combinations of a Phone Number
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 17. Letter Combinations of a Phone Number
// Accepted Date: 2017/09/17
/*****************************************************************************
 Given a digit string, return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons) is given below.

 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.


 ******************************************************************************/
//============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> results;
        string str;
        map<char, string> num_map =
        {
        { '0', " " },
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" } };

        for (const auto &num : digits)
        {
            if (num < '0' || num > '9' || num == '1')
                continue;
            str = num_map[num];

            if (results.size() > 0)
            {
                int results_size = results.size();

                for (int i = 0; i < results_size; ++i)
                {
                    for (size_t j = 1; j < str.size(); ++j)
                    {
                        results.push_back(results[i] + str[j]);
                    }
                    results[i].push_back(str[0]);
                }
            }
            else
            {
                for (const auto &alph : str)
                    results.push_back(string(&alph, 1));
            }
        }

        return results;
    }
};

int main(int argc, char **argv)
{
    string digits;
    cout << "input the digit string to conver:" << endl;
    cin >> digits;

    cout << "results is : " << endl;

    for (auto rslt : Solution().letterCombinations(digits))
    {
        cout << rslt << endl;
    }

    return EXIT_SUCCESS;
}
