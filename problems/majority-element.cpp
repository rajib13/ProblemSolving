class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0]; 
        int count = 0;
        for ( int i = 0; i < nums.size(); i++){
            count += nums[i] == majority ? 1 : -1; 
            if(count == 0) majority = nums[i+1];
        }
        return majority;
    }
};
