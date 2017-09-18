//============================================================================
// Name        : 23. Merge k Sorted Lists
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 23. Merge k Sorted Lists
// Accepted Date: 2017/09/18
/*****************************************************************************
 Merge k sorted linked lists and return it as one sorted list.
 Analyze and describe its complexity.

 ******************************************************************************/
//============================================================================
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        return detail(lists.cbegin(), lists.cend());
    }

    ListNode* detail(vector<ListNode*>::const_iterator s, vector<ListNode*>::const_iterator e)
    {
        if ( s >= e)
        {
            return NULL;
        }
        else if (e - s == 1)
        {
            return *s;
        }
        else
        {
            int offset = (e - s) / 2;
            return mergeTwoLists(detail(s, s + offset), detail(s + offset, e));
        }
    }

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
    int k, num;
    vector<ListNode*> lists;
    ListNode *p_1 = NULL;
    ListNode *p_2 = NULL;
    ListNode *head = NULL;

    cout << "Enter the list number to merge" << endl;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin.clear();
        head = new ListNode(0);
        p_2 = head;
        cout << "import No." << i << " sorted list" << endl;
        while (cin >> num)
        {
            p_1 = new ListNode(num);
            p_2->next = p_1;
            p_2 = p_1;
        }
        lists.push_back(head->next);
        delete head;
    }

    p_1 = Solution().mergeKLists(lists);

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

    return EXIT_SUCCESS;
}
