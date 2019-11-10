class Solution {
public:
    int rob(vector<int>& nums) {
        int ptr1 = 0, ptr2 = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            int curr = max(ptr1 + nums[i], ptr2);
            ptr1 = ptr2;
            ptr2 = curr;
        }
        return ptr2;
    }
};




/*

Approach 1: DP

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo;
        int numsSize = nums.size();
        if(numsSize == 0) return 0;
        else if(numsSize == 1) return nums[0];
        else if(numsSize == 2) return max(nums[0], nums[1]);
        else{
            memo.push_back(nums[0]);
            memo.push_back(max(nums[0], nums[1]));
            
            for(int i =2; i< numsSize; i++){
                int temp = max(nums[i] + memo[i - 2], memo[i - 1]);
                memo.push_back(temp);
            }
        }
        return memo[numsSize - 1];
    }
};


*/
