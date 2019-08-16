// Please see https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode *invertTree(TreeNode *root)
    {
        applyInversion(root);
        return root;
    }
    void applyInversion(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            TreeNode *tmp = root->right;
            root->right = root->left;
            root->left = tmp;
            applyInversion(root->left);
            applyInversion(root->right);
        }
    }
};