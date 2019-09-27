class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        /*This is the Kadene's algorithm*/
        
        
        /*It is necessary to initialize with first element
        otherwise when there is only one element then it fails.
        And if we initialize with INT_MIN then there would be runtime error : -2 + -2147483648 cannot be represented in type 'int'  */
        
        int best = nums[0];
        int sum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            sum = max(sum+nums[i], nums[i]);
            best = max(best, sum);
            
        }
        return best; 
        
    }
};
