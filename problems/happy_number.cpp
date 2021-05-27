class Solution {
public:
    int next(int n){
        int m = 0; 
        while(n){
            m += pow((n % 10), 2);
            n /= 10;
        }
        return m;
    }
    bool isHappy(int n) {
        /*Approach: Floyd Cycle detection algorithm*/
        int slow = n, fast = next(n); //*** initialize fast one step ahead.
        while(slow != fast){
            slow = next(slow);
            fast = next(fast);
            fast = next(fast);
        }
        return slow == 1;
    }
};

/*
    Complexity analysis:
    Time: O(n), as we need to traverse from `n` to 1.
    Space: O(1), since we do not use any extra space.
*/

