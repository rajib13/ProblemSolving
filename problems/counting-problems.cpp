class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        int powerOfTwo = 0; 
        for(int i = 1; i <= num; i++){
            if( 0 == (i & (i - 1))) powerOfTwo = i;
            dp[i] = dp[i - powerOfTwo] + 1;
        }
        return dp; 
    }
};
