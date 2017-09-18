//============================================================================
// Name        : 24. Swap Nodes in Pairs
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 24. Swap Nodes in Pairs
// Accepted Date: 2017/09/18
/*****************************************************************************
 Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

 ******************************************************************************/
//============================================================================
#include <iostream>
#include <string>
#include <vector>
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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode **pp = &head;
        ListNode *p1, *p2;

        while ( (p1 = *pp) && (p2 = p1->next))
        {
            p1->next = p2->next;
            p2->next = p1;
            *pp = p2;
            pp = &(p1->next);
        }
        return head;
    }
};

int main(int argc, char **argv)
{
    int k, num;
    vector<ListNode*> lists;
    ListNode *p_1 = NULL;
    ListNode *p_2 = NULL;
    ListNode *head = NULL;

//    cout << "Enter the list number to merge" << endl;
//    cin >> k;

    k = 1;
    for (int i = 0; i < k; i++)
    {
        cin.clear();
        head = new ListNode(0);
        p_2 = head;
//        cout << "import No." << i << " sorted list" << endl;
        cout << "import the list" << endl;
        while (cin >> num)
        {
            p_1 = new ListNode(num);
            p_2->next = p_1;
            p_2 = p_1;
        }
        lists.push_back(head->next);
        delete head;
    }

    p_1 = Solution().swapPairs(lists[0]);

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

