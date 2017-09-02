//============================================================================
// Name        : median_of_two_sorted_arrays.cpp
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 4. Median of Two Sorted Arrays
/*****************************************************************************
 There are two sorted arrays nums1 and nums2 of size m and n respectively.
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 Example 1:
 nums1 = [1, 3]
 nums2 = [2]
 The median is 2.0

 Example 2:
 nums1 = [1, 2]
 nums2 = [3, 4]
 The median is (2 + 3)/2 = 2.5
 ******************************************************************************/
//============================================================================
#include <cstdlib>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int total_length = nums1.size() + nums2.size();
        if (total_length == 0)
        {
            return 0;
        }

        int total_consume = (total_length + 1) / 2 - 1;
        vector<int>::const_iterator iter_1 = nums1.begin();
        vector<int>::const_iterator iter_2 = nums2.begin();

        detail(iter_1, nums1.cend(), iter_2, nums2.cend(), total_consume);

        vector<int> vec;
        while ((iter_1 != nums1.cend() || iter_2 != nums2.cend()) && vec.size() <= 2)
        {
            if (iter_1 == nums1.cend())
            {
                vec.push_back(*iter_2++);
            }
            else if (iter_2 == nums2.cend())
            {
                vec.push_back(*iter_1++);
            }
            else
            {
                if (*iter_1 < *iter_2)
                {
                    vec.push_back(*iter_1++);
                }
                else
                {
                    vec.push_back(*iter_2++);
                }
            }
        }

        if (total_length % 2 == 0)
        {
            return (vec[0] + vec[1]) / 2.0;
        }
        return vec[0];
    }

    void detail(vector<int>::const_iterator &start_1, vector<int>::const_iterator end_1,
            vector<int>::const_iterator &start_2, vector<int>::const_iterator end_2,
            int left)
    {
        // recurse end when left consume is 0
        if (left <= 0)
            return;

        int length_1 = end_1 - start_1;
        int length_2 = end_2 - start_2;
        // consme num2 with left consume when num1 is empty and return
        if (length_1 <= 0)
        {
            start_2 += left;
            return;
        }
        // consme num1 with left consume when num2 is empty and return
        if (length_2 <= 0)
        {
            start_1 += left;
            return;
        }

        int consume_1 = (length_1 + 1) / 2 - 1;
        if (consume_1 <= 0)
        {
            consume_1 = 1;
        }
        else if (consume_1 > left)
        {
            consume_1 = left;
        }
        int consume_2 = left - consume_1 <= 0 ? 1 : left - consume_1;

        // consmue num1 when compare element1 < compare element2
        if (*(start_1 + consume_1 - 1) < *(start_2 + consume_2 - 1))
        {
            start_1 += consume_1;
            left -= consume_1;
        }
        // consmue num2 when compare element1 > compare element2
        else if (*(start_1 + consume_1 - 1) > *(start_2 + consume_2 - 1))
        {
            start_2 += consume_2;
            left -= consume_2;
        }
        // compare next element when compare element1 == compare element2
        else
        {
            if (start_1 + consume_1 == end_1)
            {
                start_1 += consume_1;
                left -= consume_1;
            }
            else if (start_2 + consume_2 == end_2)
            {
                start_2 += consume_2;
                left -= consume_2;
            }
            else
            {
                if (*(start_1 + consume_1) < *(start_2 + consume_2))
                {
                    start_1 += consume_1;
                    left -= consume_1;
                }
                else
                {
                    start_2 += consume_2;
                    left -= consume_2;
                }
            }

        }
        detail(start_1, end_1, start_2, end_2, left);
    }
};

int main(int argc, char** argv)
{
    vector<int> nums1
    { 4 };

    // vector<int> nums2 { 16, 19, 55, 79, 80, 81, 82};
    vector<int> nums2
    { 1, 3, 4 };

    cout << "median number is " << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    return EXIT_SUCCESS;
}
