// Please see https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode *middleNode(ListNode *head)
    {

        if (head->next == NULL && head != NULL)
        {
            return head;
        }
        int numNodes = countNodes(head);

        return getHalfNode(head, numNodes / 2);
    }
    int countNodes(ListNode *head)
    {
        int cnt = 0;
        while (head != NULL)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode *getHalfNode(ListNode *head, int midNode)
    {
        int idx = 0;
        while (head != NULL)
        {
            if (midNode == idx)
            {
                return head;
            }
            head = head->next;
            idx++;
        }
        return NULL;
    }
};