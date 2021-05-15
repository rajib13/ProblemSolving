class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while(x){
            int lastDigit = x % 10; 
            x /= 10; 
            rev = rev * 10 + lastDigit;
        }
        
        return rev > INT_MAX || rev < INT_MIN ? 0 : rev;
    }
};

/*
    Complexity analysis:
    Time: O(log(x)), as there could be at best log10(x) digits in x.
    Space: O(1), since we do not use any extra space.
*/
