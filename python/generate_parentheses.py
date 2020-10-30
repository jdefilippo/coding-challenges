
def backtracking(solSet, result, parenStack, numOpenRem, numCloseRem):
    #print("solSet", solSet)
    if(numOpenRem == 0 and numCloseRem == 0):
        if(result not in solSet): 
            solSet.append(result)
    else:
        # Add open paren
        if(numOpenRem > 0):             
            numOpenRem -= 1
            parenStack.insert(0, '(')
            result += "("
            backtracking(solSet, result, parenStack, numOpenRem, numCloseRem)
            numOpenRem += 1  
            parenStack.pop(0)
            result = result[:-1]
        
        # Add close paren      
        # Base and bound
        if(parenStack and parenStack[0] == '(' and numCloseRem > 0):
            numCloseRem -= 1
            result += ')'
            parenStack.pop(0)
            backtracking(solSet, result, parenStack, numOpenRem, numCloseRem)
            numCloseRem += 1
            result = result[:-1]
            parenStack.insert(0, '(')

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        solSet = [] 
        result = "" 
        parenStack  = [] 
        numOpenRem  = n 
        numCloseRem = n 
        backtracking(solSet, result, parenStack, numOpenRem, numCloseRem)
        return solSet