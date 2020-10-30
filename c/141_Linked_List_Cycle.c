//For problem description, see https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *curNode = head; 
        int currNodeIdx = 0; 
        if(curNode==NULL || curNode->next == NULL)
        {
            return false;
        }
        curNode = curNode->next;
        currNodeIdx++; 
        while(curNode !=NULL)
        {
            //cout << "in while " << endl;
            if(comparePointers(curNode, head, currNodeIdx))
            {
                return true;
            }
            curNode = curNode->next; 
            currNodeIdx++; 
        }
        
        return false;
    };
    bool comparePointers(ListNode *curNode, ListNode *head, int currNodeIdx)
    {
         int idx = 0;
         //cout << "currNodeIdx" << currNodeIdx << endl; 
         while(head!=NULL && idx < currNodeIdx)
         {
             //cout << "curNode Address: " << curNode << endl; 
             //cout << "head Address: " << head << endl; 
             if(curNode == head)
             {
                 return true;
             }
             head = head->next;
             idx++;
         }
        return false;
    }
    

};