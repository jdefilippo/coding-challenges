//https://leetcode.com/problems/group-anagrams/
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        vector<string> newAnagram;
        string tmp;
        unordered_map<string, vector<string>> anagrams;
        for (int i = 0; i < strs.size(); i++)
        {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            anagrams[tmp].push_back(strs[i]);
        }

        unordered_map<string, vector<string>>::iterator it;
        for (it = anagrams.begin(); it != anagrams.end(); it++)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};