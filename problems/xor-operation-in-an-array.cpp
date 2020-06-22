class Solution {
public:
    int xorOperation(int n, int start) {
        int ret = 0; 
        for(int i = 0; i < n; i++){
            ret ^= (start + 2*i);
        }
        return ret;
    }
};

/*
Complexity Analysis:
Time: O(n), as we scan every element once.
Space: O(1), since we do not use any extra space. 
*/
