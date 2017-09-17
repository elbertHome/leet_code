//============================================================================
// Name        : 19. Remove Nth Node From End of List
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 19. Remove Nth Node From End of List
// Accepted Date: 2017/09/17
/*****************************************************************************

 Given a linked list, remove the nth node from the end of list and return its head.

 For example,
 Given linked list: 1->2->3->4->5, and n = 2.

 After removing the second node from the end, the linked list becomes 1->2->3->5.


 Note:
 Given n will always be valid.
 Try to do this in one pass.


 ******************************************************************************/
//============================================================================
#include <iostream>
#include <queue>

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *f = NULL;
        ListNode *p = head;
        queue<ListNode *> que;

        if (head == NULL)
            return NULL;

        while (p != NULL)
        {
            if (que.size() < n)
            {
                que.push(p);
            }
            else
            {
                f = que.front();
                que.pop();
                que.push(p);
            }
            p = p->next;
        }

        if (f == NULL)
            return que.front()->next;

        f -> next = que.front()->next;
        return head;
    }
};

int main(int argc, char **argv)
{

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;

    ListNode *head = &a;
    int nth;

    cout << "input the n:" << endl;
    cin >> nth;
    head = Solution().removeNthFromEnd(head, nth);
    if (head != NULL)
    {
        cout << head->val;
        head = head->next;
        while (head != NULL)
        {
            cout << " -> " << head->val;
            head = head->next;
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

