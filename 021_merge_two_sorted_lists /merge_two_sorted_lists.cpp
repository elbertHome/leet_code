//============================================================================
// Name        : 21. Merge Two Sorted Lists
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 21. Merge Two Sorted Lists
// Accepted Date: 2017/09/17
/*****************************************************************************
 Merge two sorted linked lists and return it as a new list.
 The new list should be made by splicing together the nodes of the first two lists.

 ******************************************************************************/
//============================================================================
#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode h = ListNode(0);
        ListNode *p = &h;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }

        p->next = NULL;
        if (l1 != NULL)
            p->next = l1;
        else
            p->next = l2;

        return h.next;
    }
};

int main(int argc, char **argv)
{
    int num;
    ListNode *h_1 = new ListNode(0);
    ListNode *h_2 = new ListNode(0);
    ListNode *p_1 = NULL;
    ListNode *p_2 = h_1;

    cout << "import 1st sorted list" << endl;
    while (cin >> num)
    {
        p_1 = new ListNode(num);
        p_2->next = p_1;
        p_2 = p_1;
    }
    cin.clear();

    cout << "import 2nd sorted list" << endl;
    p_2 = h_2;
    while (cin >> num)
    {
        p_1 = new ListNode(num);
        p_2->next = p_1;
        p_2 = p_1;
    }

    p_1 = Solution().mergeTwoLists(h_1->next, h_2->next);

    if (p_1 != NULL)
    {
        cout << p_1->val;
        p_2 = p_1;
        p_1 = p_1->next;
        delete p_2;
        while (p_1 != NULL)
        {
            cout << " -> " << p_1->val;
            p_2 = p_1;
            p_1 = p_1->next;
            delete p_2;
        }
        cout << endl;
    }

    delete h_1;
    delete h_2;
    return EXIT_SUCCESS;
}

