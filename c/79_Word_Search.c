//For problem description, see https://leetcode.com/problems/word-search/
class Solution
{
public:
    void printVisited(vector<vector<bool>> &isVisited)
    {
        for (int i = 0; i < isVisited.size(); i++)
        {
            for (int j = 0; j < isVisited[0].size(); j++)
            {
                cout << isVisited[i][j];
            }
            cout << endl;
        }
    }
    void resetVisited(vector<vector<bool>> &isVisited)
    {
        for (int i = 0; i < isVisited.size(); i++)
        {
            for (int j = 0; j < isVisited[0].size(); j++)
            {
                isVisited[i][j] = false;
            }
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        bool result = false;
        string tmp = word;
        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
        int rowSize = board.size();
        int colSize = board[0].size();
        cout << rowSize << endl;
        cout << colSize << endl;
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (i == 1 && j == 1)
                    {
                        cout << "AT SOLUTION!" << endl;
                    }
                    result = findWord(tmp, board, isVisited, i, j);
                    if (result)
                        return true;
                }
                tmp = word;
                resetVisited(isVisited);
            }
        }
        return false;
    }
    bool findWord(string &ctrWord, vector<vector<char>> &board, vector<vector<bool>> &isVisited, int ri, int cj)
    {
        //cout << "at beginning of findWord" << endl;
        bool result1 = false;
        bool result2 = false;
        bool result3 = false;
        bool result4 = false;
        int rowSize = board.size();
        int colSize = board[0].size();

        if (ctrWord.length() == 0)
        {
            return true;
        }
        else
        {
            if ((ri > rowSize - 1) || ri < 0)
            {
                //cout << "Row Size guard " << endl;
                return false;
            }
            else if ((cj > colSize - 1) || cj < 0)
            {
                //cout << "Column Size guard " << endl;
                return false;
            }
            else if (board[ri][cj] != ctrWord[0])
            {
                return false;
            }
            else if (isVisited[ri][cj])
            {
                cout << "isVisited tigger" << endl;
                return false;
            }
            else
            {

                cout << endl
                     << endl;

                isVisited[ri][cj] = true;
                ctrWord = ctrWord.substr(1, ctrWord.size());
                cout << "First Way" << endl;
                cout << "Board value " << board[ri][cj] << endl;
                cout << "ri: " << ri << endl;
                cout << "cj: " << cj << endl;
                cout << endl
                     << endl;
                result1 = findWord(ctrWord, board, isVisited, ri + 1, cj);
                cout << "Second Way" << endl;
                cout << "Board value " << board[ri][cj] << endl;
                cout << "ri: " << ri << endl;
                cout << "cj: " << cj << endl;
                cout << endl
                     << endl;
                result2 = findWord(ctrWord, board, isVisited, ri - 1, cj);
                cout << "Third Way" << endl;
                cout << "Board value " << board[ri][cj] << endl;
                cout << "ri: " << ri << endl;
                cout << "cj: " << cj << endl;
                cout << endl
                     << endl;
                result3 = findWord(ctrWord, board, isVisited, ri, cj + 1);
                cout << "Fourth Way" << endl;
                cout << "Board value " << board[ri][cj] << endl;
                cout << "ri: " << ri << endl;
                cout << "cj: " << cj << endl;
                cout << endl
                     << endl;
                result4 = findWord(ctrWord, board, isVisited, ri, cj - 1);
                if (result1 || result2 || result3 || result4)
                {
                    return true;
                }
                else
                {
                    return false;
                }
                //return (findWord(ctrWord,board,isVisited,ri+1, cj) ||
                //findWord(ctrWord,board,isVisited,ri-1, cj)     ||
                //findWord(ctrWord,board,isVisited,ri,   cj+1)  ||
                //findWord(ctrWord,board,isVisited,ri,   cj-1));
            }
        }
    }
};