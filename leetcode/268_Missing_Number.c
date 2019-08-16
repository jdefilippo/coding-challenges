// Please see https://leetcode.com/problems/missing-number/
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int fullSum = 0;
        int curSum = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            fullSum += i;
        }
        for (int j = 0; j < nums.size(); j++)
        {
            curSum += nums[j];
        }
        return fullSum - curSum;
    }
};