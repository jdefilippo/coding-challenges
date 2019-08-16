//https://leetcode.com/problems/palindrome-number/
class Solution
{
public:
    int getLength(int x)
    {
        int length = 0;
        x = abs(x);
        while (x > 0)
        {
            length++;
            x = x / 10;
        }
        return length;
    }
    int reverse(int x)
    {
        long long new_digit = 0;
        long long reverse = 0;
        long long factor = 0;
        long long length = 0;
        length = getLength(x);
        factor = pow(10, length - 1);
        while (x > 0)
        {
            new_digit = x % 10;
            reverse += new_digit * factor;
            factor /= 10;
            x /= 10;
        }
        if (reverse < INT_MAX)
        {
            return (int)reverse;
        }
        else
        {
            return 0;
        }
    }

    bool isPalindrome(int x)
    {
        int temp;
        if (x < 0)
        {
            return false;
        }
        else
        {
            temp = reverse(x);
            if (temp == x)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
