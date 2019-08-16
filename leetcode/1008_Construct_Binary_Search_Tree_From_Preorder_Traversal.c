// Please see https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *myTree = NULL;

        insertNode(&myTree, preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
        {
            insertIntoBST(&myTree, preorder[i]);
        }
        return myTree;
    }
    void insertNode(TreeNode **root, int val)
    {
        *root = new TreeNode(val);
    }
    void insertIntoBST(TreeNode **root, int val)
    {
        if (*root == NULL)
        {
            return;
        }
        if (val >= (*root)->val)
        {
            if ((*root)->right == NULL)
            {
                insertNode(&((*root)->right), val);
            }
            else
            {
                insertIntoBST(&((*root)->right), val);
            }
        }
        else
        {
            if ((*root)->left == NULL)
            {
                insertNode(&((*root)->left), val);
            }
            else
            {
                insertIntoBST(&((*root)->left), val);
            }
        }
    }
};