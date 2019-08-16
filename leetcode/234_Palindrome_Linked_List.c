//For problem description, see https://leetcode.com/problems/palindrome-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *revHead = NULL;
        ListNode *tmpHead = head;
        while (tmpHead != NULL)
        {
            insertNodeAtBeginning(&revHead, tmpHead->val);
            tmpHead = tmpHead->next;
        }
        while (head != NULL && revHead != NULL)
        {
            if (head->val != revHead->val)
            {
                return false;
            }
            head = head->next;
            revHead = revHead->next;
        }
        return true;
    }

    void insertNodeAtBeginning(ListNode **newHead, int newVal)
    {
        ListNode *tmp = new ListNode(newVal);
        tmp->next = (*newHead);
        (*newHead) = tmp;
    }
};