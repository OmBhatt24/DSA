#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        ListNode *next, *prev = NULL;

        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *p = head;
        while (p)
        {
            ListNode *q = p->next, *r = p;

            while (!q->next)
            {
                r = r->next;
                q = q->next;
            }
            if (p->val == q->val)
            {
                p = p->next;
                r.next = NULL;
            }
            else
                return false;
        }
        return true;
    }
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *prev = head, *current = head, *nextNode = (current->next) ? current->next : NULL, *headPtr = head;
        while (nextNode->next)
        {
            if (current->val == nextNode->val)
            {
                if (current == headPtr)
                    headPtr = nextNode->next;
                prev->next = nextNode->next;
            }
            prev = current;
            current = nextNode;
            nextNode = (nextNode->next) ? nextNode->next : NULL;
        }
        return headPtr;
    }
};

int main()
{

    return 0;
}