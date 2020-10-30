class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def helper(s,p,sP,pP):
            # Five non-recursive cases
            if(sP==len(s) and pP==len(p)):
                return True
            elif(sP==len(s) and pP+1<len(p) and p[pP+1] == '*'):
                return helper(s,p,sP,pP+2)
            elif (sP==len(s) or pP==len(p)):
                return False
            elif (s[sP]==p[pP]) and ((((pP+1)<len(p)) and p[pP+1] != '*') or pP+1>=len(p)):
                return helper(s,p,sP+1,pP+1)
            elif ('.'==p[pP]) and ((((pP+1)<len(p)) and p[pP+1] != '*') or pP+1>=len(p)):
                return helper(s,p,sP+1,pP+1)
            elif (s[sP]!=p[pP]) and ((((pP+1)<len(p)) and p[pP+1] != '*') or pP+1>=len(p)): 
                return False
            elif (s[sP]==p[pP] or p[pP] == '.') and (((pP+1)<len(p)) and p[pP+1] == '*'):
                return (helper(s,p,sP+1,pP) or helper(s,p,sP,pP+2))
            elif (s[sP]!=p[pP]) and (((pP+1)<len(p)) and p[pP+1] == '*'): 
                return helper(s,p,sP,pP+2)                
            else:
                print(sP,pP)
                print("DID NOT CONSIDER")
        
        return helper(s,p,0,0)