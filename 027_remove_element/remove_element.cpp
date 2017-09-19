//============================================================================
// Name        : 27. Remove Element
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 27. Remove Element
// Accepted Date: 2017/09/19
/*****************************************************************************
 Given an array and a value, remove all instances of that value in place and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Example:
 Given input array nums = [3,2,2,3], val = 3
 Your function should return length = 2, with the first two elements of nums being 2.
 ******************************************************************************/
//============================================================================
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {

        if (nums.size() > 0)
        {
            vector<int>::iterator head = nums.begin();
            vector<int>::iterator tail = nums.end() - 1;

            while (head < tail)
            {
                while (*head != val && head < tail)
                {
                    ++head;
                }

                while (*tail == val && head < tail)
                {
                    --tail;
                }

                if (head < tail)
                {
                    *head = *tail;
                    ++head;
                    --tail;
                }
            }
            if (head == tail && *head != val)
            {
                ++head;
            }
            nums.resize(distance(nums.begin(),  head));
        }
        return nums.size();
    }
};

int main(int argc, char **argv)
{
    vector<int> nums;
    int num, val;
    cout << "Enter the Array" << endl;

    while (cin >> num)
    {
        nums.push_back(num);
    }
    cin.clear();
    cout << "Enter the val" << endl;
    cin >> val;

    Solution().removeElement(nums, val);
    cout << "Result is: " << endl;
    for (auto rcd : nums)
    {
        cout << rcd << endl;
    }

    return EXIT_SUCCESS;
}
