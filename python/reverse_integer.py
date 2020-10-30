class Solution:
    def reverse(self, x: int) -> int:
        res = 0
        isNeg = False
        if x < 0:
            isNeg = True
            
        x = abs(x)
            
        while x:
            digit = x % 10 
            x //= 10
            res = res * 10 + digit
            
        if res > 2147483647:
            return 0
        if res < -2147483648:
            return 0
        
        if isNeg:
            return -res 
        else:
            return res