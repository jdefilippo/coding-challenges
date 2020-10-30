class Solution:
    def isValid(self, s: str) -> bool:
        stack = [] 
        for elem in s: 
            if elem == '(' or elem == '[' or elem == '{':
                stack.append(elem)            
            elif elem == ')' and stack and stack[-1] == '(': 
                stack.pop()
            elif elem == ']' and stack and stack[-1] == '[': 
                stack.pop()
            elif elem == '}' and stack and stack[-1] == '{': 
                stack.pop()
            else: 
                return False
        
        if len(stack) != 0: 
            return False
        else:
            return True
    