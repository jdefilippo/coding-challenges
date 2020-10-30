// For problem description, see https://leetcode.com/problems/fizz-buzz/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result; 
        for(int i = 1; i <= n; i++)
        {
            if ((i % 3 == 0) && (i % 5 != 0))
            {
                result.push_back("Fizz");     
            }
            else if ((i % 3 != 0) && (i % 5 == 0))
            {
                result.push_back("Buzz");  
            }
            else if ((i % 3 == 0) && (i % 5 == 0))
            {
                result.push_back("FizzBuzz");  
            }
            else
            {
                result.push_back(std::to_string(i));  
            }                
        }
        return result; 
    }
};
