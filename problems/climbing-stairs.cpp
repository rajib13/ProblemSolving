class Solution {
public:
    int climbStairs(int n) {
        int first = 0;
        int second = 1;
        
        for(int i = 2; i <= n; i++){
            int third = first + second;
            first = second;
            second = third;
        }
        return first + second; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where n is the number of stairs;
    Space: O(1), since we did not use any extra space;
*/
