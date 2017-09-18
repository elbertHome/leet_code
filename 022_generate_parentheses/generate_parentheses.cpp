//============================================================================
// Name        : 22. Generate Parentheses
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 22. Generate Parentheses
// Accepted Date: 2017/09/18
/*****************************************************************************
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]

 ******************************************************************************/
//============================================================================
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> rslts;
        string rslt;

        detail(rslts, rslt, n, 0);
        return rslts;
    }

    void detail(vector<string> &rslts, string rslt, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            rslts.push_back(rslt);
            return;
        }

        if (left > 0)
            detail(rslts, rslt + "(", left -1, right + 1);

        if (right > 0)
            detail(rslts, rslt + ")", left, right - 1);
    }
};

int main(int argc, char **argv)
{
    int num;
    cout << "input the numbert to generate Parentheses:" << endl;
    cin >> num;
    vector<string> rslts = Solution().generateParenthesis(num);

    for (auto rslt : rslts)
    {
        cout << rslt << endl;
    }

    return EXIT_SUCCESS;
}

