class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int localMax = nums[0];
        int localMin = nums[0];
        
        int globalMax = nums[0];
        
        
        for(int i = 1; i < nums.size(); i++){
            
            int maxProduct = localMax  * nums[i];
            int minProduct = localMin  * nums[i];
            
            localMax = max(maxProduct, nums[i]);
            localMax = max(minProduct, localMax);
            
            localMin = min(maxProduct, nums[i]);
            localMin = min(minProduct, localMin);
            
            globalMax = max(globalMax, localMax);
        }
        
        return globalMax;
    }
};
