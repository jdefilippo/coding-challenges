// Please see https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        //TreeNode* test = NULL;
        //insertNode(&test, 5);
        //cout << test->val << endl;

        if (root == NULL)
            return root;

        if (val > root->val)
        {
            //cout << root->val << endl;
            if (root->right == NULL)
            {
                insertNode(&(root->right), val);
            }
            else
            {
                insertIntoBST(root->right, val);
            }
        }
        else
        {
            //cout << root->val << endl;
            if (root->left == NULL)
            {
                insertNode(&(root->left), val);
            }
            else
            {
                insertIntoBST(root->left, val);
            }
        }
        return root;
    }
    void insertNode(TreeNode **root, int val)
    {
        *root = new TreeNode(val);
    }
};