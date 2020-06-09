class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n < 1) return false;
        return (n&(n-1)) == 0; 
        
    }
};

/*
Approach 2: Mathematics for any power of m.

        double val = log10(n)/log10(2); // m = 2
        long iVal = val; // To check whether there is any decimal part or not
        return val == iVal? true: false;
*/
