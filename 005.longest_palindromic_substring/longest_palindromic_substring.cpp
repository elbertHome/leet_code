//============================================================================
// Name        : 5. Longest Palindromic Substring
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 5. Longest Palindromic Substring
// Accepted Date: 2017/09/02
/*****************************************************************************
 Given a string s, find the longest palindromic substring in s.
 You may assume that the maximum length of s is 1000.

 Example:
 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.

 Example:
 Input: "cbbd"
 Output: "bb"
 ******************************************************************************/
//============================================================================
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string result;

        return result;
    }
};

int main(int argc, char **argv)
{
    string input;

    cout << "enter the string to be caculate:" << endl;
    cin >> input;
    cout << "longest palindromic substring is " << Solution().longestPalindrome(input) << endl;
    return EXIT_SUCCESS;
}
