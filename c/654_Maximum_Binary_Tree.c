// Please see https://leetcode.com/problems/maximum-binary-tree/
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *maxTree = new TreeNode(0);
        vector<int> leftArray;
        vector<int> rightArray;
        if (nums.size() == 0)
        {
            return NULL;
        }
        int maxVal = nums[0];
        int maxIdx = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        // create left array
        for (int i = 0; i < maxIdx; i++)
        {
            leftArray.push_back(nums[i]);
        }
        for (int i = maxIdx + 1; i < nums.size(); i++)
        {
            rightArray.push_back(nums[i]);
        }
        maxTree->val = maxVal;
        maxTree->left = constructMaximumBinaryTree(leftArray);
        maxTree->right = constructMaximumBinaryTree(rightArray);
        return maxTree;
    }
};