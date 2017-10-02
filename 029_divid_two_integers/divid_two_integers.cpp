//============================================================================
// Name        : 29. Divide Two Integers
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 29. Divide Two Integers
// Accepted Date: 2017/10/02
/*****************************************************************************
 Divide two integers without using multiplication, division and mod operator.

 If it is overflow, return MAX_INT.
 ******************************************************************************/
//============================================================================
#include <string>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 0)
            return INT_MAX;

        long long div_1 = dividend;
        long long div_2 = divisor;

        bool isNeg = false;
        if (div_1 < 0)
        {
            div_1 = abs(div_1);
            isNeg = !isNeg;
        }
        if (div_2 < 0)
        {
            div_2 = abs(div_2);
            isNeg = !isNeg;
        }
        long long result = abs(detail(div_1, div_2));
        result = isNeg ? -result : result;
        if ((result < INT_MIN) || (result > INT_MAX))
            return INT_MAX;
        return result;
    }

    long long detail(long long dividend, long long divisor)
    {
        if (dividend < divisor)
            return 0;
        int multiple;
        for (multiple = 1; dividend >= (divisor << multiple); ++multiple);
        if (multiple > 1)
            return (2 << (multiple - 2)) + detail(dividend - (divisor << (multiple - 1)), divisor);
        else
            return 1;
    }
};

int main(int argc, char **argv)
{
    int dividend, divisor;

    cout << "input the dividend and divisor" << endl;
    cin >> dividend >> divisor;
    cout << "result is " << Solution().divide(dividend, divisor) << endl;

    return EXIT_SUCCESS;
}

