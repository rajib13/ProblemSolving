#define MOD 1000000007
class Solution {
public:
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> subarray;
        
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                 subarray.push_back(sum);
            }
           
        }
        sort(subarray.begin(), subarray.end());
        int ret = 0;
        for(int i = left-1; i < right; i++){
            ret = (ret + subarray[i]) %  MOD;
        }
        return ret;
    }
};
