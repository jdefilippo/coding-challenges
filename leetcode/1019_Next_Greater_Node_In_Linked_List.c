// Please see https://leetcode.com/problems/next-greater-node-in-linked-list/
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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> myResult = {};
        ListNode *tmp = NULL;
        while (head != NULL && head->next != NULL)
        {
            tmp = head->next;
            while (tmp != NULL)
            {
                if (tmp->val > head->val)
                {
                    myResult.push_back(tmp->val);
                    //cout << tmp->val << endl;
                    //cout << "About to break" << endl;
                    break;
                }
                tmp = tmp->next;
            }
            if (tmp == NULL)
            {
                myResult.push_back(0);
                //cout << "In null " << endl;
            }
            head = head->next;
        }

        while (head != NULL)
        {
            myResult.push_back(0);
            head = head->next;
        }

        return myResult;
    }
};