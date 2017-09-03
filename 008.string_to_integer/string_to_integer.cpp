//============================================================================
// Name        : 8. String To Integer
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 8. String to Integer
// Accepted Date: 2017/09/03
/*****************************************************************************
 Implement atoi to convert a string to an integer.

 Hint: Carefully consider all possible input cases.
 If you want a challenge, please do not see below and ask yourself what are the possible input cases.

 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 You are responsible to gather all the input requirements up front.
 ******************************************************************************/
//============================================================================
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        bool isStart = false;
        bool isMinus = false;
        long long result = 0;
        for (auto iter = str.cbegin(); iter != str.cend(); ++iter)
        {
            if (*iter >= '0' && *iter <= '9')
            {
                if (!isStart)
                {
                    isStart = true;
                }
                result = result * 10 + (*iter - '0');

                if (isMinus && -result <= INT_MIN)
                {
                    return INT_MIN;
                }
                if (!isMinus && result >= INT_MAX)
                {
                    return INT_MAX;
                }
            }
            else if (*iter == '+' || *iter == '-')
            {
                if (!isStart)
                {
                    isStart = true;
                    isMinus = *iter == '-' ? true : false;
                }
                else
                {
                    break;
                }

            }
            else if (*iter == ' ')
            {
                if (isStart)
                    break;
                else
                    continue;
            }
            else
            {
                break;
            }
        }

        result = isMinus ? -result : result;
        return result;
    }
};

int main(int argc, char **argv)
{
    string str;
    cout << "please input the str to convert" << endl;
    std::getline(std::cin, str);
    cout << Solution().myAtoi(str) << endl;
    return EXIT_SUCCESS;
}
