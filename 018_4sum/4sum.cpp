//============================================================================
// Name        : 18. 4SUM
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 18. 4SUM
// Accepted Date: 2017/09/17
/*****************************************************************************
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 Find all unique quadruplets in the array which gives the sum of target.

 Note: The solution set must not contain duplicate quadruplets.
 For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

 A solution set is:
 [
 [-1,  0, 0, 1],
 [-2, -1, 1, 2],
 [-2,  0, 0, 2]
 ]

 ******************************************************************************/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {

        set<vector<int>> results;
        vector<int>::const_iterator iter_1, iter_2, iter_3, iter_4;

        sort(nums.begin(), nums.end());
        iter_1 = nums.cbegin();
        while (iter_1 != nums.cend())
        {
            iter_2 = iter_1 + 1;
            while(iter_2 != nums.cend())
            {
                iter_3 = iter_2 + 1;
                iter_4 = nums.cend() -1;

                while (iter_3 < iter_4)
                {
                    if (*iter_1 + *iter_2 + *iter_3 + *iter_4 == target)
                    {
                        results.insert(vector<int> {*iter_1, *iter_2, *iter_3, *iter_4});
                        ++iter_3;
                        --iter_4;
                    }
                    else if (*iter_1 + *iter_2 + *iter_3 + *iter_4 < target)
                    {
                        ++iter_3;
                    }
                    else
                    {
                        --iter_4;
                    }
                }
                ++iter_2;
            }
            ++iter_1;
        }

        return vector<vector<int>>(results.cbegin(), results.cend());
    }
};

int main(int argc, char **argv)
{
    int num, target;
    vector<int> nums;
    cout << "input target: " << endl;
    cin >> target;
    cout << "input numbers: " << endl;
    cin.clear();
    while (cin >> num)
    {
        nums.push_back(num);
    }

    vector<vector<int>> rslts = Solution().fourSum(nums, target);

    for (auto rslt : rslts)
    {
        cout << " [ ";
        cout << rslt[0] << ", ";
        cout << rslt[1] << ", ";
        cout << rslt[2] << ", ";
        cout << rslt[3] << " ] " << endl;
    }

    return EXIT_SUCCESS;
}
