//For problem description, see https://leetcode.com/problems/valid-palindrome/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string s2;
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                if (isupper(s[i]))
                {
                    s2 += tolower(s[i]);
                }
                else
                {
                    s2 += s[i];
                }
            }
        }
        for (int i = 0; i < s2.length(); i++)
        {
            if (s2[i] != s2[s2.length() - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};