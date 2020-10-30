//For problem description, see https://leetcode.com/problems/sqrtx/
class Solution
{
public:
    int mySqrt(int x)
    {
        long long product;
        if (x == 0 || x == 1)
            return x;

        for (int i = 2; i <= x; i++)
        {
            product = (long long)i * i;
            if (product > x)
            {
                return i - 1;
            }
            else if (product == x)
            {
                return i;
            }
            else
            {
            }
        }
        return -1;
    }
};