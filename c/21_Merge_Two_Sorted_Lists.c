// Please see https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *cHead = NULL;
        // if only one of the original lists in non-empty, simply return the non-empty lst
        if (l1 == NULL && l2 != NULL)
        {
            return l2;
        }
        if (l2 == NULL && l1 != NULL)
        {
            return l1;
        }
        // compare lists
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val == l2->val)
            {
                insertNodeAtEnd(&cHead, l1->val);
                insertNodeAtEnd(&cHead, l2->val);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1->val < l2->val)
            {
                insertNodeAtEnd(&cHead, l1->val);
                l1 = l1->next;
            }
            else
            {
                insertNodeAtEnd(&cHead, l2->val);
                l2 = l2->next;
            }
        }
        // add remainder of the list
        while (l1 != NULL)
        {
            insertNodeAtEnd(&cHead, l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            insertNodeAtEnd(&cHead, l2->val);
            l2 = l2->next;
        }
        return cHead;
    }
    void insertNodeAtEnd(ListNode **cHead, int newVal)
    {
        ListNode *last = *cHead;
        ListNode *newNode = new ListNode(newVal);
        newNode->next = NULL;
        if (*cHead == NULL)
        {
            *cHead = newNode;
            return;
        }
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = newNode;
        return;
    }
};