//For problem description, see https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        int prevVal = -1;
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *curNode = head;

        while (curNode != NULL)
        {
            if (prevVal == curNode->val)
            {
                deleteNode(head, curNode);
            }
            // set previous val to current val
            prevVal = curNode->val;
            // move to next node in linked list
            curNode = curNode->next;
        }
        return head;
    }
    void deleteNode(ListNode *head, ListNode *delNode)
    {
        ListNode *tmp = head;
        while (tmp->next != NULL && tmp->next != delNode)
        {
            tmp = tmp->next;
        }
        if (tmp->next == NULL)
        {
            return;
        }
        tmp->next = tmp->next->next;
        return;
    }
};