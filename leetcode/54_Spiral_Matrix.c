//For problem description, see https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    void printMatrix(vector<vector<int>> matrix)
    {
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                cout << matrix[i][j]; 
            }
            cout << endl; 
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result = {};
        if(matrix.empty())
        {
            return {}; 
        }
        int rowNum = matrix.size(); 
        int colNum = matrix[0].size(); 
        int totalSize = rowNum * colNum;
        

        
        vector<vector<int>> isVisited = matrix; 
        for(int i = 0; i < isVisited.size(); i++)
        {
            for(int j = 0; j < isVisited[0].size(); j++)
            {
                isVisited[i][j] = 0; 
            }
        }
        //printMatrix(isVisited);
        
        bool goRight      = true; 
        bool goDown       = false; 
        bool goLeft       = false; 
        bool goUp         = false;
        int  exploreCount = 0; 
        int spX = 0; 
        int spY = -1; 
        bool firstPass = true;
        //cout << "total Size " << totalSize << endl; 
        while(exploreCount < totalSize)
        {
            if(goRight)
            {
                spY++;
                //cout << "At go left " << endl; 
                //cout << "!isVisited[spX][spY]" << !isVisited[spX][spY] << endl; 
                //cout << "spY" << spY << endl; 
                //cout << "spX" << spX << endl; 
                while(spY < colNum && !isVisited[spX][spY])
                {
                    result.push_back(matrix[spX][spY]);
                    isVisited[spX][spY] = true;
                    exploreCount++; 
                    spY++;
                }
                spY--;
                goRight = false; 
                goDown = true;                
                //printMatrix(isVisited);
                  
            }
            else if (goDown)
            {
                spX++; 
                while(spX < rowNum && !isVisited[spX][spY])
                {
                   result.push_back(matrix[spX][spY]);
                   isVisited[spX][spY] = true;
                   spX++;
                   exploreCount++; 
                }
                spX--; 
                goDown = false; 
                goLeft = true;
                //printMatrix(isVisited);
            }
            else if (goLeft)
            {

                spY--; 
                while(spY >= 0 && !isVisited[spX][spY])
                {
                   result.push_back(matrix[spX][spY]);
                   isVisited[spX][spY] = true;
                   spY--;
                   exploreCount++; 
                }
                spY++; 
                goLeft = false; 
                goUp = true; 
                //printMatrix(isVisited);

            }
            else if (goUp)
            {
                spX--; 
                while(spX >= 0 && !isVisited[spX][spY])
                {
                   result.push_back(matrix[spX][spY]);
                   isVisited[spX][spY] = true;
                   spX--;
                   exploreCount++; 
                }
                spX++; 
                
                goUp = false; 
                goRight = true; 
                //printMatrix(isVisited);
            }
            else
            {}
            
        }
        
        return result; 
    }
};