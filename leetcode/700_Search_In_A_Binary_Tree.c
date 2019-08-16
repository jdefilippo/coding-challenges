// Please see https://leetcode.com/problems/search-in-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // base case 
        if ( root == NULL )
        {
            return NULL;
        }
        else 
        {
            if(root->val == val)
                return root;
        }
        //recursion case
        if( val > root->val )
        {
            return searchBST( root->right,val );            
        }
        else
        {
            return searchBST( root->left,val );
        }
    }
    
};