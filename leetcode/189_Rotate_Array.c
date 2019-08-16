//For problem description, see https://leetcode.com/problems/rotate-array/
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> result = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            result[(i + k) % (nums.size())] = nums[i];
        }
        nums = result;
    }
};