class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret(2*n, 0);
        int i = 0; 
        int j = n;
        for(int k = 0; k < n; k++){
            ret[i++] = nums[k];
            ret[i++] = nums[j++];
        
        }
        return ret;
    }
};
