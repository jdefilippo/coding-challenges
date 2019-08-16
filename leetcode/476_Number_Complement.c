// Please see https://leetcode.com/problems/number-complement/
class Solution
{
public:
    int findComplement(int num)
    {
        vector<int> digits = {};
        createDigits(num, digits);
        createComplementDigits(digits);
        int complement = 0;
        long powerOfTwo = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            complement += digits[i] * powerOfTwo;
            powerOfTwo *= 2;
        }
        return complement;
    }
    void createDigits(unsigned n, vector<int> &digits)
    {
        if (n > 1)
            createDigits(n / 2, digits);
        digits.push_back(n % 2);
    }
    void createComplementDigits(vector<int> &digits)
    {
        for (int i = 0; i < digits.size(); i++)
        {
            (digits[i] == 1) ? digits[i] = 0 : digits[i] = 1;
        }
    }
    void printDigits(vector<int> &digits)
    {
        for (int i = 0; i < digits.size(); i++)
        {
            cout << digits[i] << " ";
        }
        cout << endl;
    }
};
