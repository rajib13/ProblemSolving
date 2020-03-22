class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3) return ret;
        sort(nums.begin(), nums.end());
        
        for (int i = 0 ; i < nums.size() - 2; i++){
            if(nums[i] > 0) break; // as we sorted the array, so if a==nums[i]==0 then always a+b+c > 0
            if(i > 0 and nums[i] == nums[i-1]) continue; // We already checked for this a. 
            int left = i + 1;
            int right = nums.size() - 1; 
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right]; // a+b+c
                if(sum == 0){
                    ret.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    
                    while(left < right and nums[left] == nums[left+1]) left++;
                    while(left < right and nums[right] == nums[right-1]) right--;
                    left++; // While loop exists when these pointer at the edge of duplicate entries. 
                    right--;  
                } 
                else if(sum > 0) right--;
                else left++;
            }
            
            
        }
        return ret;
        
    }
};
