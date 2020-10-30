class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x == 0:
            return True
        if x % 10 == 0: # trailing zeros
            return False
        
        tmp = x
        res = 0 
        while tmp > 0:
            res = res*10 + tmp%10
            tmp //= 10
        
        print(res)
        if res == x:
            return True
        
        return False