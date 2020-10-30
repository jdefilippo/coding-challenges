class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0; 
        int curLength = 0; 
        unordered_map<char,int> anagrams; 
        string tmp; 

        for(int pivot = 0; pivot < s.length(); pivot++)
        {
            curLength = 1;  
            anagrams[s[pivot]]++;
            for(int j = pivot+1; j < s.length(); j++)
            {
                if(anagrams[s[j]] == 0)
                {
                    curLength++; 
                    anagrams[s[j]]++;
                }
                else
                {
                    break; 
                }                
            }
            if(curLength > maxLength)
            {
                maxLength = curLength; 
            }
            resetMap(anagrams);
        }
        return maxLength; 
    }
    void resetMap(unordered_map<char,int>& anagrams)
    {
        unordered_map<char,int>::iterator it; 
        for ( it = anagrams.begin(); it != anagrams.end(); it++ )
        {
            it->second = 0; 
            //std::cout << it->first  // string (key)
            //          << ':'
            //          << it->second   // string's value 
            //          << std::endl ;
        }
    }
};