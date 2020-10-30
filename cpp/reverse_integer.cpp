class Solution {
public:
    int getLength(int x) { 
        int length = 0; 
        if(x<0) { 
            x = -x;
        }
        while(x>0) { 
            length++; 
            x=x/10; 
        }
        return length; 
    }
    
    int reverse(int x) {
        long long new_digit; 
        long long reverse=0; 
        int length; 
        long long factor;
        int sign = 1; 
        length = getLength(x); 
        factor = pow(10, length-1); 
        if(x<0) { 
            x=-x;
            sign=-1; 
        }
        while(x>0) { 
            new_digit = x % 10; 
            new_digit = factor*new_digit;
            reverse += new_digit; 
            x = x/10; 
            factor = factor/10; 
        }
        if(reverse < INT_MAX) { 
            reverse = sign*reverse; 
            return (int) reverse; 
        }
        else { 
            return 0; 
        }
    }
};