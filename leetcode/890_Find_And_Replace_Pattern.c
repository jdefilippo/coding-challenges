// Please see https://leetcode.com/problems/find-and-replace-pattern/
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> resultStrings;
        string myString;
        char pivotChar;
        char pivotCharSub;
        bool permuted[pattern.length()] = {false};
        vector<char> subList;
        string newString;
        // start list here
        for (int k = 0; k < words.size(); k++)
        {
            subList.clear();
            myString = words[k];
            newString = pattern;
            for (int l = 0; l < myString.length(); l++)
            {
                permuted[l] = false;
            }
            // substitute function
            for (int i = 0; i < pattern.length(); i++)
            {
                pivotChar = pattern[i];
                pivotCharSub = myString[i];
                for (int j = 0; j < pattern.length(); j++)
                {
                    if (pattern[j] == pivotChar && !permuted[j] && !inSubList(subList, pivotCharSub))
                    {
                        //cout << " in inner " << endl;
                        //cout << " pivot Char " << pivotChar << endl;
                        newString[j] = pivotCharSub;
                        permuted[j] = true;
                    }
                }
                subList.push_back(pivotCharSub);
            }
            cout << newString << endl;
            if (newString == words[k])
            {
                cout << "permutation!" << endl;
                resultStrings.push_back(newString);
            }
        }

        return resultStrings;
    }
    bool inSubList(vector<char> &subList, char newSub)
    {
        for (int i = 0; i < subList.size(); i++)
        {
            if (newSub == subList[i])
            {
                return true;
            }
        }
        return false;
    };
};