class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum = 0 ; 
        for(int num : nums){
            if(num % 2 == 0) sum += num;
        }
        vector<int> ret;
        for(auto query : queries){
            int value = query[0];
            int pos = query[1];
            
            if(nums[pos] % 2 == 0){
                sum -= nums[pos];
            }
            nums[pos] += value;
            
            if(nums[pos] % 2 == 0){
                sum += nums[pos];
            }
            
            ret.push_back(sum);
            
        }
        return ret;
    }
};
