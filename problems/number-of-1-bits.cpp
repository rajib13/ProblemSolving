class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0; 
        while(n){
            count++;
            n &= (n-1);
        }
        return count; 
    }
};

/*
    Complexity Analysis:
    Time: O(1), at the worst case all 32 bits are 1
    Space: O(1), since no additional space is allocated.
*/
