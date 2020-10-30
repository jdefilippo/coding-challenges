// Please see https://leetcode.com/problems/product-of-array-except-self/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // initialize output vector, same size as nums
        vector<int> output(nums.size(), 1);
        int tally = 1;
        // forward traversal
        for (int i = 0; i < nums.size(); i++)
        {
            output[i] *= tally;
            tally *= nums[i];
        }
        tally = 1;
        // backward traversal
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            output[i] *= tally;
            tally *= nums[i];
        }
        return output;
    }
};