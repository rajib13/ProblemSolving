class Solution {
public:
    int arrangeCoins(int n) {
        /*
           a(a+1)/2 = n
           => a(a+1) = 2n
           => a^2 + a = 2n
           => (a + 1/2)^2 - 1/4 = 2n
           a = sqrt(2n + 1/4) - 1/2
        */
        
        return sqrt(2 * (long) n + 0.25) - 0.5;
    }
};


/*
class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0;
        int high = n;
        
        // Binary search approach
        
        while(low <= high){
            int mid = low + (high - low)/2;
            long totalCoins = (long) mid * (long)(mid+1)/2;
            
            if(totalCoins == n) return mid;
            if(totalCoins > n) high = mid -1;
            else low = mid + 1;
        }
        return high;
    }
};
*/

/*
Complexity analysis:
Time: O(1)
Space: O(1)
*/
