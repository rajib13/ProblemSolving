class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ret;
        
        for(int num : nums){
            if(num % 2 == 0) sum += num;
        }
        
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

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given `nums`, as we need to iterate through the array once.
    Space: O(1), since we do not use any extra space.
*/
