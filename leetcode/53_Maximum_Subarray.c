//https://leetcode.com/problems/maximum-subarray/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int tally = 0;
        int result = 0;
        int maxForwardSumIdx;
        int maxForwardSum;
        int maxBackwardSumIdx;
        int maxBackwardSum;
        vector<int> tallyForward(nums.size(), 0);
        vector<int> tallyBackward(nums.size(), 0);

        tally = 0;
        maxBackwardSumIdx = 0;
        maxBackwardSum = nums[nums.size() - 1];

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            tally += nums[i];
            tallyBackward[i] = tally;
            if (tallyBackward[i] > maxBackwardSum)
            {
                maxBackwardSumIdx = i;
                maxBackwardSum = tallyBackward[i];
            }
        }

        //cout << "tallyBackward" << endl;
        //for(int i = 0; i < nums.size(); i++)
        //{
        //    cout << tallyBackward[i] << endl;
        //}

        cout << endl
             << endl
             << endl;

        tally = 0;
        maxForwardSumIdx = 0;
        maxForwardSum = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            tally += nums[i];
            tallyForward[i] = tally;
            if (tallyForward[i] > maxForwardSum)
            {
                maxForwardSumIdx = i;
                maxForwardSum = tallyForward[i];
            }
        }
        //cout << "tallyForward" << endl;
        //for(int i = 0; i < nums.size(); i++)
        //{
        //    cout << tallyForward[i] << endl;
        //}

        cout << "maxForwardSumIdx: " << maxForwardSumIdx << endl;
        cout << "maxForwardSum: " << maxForwardSum << endl;
        cout << "maxBackwardSumIdx: " << maxBackwardSumIdx << endl;
        cout << "maxBackwardSum: " << maxBackwardSum << endl;
        if (maxForwardSumIdx < maxBackwardSumIdx)
        {
            for (int i = maxForwardSumIdx; i <= maxBackwardSumIdx; i++)
            {
                result += nums[i];
            }
        }
        else
        {
            for (int i = maxBackwardSumIdx; i <= maxForwardSumIdx; i++)
            {
                result += nums[i];
            }
        }
        return result;
    }
};