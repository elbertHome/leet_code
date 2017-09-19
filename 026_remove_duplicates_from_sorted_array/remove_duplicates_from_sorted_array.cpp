//============================================================================
// Name        : 26. Remove Duplicates from Sorted Array
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 26. Remove Duplicates from Sorted Array
// Accepted Date: 2017/09/19
/*****************************************************************************
 Given a sorted array,
 remove the duplicates in place such that each element appear only once and return the new length.
 Do not allocate extra space for another array,
 you must do this in place with constant memory.

 For example,
 Given input array nums = [1,1,2],
 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 It doesn't matter what you leave beyond the new length.
 ******************************************************************************/
//============================================================================
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() > 1)
        {
            int cur_number;
            vector<int>::iterator it1 = nums.begin();
            vector<int>::iterator it2 = nums.begin() + 1;
            cur_number = *it1;
            while (it2 != nums.end())
            {
                if (*it2 != cur_number)
                {
                    cur_number = *it2;
                    *(++it1) = cur_number;
                }
                ++it2;
            }

            nums.resize(distance(nums.begin(), it1 + 1));
        }
        return nums.size();
    }
};

int main(int argc, char **argv)
{
    vector<int> nums;
    int num;
    cout << "Enter the Sorted Array" << endl;

    while (cin >> num)
    {
        nums.push_back(num);
    }
    Solution().removeDuplicates(nums);

    cout << "Result is: " << endl;
    for (auto rcd : nums)
    {
        cout << rcd << endl;
    }

    return EXIT_SUCCESS;
}
