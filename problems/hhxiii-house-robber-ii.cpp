class Solution {
public:
    
    int helper(vector<int>& nums, int start, int numsSize){
        
        int ptr1 = 0, ptr2 = 0;
        for(int i = start; i < numsSize; i++){
            int curr = max(ptr1 + nums[i], ptr2);
            ptr1 = ptr2;
            ptr2 = curr;
        }
        return ptr2;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums[0];
        
        return max(helper(nums, 0, nums.size() - 1), helper(nums, 1, nums.size()));
 
    }
};



/*
Approach 1 : DP
class Solution {
public:
    vector<int> memo;
    
    int helper(vector<int>& nums, int start, int numsSize){
        
        memo.clear();
        memo.push_back(nums[start]);
        memo.push_back(max(nums[start], nums[start + 1]));

        for(int i = start + 2; i < numsSize; i++){
            int temp = max(nums[i] + memo[i - (start + 2)], memo[i - (start +1)]);
            memo.push_back(temp);
        }
    
        return memo[memo.size() - 1];
    }
    
    
    int rob(vector<int>& nums) {
        
        
        int numsSize = nums.size();
        if(numsSize == 0) return 0;
        else if(numsSize == 1) return nums[0];
        else if(numsSize == 2) return max(nums[0], nums[1]);
        else{
            return max(helper(nums, 0, numsSize - 1), helper(nums, 1, numsSize));
        }
        
    }
};

*/
