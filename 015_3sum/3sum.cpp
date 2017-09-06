//============================================================================
// Name        : 15. 3Sum
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 15. 3Sum
// Accepted Date: 2017/09/06
/*****************************************************************************
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 Find all unique triplets in the array which gives the sum of zero.

 Note: The solution set must not contain duplicate triplets.
 For example, given array S = [-1, 0, 1, 2, -1, -4],

 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 ******************************************************************************/
//============================================================================
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> rslts;

        if (nums.size() < 3)
            return rslts;

        sort(nums.begin(), nums.end());
        vector<int>::const_iterator iter_1 = nums.cbegin();
        vector<int>::const_iterator iter_2 = nums.cbegin();
        vector<int> rslt(3);

        while (iter_1 != nums.cend())
        {
            rslt[0] = *iter_1;
            iter_2 = iter_1 + 1;
            while (iter_2 != nums.cend())
            {
                rslt[1] = *iter_2;

                 if (binary_search(iter_2 + 1, nums.cend(), 0 - *iter_1 - *iter_2))
                 {
                     rslt[2] = 0 - *iter_1 - *iter_2;
                     rslts.push_back(rslt);
                 }

                do
                {
                    ++iter_2;
                } while (iter_2 != nums.cend() && rslt[1] == *iter_2);
            }

            do
            {
                ++iter_1;
            } while (iter_1 != nums.cend() && rslt[0] == *iter_1);
        }
        return rslts;
    }
};

int main(int argc, char **argv)
{
    int num;
    vector<int> nums;
    cout << "input numbers: " << endl;
    while (cin >> num)
    {
        nums.push_back(num);
    }

    vector<vector<int>> rslts = Solution().threeSum(nums);

    for (auto rslt : rslts)
    {
        cout << " [ ";
        cout << rslt[0] << ", ";
        cout << rslt[1] << ", ";
        cout << rslt[2] << " ] " << endl;
    }

    return EXIT_SUCCESS;
}
