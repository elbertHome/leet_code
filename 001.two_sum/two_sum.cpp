//============================================================================
// Name        : two_sum.cpp
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 1. Tow Sum
/*****************************************************************************
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
******************************************************************************/
//============================================================================

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return vector<int> {static_cast<int>(i), static_cast<int>(j)};
                }
            }
        }
        return vector<int>();
    }
};


int main(int argc, char **argv)
{
    vector<int> nums {2, 7, 11, 16};
    int target;
    Solution sol;
    cout << "input the target" << endl;
    cin >> target;
    vector<int> result = sol.twoSum(nums, target);
    if (result.size() == 0)
    {
        cout << "can't match" << endl;
    }
    else
    {
        cout << result[0] << ", " << result[1] << endl;
    }
    return EXIT_SUCCESS;
}
