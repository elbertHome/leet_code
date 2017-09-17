//============================================================================
// Name        : 20. Valid Parentheses
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 20. Valid Parentheses
// Accepted Date: 2017/09/17
/*****************************************************************************
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 determine if the input string is valid.

 The brackets must close in the correct order,
 "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

 ******************************************************************************/
//============================================================================
#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;

        for (char ch : s)
        {
            switch (ch)
            {
                case '(':
                case '[':
                case '{':
                    stk.push(ch);
                    break;
                case ')':
                    if (!stk.empty() && stk.top() == '(')
                        stk.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (!stk.empty() && stk.top() == '[')
                        stk.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (!stk.empty() && stk.top() == '{')
                        stk.pop();
                    else
                        return false;
                    break;
                default:
                    return false;
            }
        }
        return stk.empty();
    }
};

int main(int argc, char **argv)
{
    string str;

    cout << "enter the string: " << endl;
    cin >> str;
    cout << Solution().isValid(str) << endl;

    return EXIT_SUCCESS;
}

