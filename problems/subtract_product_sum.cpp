class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        
        while(n > 0){
            int lastDigit = n % 10;
            product *= lastDigit;
            sum += lastDigit;
            n /= 10;
        }
        
        return product - sum; 
    }
};

/*
    Complexity analysis:
    Time: O(1), as the given number `n` is an integer meaning there could be maximum ten digits, so the loop execute at most ten times.
    Space: O(1), since we do not use any extra space.
*/

