//============================================================================
// Name        : 12. Integer to Roman
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 12. Integer to Roman
// Accepted Date: 2017/09/05
/*****************************************************************************
 Given an integer, convert it to a roman numeral.
 Input is guaranteed to be within the range from 1 to 3999.

 ******************************************************************************/
//============================================================================
#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        if (num < 1 || num > 3999)
            return "";

        char mapping[][3] =
                {
                        { 'I', 'V', 'X' },
                        { 'X', 'L', 'C' },
                        { 'C', 'D', 'M' },
                        { 'M', '\0', '\0' }

                };
        int j = 0;
        string str;
        for (int i = 0; num > 0; num /= 10, ++i)
        {
            j = num % 10;
            switch (j)
            {
                case 1:
                    case 2:
                    case 3:
                    str.insert(str.begin(), j, mapping[i][0]);
                    break;
                case 4:
                    str.insert(str.begin(),
                    { mapping[i][0], mapping[i][1] });
                    break;
                case 5:
                    str.insert(str.begin(), mapping[i][1]);
                    break;
                case 6:
                    case 7:
                    case 8:
                    str.insert(str.begin(), j - 5, mapping[i][0]);
                    str.insert(str.begin(), mapping[i][1]);
                    break;
                case 9:
                    str.insert(str.begin(),
                    { mapping[i][0], mapping[i][2] });
                    break;
            }
        }
        return str;
    }
};

int main(int argc, char **argv)
{
    int num = 0;
    cout << "input the integer to convert to roman: " << endl;
    cin >> num;
    cout << "roman number is: " << Solution().intToRoman(num) << endl;
    return EXIT_SUCCESS;
}
