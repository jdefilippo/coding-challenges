class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int r1 = 0;
        int r2 = matrix.size() - 1;
        int c1 = 0;
        int c2 = matrix[0].size() - 1;
        queue<int> buffer;
        int replacePoint = matrix.size() - 1;
        int startReplacing = 0;

        while (r1 <= r2 && c1 <= c2)
        {
            for (int c = c1; c <= c2; c++)
            {
                buffer.push(matrix[r1][c]);
                if (startReplacing == replacePoint)
                {
                    matrix[r1][c] = buffer.front();
                    buffer.pop();
                }
                if (startReplacing < replacePoint)
                {
                    startReplacing++;
                }
            }
            for (int r = r1 + 1; r <= r2; r++)
            {
                buffer.push(matrix[r][c2]);
                matrix[r][c2] = buffer.front();
                buffer.pop();
            }

            if (r1 < r2 && c1 < c2)
            {
                for (int c = c2 - 1; c > c1; c--)
                {
                    buffer.push(matrix[r2][c]);
                    matrix[r2][c] = buffer.front();
                    buffer.pop();
                }
                for (int r = r2; r > r1; r--)
                {
                    buffer.push(matrix[r][c1]);
                    matrix[r][c1] = buffer.front();
                    buffer.pop();
                }
                // Only pop on the last time through!
                for (int c = c1; c < c2; c++)
                {
                    matrix[r1][c] = buffer.front();
                    buffer.pop();
                }
            }
            r1++;
            r2--;
            c1++;
            c2--;
            replacePoint -= 2;
            startReplacing = 0;
        }
    }
};