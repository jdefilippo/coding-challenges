//For problem description, see https://leetcode.com/problems/maximum-product-subarray/
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int prod;
        int maxProd;
        if (nums.size() > 0)
        {
            maxProd = nums[0];
        }
        else
        {
            maxProd = 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            /* reset product for each element */
            prod = 1;
            for (int j = i; j < nums.size(); j++)
            {
                prod *= nums[j];
                if (prod > maxProd)
                    maxProd = prod;
            }
        }
        return maxProd;
    }
};