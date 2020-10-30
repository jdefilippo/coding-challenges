// Please see https://leetcode.com/problems/contains-duplicate/
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        if (vec.size() == nums.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};