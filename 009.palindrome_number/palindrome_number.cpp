//============================================================================
// Name        : 9. Palindrome Number
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 9. Palindrome Number
// Accepted Date: 2017/09/04
/*****************************************************************************
 Determine whether an integer is a palindrome. Do this without extra space.
 ******************************************************************************/
//============================================================================
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        int origin = x;
        long long reverse = 0;

        while (x > 0)
        {
            reverse = reverse * 10 + x%10;
            x /= 10;
            if (reverse > INT_MAX || reverse < INT_MIN)
                return false;
        }
        return reverse == origin;
    }
};

int main(int argc, char **argv)
{
    int num;

    cout << "input the numbet to judge: " << endl;
    cin >> num;
    cout << Solution().isPalindrome(num) << endl;
    return EXIT_SUCCESS;
}
