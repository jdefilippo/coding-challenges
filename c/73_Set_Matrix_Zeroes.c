//For problem description, see https://leetcode.com/problems/set-matrix-zeroes/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        bool zeroInRow[rowSize] = {false};
        bool zeroInCol[colSize] = {false};
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroInRow[i] = true;
                    zeroInCol[j] = true;
                }
            }
        }

        for (int i = 0; i < rowSize; i++)
        {
            if (zeroInRow[i])
            {
                for (int j = 0; j < colSize; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < colSize; j++)
        {
            if (zeroInCol[j])
            {
                for (int i = 0; i < rowSize; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};