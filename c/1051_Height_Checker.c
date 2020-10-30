// Please see https://leetcode.com/problems/height-checker/
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> sortedHeights;
        sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());
        int notRightStanding = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (sortedHeights[i] != heights[i])
            {
                notRightStanding++;
            }
        }

        return notRightStanding;
    }
};