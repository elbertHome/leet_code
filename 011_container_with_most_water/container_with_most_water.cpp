//============================================================================
// Name        : 11. Container With Most Water
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 11. Container With Most Water
// Accepted Date: 2017/09/05
/*****************************************************************************
 Given n non-negative integers a1, a2, ..., an,
 where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 Find two lines, which together with x-axis forms a container,
 such that the container contains the most water.

 Note: You may not slant the container and n is at least 2.
 ******************************************************************************/
//============================================================================

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        if (height.size() < 1)
            return 0;

        int max_water = 0;
        int area;

        auto iter1 = height.cbegin();
        auto iter2 = height.cend() - 1;

        while (iter1 < iter2)
        {
            area = (iter2 - iter1) * (*iter1 < *iter2 ? *iter1++ : *iter2--);
            max_water = max_water < area ? area : max_water;
        }

        return max_water;
    }
};

int main(int argc, char **argv)
{
    int num;
    vector<int> vec;
    cout << "Input heights" << endl;
    while (cin >> num)
    {
        vec.push_back(num);
    }

    cout << "Most water is " << Solution().maxArea(vec) << endl;
    return EXIT_SUCCESS;
}
