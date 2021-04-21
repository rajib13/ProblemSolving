class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        return ( n & (n-1)) == 0;
    }
};

/*
    Complexity analysis:
    Time: O(1), as the time complexity does not depend on the given inpput `n`.
    Space: O(1), as we do not need any extra space.
*/
