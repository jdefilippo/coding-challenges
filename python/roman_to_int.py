class Solution:
    def romanToInt(self, s: str) -> int:

        i = 0 
        res = 0 
        while(i < len(s)-1):
            if s[i:i+2]   == "IV":
                res += 4
                i += 2
            elif s[i:i+2] == "IX":
                res += 9
                i += 2
            elif s[i:i+2] == "XL": 
                res += 40
                i += 2
            elif s[i:i+2] == "XC":
                res += 90
                i += 2
            elif s[i:i+2] == "CD":
                res += 400
                i += 2
            elif s[i:i+2] == "CM":
                res += 900 
                i += 2
            elif s[i] == "I":
                res += 1 
                i += 1
            elif s[i] == "V": 
                res += 5
                i += 1
            elif s[i] == "X": 
                res += 10 
                i += 1
            elif s[i] == "L":
                res += 50
                i += 1
            elif s[i] == "C":
                res += 100 
                i += 1
            elif s[i] == "D":
                res += 500
                i += 1
            elif s[i] == "M":
                res += 1000
                i += 1
            else:
                pass
        if i == len(s)-1:
            if s[i] == "I":
                res += 1 
            elif s[i] == "V": 
                res += 5
            elif s[i] == "X": 
                res += 10 
            elif s[i] == "L":
                res += 50
            elif s[i] == "C":
                res += 100 
            elif s[i] == "D":
                res += 500
            elif s[i] == "M":
                res += 1000
            else:
                pass
        
        return res