//============================================================================
// Name        : 28. Implement strStr()
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 28. Implement strStr()
// Accepted Date: 2017/10/02
/*****************************************************************************
 Implement strStr().
 Returns the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.
 ******************************************************************************/
//============================================================================
#include <string>
#include <iostream>

using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        size_t lens = needle.size();
        if (haystack.size() < lens)
            return -1;

        for (auto iter_s = haystack.cbegin(); iter_s + lens - 1 < haystack.cend(); ++iter_s)
        {
            if (string(iter_s, iter_s + lens) == needle)
                return distance(haystack.cbegin(), iter_s);
        }

        return -1;
    }
};

int main(int argc, char **argv)
{
    string haystack, needle;

    cout << "print the haystack and needle" << endl;
    cin >> haystack >> needle;
    cout << "result is " << Solution().strStr(haystack, needle) << endl;

    return EXIT_SUCCESS;
}

