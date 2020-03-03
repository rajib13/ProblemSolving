class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        /*100% time and 100% space efficients of all submissions.*/
        while(x){
            int lastDigit = x %10; 
            x /= 10; 
            
            rev = rev * 10 + lastDigit;
        }
        
        return rev > INT_MAX || rev < INT_MIN ? 0 : rev;
        
    }
};
