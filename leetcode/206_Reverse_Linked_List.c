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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newHead = NULL;
        while (head != NULL)
        {
            insertNodeAtBeginning(&newHead, head->val);
            head = head->next;
        }
        //printNodes(newHead);
        return newHead;
    }
    void printNodes(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }
    void insertNodeAtBeginning(ListNode **newHead, int newVal)
    {
        ListNode *tmp = new ListNode(newVal);
        tmp->next = (*newHead);
        (*newHead) = tmp;
    }
};
