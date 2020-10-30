//https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }
        bool appeared[nums.size()] = {false};
        vector<int> dups = {};

        for (int i = 0; i < nums.size(); i++)
        {
            if (appeared[(nums[i] - 1)])
            {
                dups.push_back(nums[i]);
            }
            else
            {
                appeared[(nums[i] - 1)] = true;
            }
        }
        return dups;
    }
};