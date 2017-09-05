//============================================================================
// Name        : 13. Roman To Integer
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 13. Roman To Integer
// Accepted Date: 2017/09/05
/*****************************************************************************
 Given a roman numeral, convert it to an integer.

 Input is guaranteed to be within the range from 1 to 3999.
 ******************************************************************************/
//============================================================================
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        int adding;
        map<char, int> mapping =
                {
                        { 'M', 1000 },
                        { 'D', 500 },
                        { 'C', 100 },
                        { 'L', 50 },
                        { 'X', 10 },
                        { 'V', 5 },
                        { 'I', 1 }
                };

        for (auto iter = s.cbegin(); iter != s.cend(); ++iter)
        {
            adding = mapping[*iter];
            if (iter + 1 != s.cend() && adding < mapping[*(iter + 1)])
            {
                result -= adding;
            }
            else
            {
                result += adding;
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    string str;

    cout << "input the roman to convert into integer" << endl;
    getline(cin, str);
    cout << "result is : " << Solution().romanToInt(str) << endl;
    return EXIT_SUCCESS;
}

