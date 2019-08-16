//For problem description, see https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<int> myStack; 
        if(s.length() == 0)
        {
            return true; 
        }
        if(s.length() == 1)
        {
            return false; 
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                myStack.push(s[i]); 
            }
            else if(s[i] == ')')
            {
                if (myStack.empty() || myStack.top() != '(')
                {
                    return false;
                }
                else
                {
                    myStack.pop(); 
                }
                
            }
            else if(s[i] == '}')
            {
                if (myStack.empty() || myStack.top() != '{')
                {
                    return false;
                }
                else
                {
                    myStack.pop(); 
                }
            }
            else if(s[i] == ']')
            {
                if (myStack.empty() || myStack.top() != '[')
                {
                    return false;
                }
                else
                {
                    myStack.pop(); 
                }                
            }
        }
        if(myStack.empty())
        {
            return true; 
        }
        else
        {
            return false; 
        }
    }
};