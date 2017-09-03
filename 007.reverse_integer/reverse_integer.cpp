//============================================================================
// Name        : 7. Reverse Integer
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 7. Reverse Integer
// Accepted Date: 2017/09/02
/*****************************************************************************
 Reverse digits of an integer.

 Example1: x = 123, return 321
 Example2: x = -123, return -321

 Note:
 The input is assumed to be a 32-bit signed integer.
 Your function should return 0 when the reversed integer overflows.
 ******************************************************************************/
//============================================================================

#include <limits.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x)
    {
       long long result = 0;
       while (x)
       {
           result = result * 10 + x%10;
           x = x/10;
       }
       return (result > INT_MAX || result < INT_MIN) ? 0 : result;
    }
};

int main(int argc, char **argv)
{
    int num;

    cout << "input the integer number to reverse" << endl;
    cin >> num;
    cout << Solution().reverse(num) << endl;

    return EXIT_SUCCESS;
}
