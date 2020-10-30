// Please see https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i; j < prices.size(); j++)
            {
                if (maxProfit < (prices[j] - prices[i]))
                {
                    //cout << "New Max" << endl;
                    //cout << "i : " << prices[i] << endl;
                    //cout << "j : " << prices[j] << endl;
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        return maxProfit;
    }
};