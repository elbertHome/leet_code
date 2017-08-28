//============================================================================
// Name        : add_two_numbers.cpp
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 2. Add Two Numbers
/*****************************************************************************
 You are given two non-empty linked lists representing two non-negative integers.
 The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 ******************************************************************************/
//============================================================================


#include <stdio.h>
#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :
            val(x), next(NULL)
    {
    }
};


class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *res = NULL;
        ListNode *pCur = NULL;
        ListNode *pre = NULL;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        unsigned carry = 0;

        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        else
        {
            res = new ListNode(0);
            pCur = res;
            while (p1 != NULL && p2 != NULL)
            {
                pre = pCur;
                pCur = new ListNode((p1->val + p2->val + carry) % 10);
                carry = (p1->val + p2->val + carry) / 10;
                pre->next = pCur;
                p1 = p1->next;
                p2 = p2->next;
            }

            while (p1 != NULL)
            {
                pre = pCur;
                pCur = new ListNode((p1->val + carry) % 10);
                carry = (p1->val + carry) / 10;
                pre->next = pCur;
                p1 = p1->next;
            }

            while (p2 != NULL)
            {
                pre = pCur;
                pCur = new ListNode((p2->val + carry) % 10);
                carry = (p2->val + carry) / 10;
                pre->next = pCur;
                p2 = p2->next;
            }

            if (carry > 0)
            {
                pre = pCur;
                pCur = new ListNode(carry);
                carry = 0;
                pre->next = pCur;
            }

            pre = res;
            res = res -> next;
            delete pre;
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    ListNode l1(0), l2(0);
    ListNode *cur = NULL;
    ListNode *res = NULL;
    ListNode *pre = NULL;

    // setting l1
    cur = &l1;
    cur->val = 3;
    ListNode tmp_1(8);
    cur->next = &tmp_1;
    cur = cur->next;
    ListNode tmp_2(9);
    cur->next = &tmp_2;
    cur = cur->next;

    // setting l2
    cur = &l2;
    cur->val = 0;
    ListNode tmp_3(6);
    cur->next = &tmp_3;
    cur = cur->next;
    ListNode tmp_4(0);
    cur->next = &tmp_4;
    cur = cur->next;
    ListNode tmp_5(9);
    cur->next = &tmp_5;
    cur = cur->next;

    res = Solution().addTwoNumbers(&l1, &l2);

    cur = res;
    if (cur != NULL)
    {
        std::cout << cur->val;
        pre = cur;
        cur = cur->next;
        delete pre;
        while (cur != NULL)
        {
            std::cout << "->" << cur->val;
            pre = cur;
            cur = cur->next;
            delete pre;
        }
        std::cout << std::endl;
    }
}
