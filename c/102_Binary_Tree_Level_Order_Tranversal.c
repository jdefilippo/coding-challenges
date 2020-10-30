// Please see https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<vector<int>> ans;
        int level = 0;
        vector<int> levelVec;
        vector<int> orderVec;
        vector<int> tmpVec;
        int curLevel = 0;
        queue<TreeNode *> myQueue;
        queue<int> levelQueue;
        TreeNode *traverse;
        myQueue.push(root);
        levelQueue.push(level);
        while (!myQueue.empty())
        {
            traverse = myQueue.front();
            level = levelQueue.front();

            myQueue.pop();
            levelQueue.pop();

            levelVec.push_back(traverse->val);
            orderVec.push_back(level);

            level += 1;

            if (traverse->left != NULL)
            {
                myQueue.push(traverse->left);
                levelQueue.push(level);
            }
            if (traverse->right != NULL)
            {
                myQueue.push(traverse->right);
                levelQueue.push(level);
            }
        }

        for (int i = 0; i < levelVec.size(); i++)
        {

            if (orderVec[i] > curLevel)
            {
                ans.push_back(tmpVec);
                tmpVec.erase(tmpVec.begin(), tmpVec.end());
            }
            tmpVec.push_back(levelVec[i]);
            curLevel = orderVec[i];
        }
        ans.push_back(tmpVec);

        return ans;
    }
};