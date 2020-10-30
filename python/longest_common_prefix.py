class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ### original solution 
        '''
        match_idx = 0 
        match_char = "" 
        res = "" 
        foundLCA = False
        
        if not strs: 
            return res
        
        while(not foundLCA):
            if match_char != "": 
                res += match_char
            
            # Create match char from the first string 
            if(match_idx<len(strs[0])):
                match_char = strs[0][match_idx]
            else:
                foundLCA = True
                break
                           
            for string in range(1, len(strs)):
                if(match_idx>=len(strs[string]) or not strs[string][match_idx] == match_char):
                    foundLCA = True 
                    break
            
            match_idx += 1 
        
        return res
        '''
        ### horizontal scaling 
        '''
        if len(strs)==0:
            return ""
        
        prefix = strs[0]
        for i in range(1,len(strs),1):
            while(prefix != strs[i][0:len(prefix)]):
                prefix = prefix[:-1]
                if(prefix == ""):
                    return ""
        return prefix
        '''
        if not strs:
            return ""
        
        for i in range(0,len(strs[0]),1):
            c = strs[0][i]
            for j in range(1,len(strs),1):
                if(i == len(strs[j]) or strs[j][i] != c):
                    return strs[0][0:i]
                
        return strs[0]