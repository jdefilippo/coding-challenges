//https://leetcode.com/problems/climbing-stairs/
class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[n];
        // BASE CASE
        if (n >= 1)
        {
            dp[0] = 1;
        }
        if (n >= 2)
        {
            dp[1] = 2;
        }
        if (n >= 3)
        {
            dp[2] = 3;
        }
        if (n >= 4)
        {
            dp[3] = 5;
        }
        // Building from the bottom
        for (int i = 4; i < n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n - 1];
    }
};