//============================================================================
// Name        : 14. Longest Common Prefix
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 14. Longest Common Prefix
// Accepted Date: 2017/09/06
/*****************************************************************************
 Write a function to find the longest common prefix string amongst an array of strings.
 ******************************************************************************/
//============================================================================
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() < 1)
            return "";

        size_t common_prefix_length = 0;
        string first = strs.front();
        while (true)
        {
            for (string str : strs)
            {
                if (str.size() <= common_prefix_length || first[common_prefix_length] != str[common_prefix_length])
                {
                    goto END;
                }
            }
            ++common_prefix_length;
        }
        END:

        return first.substr(0, common_prefix_length);
    }
};

int main(int argc, char **argv)
{
    vector<string> strs;
    string str;
    cout << "Input strings to find common prefix:" << endl;

    while (getline(cin, str))
    {
        strs.push_back(str);
    }
    cout << "common prefix is: " << Solution().longestCommonPrefix(strs) << endl;

    return EXIT_SUCCESS;
}
