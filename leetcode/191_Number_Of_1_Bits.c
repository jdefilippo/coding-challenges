//https://leetcode.com/problems/number-of-1-bits/
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int bitIdx = 31;
        int power;
        int hammingWeight = 0;
        while (bitIdx >= 0)
        {
            power = (int)(pow(2, bitIdx));
            if (power <= n)
            {
                n = n - power;
                hammingWeight++;
            }
            bitIdx--;
        }
        return hammingWeight;
    }
};