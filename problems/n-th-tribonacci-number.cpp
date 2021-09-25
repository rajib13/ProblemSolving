class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n < 3) return 1;
        int a = 0;
        int b = 1;
        int c = 1;
        
        for(int i = 3; i <= n; i++){
            int d = a + b + c;
            
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};

/*
    Complexity analysis:
    Time: O(n), as we need to compute the tribonacci `n` times.
    Space: O(1), since we do not use any extra space.
*/
