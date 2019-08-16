// Please see https://leetcode.com/problems/to-lower-case/
class Solution
{
public:
    string toLowerCase(string str)
    {
        char uppers[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        char lowers[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        for (int i = 0; i < str.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (str[i] == uppers[j])
                {
                    str[i] = lowers[j];
                }
            }
        }
        return str;
    }
};