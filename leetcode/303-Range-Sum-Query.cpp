class NumArray {
private:
    vector<int> prefixSum; // Declare the vector
public:
    NumArray(vector<int>& nums) {
        prefixSum = vector<int>(nums.size()+1, 0);
        
        /*O(1) but O(n) space solution*/
        
        for(int i = 0; i < nums.size(); i++){
            prefixSum[i+1] += prefixSum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return prefixSum[j+1] - prefixSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


/*
    Approach 2 : O(n) and O(1)
    
class NumArray {
public:
    vector<int> vec;
    NumArray(vector<int>& nums) {
        vec = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int k = i; k <= j; k++){
            sum += vec[k];
        }
        return sum;
    }
};

*/
