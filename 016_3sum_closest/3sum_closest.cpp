//============================================================================
// Name        : 16. 3Sum Closest
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 16. 3Sum Closest
// Accepted Date: 2017/09/06
/*****************************************************************************
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
 target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 For example, given array S = {-1 2 1 -4}, and target = 1.

 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 ******************************************************************************/
//============================================================================
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        if (nums.size() < 3)
            return 0;

        int diff = INT_MAX;
        int sub_target;

        sort(nums.begin(), nums.end());
        vector<int>::const_iterator iter_1 = nums.cbegin();
        vector<int>::const_iterator iter_front;
        vector<int>::const_iterator iter_back;
        int pre_1, pre_2, pre_3;

        while (iter_1 != nums.cend())
        {
            pre_1 = *iter_1;
            sub_target = target - *iter_1;

            iter_front = iter_1 + 1;
            iter_back = nums.cend() - 1;

            while (iter_front < iter_back)
            {
                pre_2 = *iter_front;
                pre_3 = *iter_back;
                if (*iter_front + *iter_back < sub_target)
                {
                    do
                    {
                        ++iter_front;
                    } while (iter_front < iter_back && *iter_front == pre_2);
                }
                else if (*iter_front + *iter_back > sub_target)
                {
                    do
                    {
                        --iter_back;
                    } while (iter_front < iter_back && *iter_back == pre_3);
                }
                else
                    return target;
                diff = abs(diff) <= abs(target - (pre_1 + pre_2 + pre_3)) ? diff : target - (pre_1 + pre_2 + pre_3);
            }

            do
            {
                ++iter_1;
            } while (iter_1 != nums.cend() && pre_1 == *iter_1);
        }
        return target - diff;
    }
};

int main(int argc, char **argv)
{
    int num, target;
    vector<int> nums;
    cout << "input numbers: " << endl;
    while (cin >> num)
    {
        nums.push_back(num);
    }
    cin.clear();
    cout << "input target: " << endl;
    cin >> target;
    cout << "result is: " << Solution().threeSumClosest(nums, target) << endl;

    return EXIT_SUCCESS;
}
