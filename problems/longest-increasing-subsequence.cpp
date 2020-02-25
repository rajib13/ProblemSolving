class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int maxx = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                    maxx = max(maxx, dp[i]);
                }
               
            }
        }
        return maxx;
    }
};
