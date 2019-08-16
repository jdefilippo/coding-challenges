// Please see https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
    TreeNode *bstToGst(TreeNode *root)
    {
        TreeNode thing = *root;
        bstTraverse(&thing);
        return &thing;
    }
    void bstTraverse(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->val << endl;
        bstTraverse(root->right);
    }
};