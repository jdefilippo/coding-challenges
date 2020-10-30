// Please see https://leetcode.com/problems/reverse-string/
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int leftPivot;
        int rightPivot;
        int temp;

        leftPivot = 0;
        rightPivot = s.size() - 1;
        while (leftPivot != rightPivot && leftPivot < rightPivot)
        {
            temp = s[leftPivot];
            s[leftPivot] = s[rightPivot];
            s[rightPivot] = temp;
            leftPivot++;
            rightPivot--;
        }
    }
};