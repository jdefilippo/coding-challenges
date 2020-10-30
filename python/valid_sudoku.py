class Solution:

                                     
        
    def isValidSudoku(self, board: List[List[str]]) -> bool:                     
        def findSubBox(i, j): 
            if (i <= 2 and j <= 2): 
                return 0
            elif(i <= 2 and j >= 3 and j <= 5): 
                return 1
            elif(i <= 2 and j >= 6 and j <= 8): 
                return 2        
            elif (i >= 3 and i <= 5 and j <= 2): 
                return 3 
            elif(i >= 3 and i <= 5 and j >= 3 and j <= 5): 
                return 4
            elif(i >= 3 and i <= 5 and j >= 6 and j <= 8): 
                return 5       
            elif (i >= 6 and i <= 8 and j <= 2): 
                return 6
            elif(i >= 6 and i <= 8 and j >= 3 and j <= 5): 
                return 7
            elif(i >= 6 and i <= 8 and j >= 6 and j <= 8): 
                return 8  
            else:
                return -1
            
        def determineValidity(board, rows, cols, boxes):
            for i in range(0, len(board),1): 
                for j in range(0, len(board),1): 
                    if board[i][j] != '.': 
                        searchNum = int(board[i][j])
                        if searchNum in rows[i]: 
                            return False
                        else: 
                            rows[i].add(int(board[i][j]))
                        if searchNum in cols[j]: 
                            return False
                        else: 
                            cols[j].add(int(board[i][j]))  
                        subBoxIdx = findSubBox(i,j)
                        if searchNum in boxes[subBoxIdx]: 
                            return False 
                        else:
                            boxes[subBoxIdx].add(int(board[i][j]))  
            return True
                            
        rows  = [set() for i in range(1,10)]
        cols  = [set() for i in range(1,10)]
        boxes = [set() for i in range(1,10)]
        
        return determineValidity(board,rows,cols,boxes)