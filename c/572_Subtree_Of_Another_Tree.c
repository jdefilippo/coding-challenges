//For problem description, see https://leetcode.com/problems/subtree-of-another-tree/
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
    bool subtreeIsEqual(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
        {
            return true;
        }
        else if (s == NULL || t == NULL)
        {
            return false;
        }
        return s->val == t->val && subtreeIsEqual(s->left, t->left) && subtreeIsEqual(s->right, t->right);
    }
    bool traverse(TreeNode *s, TreeNode *t)
    {
        return s != NULL && (subtreeIsEqual(s, t) || traverse(s->left, t) || traverse(s->right, t));
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        return traverse(s, t);
    }
};