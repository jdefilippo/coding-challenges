// Please see https://leetcode.com/problems/sort-array-by-parity/
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
            {
                even.push_back(A[i]);
            }
            else
            {
                odd.push_back(A[i]);
            }
            //even.insert(even.end(),odd.begin(), odd.end());
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};