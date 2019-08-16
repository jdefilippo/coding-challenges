// Please see https://leetcode.com/problems/same-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (isDifferent(p, q))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool isDifferent(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q != NULL)
        {
            return true;
        }
        else if (p != NULL && q == NULL)
        {
            return true;
        }
        else if (p == NULL && q == NULL)
        {
            return false;
        }
        else if (p->val != q->val)
        {
            return true;
        }
        else
        {
            return (isDifferent(p->left, q->left) ||
                    isDifferent(p->right, q->right));
        }
    }
};