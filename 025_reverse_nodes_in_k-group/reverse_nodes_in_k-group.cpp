//============================================================================
// Name        : 25. Reverse Nodes in k-Group
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 25. Reverse Nodes in k-Group
// Accepted Date: 2017/09/18
/*****************************************************************************
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 k is a positive integer and is less than or equal to the length of the linked list.
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 You may not alter the values in the nodes, only nodes itself may be changed.
 Only constant memory is allowed.

 For example,
 Given this linked list: 1->2->3->4->5
 For k = 2, you should return: 2->1->4->3->5
 For k = 3, you should return: 3->2->1->4->5

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        detail(&head, k);
        return head;
    }

    void detail(ListNode **head, int k)
    {
        if (k <= 1 || *head == NULL)
            return;
        else
        {
            ListNode *p = *head;
            for (int i = 0; i < k / 2 && p != NULL; ++i, p = p->next);

            if (p == NULL) return;

            ListNode *tail_1 = (*head);
            ListNode *tail_2 = p;
            ListNode **sub_head = &p;
            detail(head, k / 2);
            detail(sub_head, k - k / 2);
            tail_1->next = tail_2->next;
            tail_2->next = *head;
            *head = *sub_head;
        }
    }
};

int main(int argc, char **argv)
{
    int k, num;
    vector<ListNode*> lists;
    ListNode *p_1 = NULL;
    ListNode *p_2 = NULL;
    ListNode *head = NULL;

    cout << "Enter the group number" << endl;
    cin >> k;

    for (int i = 0; i < 1; i++)
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

    p_1 = Solution().reverseKGroup(lists[0], k);

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
