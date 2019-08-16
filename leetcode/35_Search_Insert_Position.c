//For problem description, see https://leetcode.com/problems/search-insert-position/
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;
        else if (target > nums[nums.size() - 1])
            return nums.size();
        else
        {
            for (int i = 1; i < nums.size(); i++)
            {
                if (target > nums[i - 1] && target < nums[i])
                    return i;
                else if (target == nums[i])
                    return i;
                else
                {
                }
            }
        }
        return 0;
    };
};
