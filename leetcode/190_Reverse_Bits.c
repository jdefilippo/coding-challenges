//For problem description, see https://leetcode.com/problems/reverse-bits/
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int bitIdx = 31;
        int msBitIdx = 31;
        int power;
        int m = 0;
        while (bitIdx >= 0)
        {
            power = (int)(pow(2, bitIdx));
            if (power <= n)
            {
                n -= power;
                m += (int)(pow(2, msBitIdx - bitIdx));
            }
            bitIdx--;
        }
        return m;
    };
};
