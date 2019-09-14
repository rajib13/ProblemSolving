class Solution {
public:
    bool isPowerOfThree(int n) {
        
        return fmod(log10(n)/log10(3), 1) == 0; //  % is defined only for integers in C++, but in Java that is ok. Used fmod() for double. 
        
    }
};
