class Solution {
public:
    
   void flip(vector<int>& nums, int j){
          int i = 0;
          while(i < j)
            swap(nums[i++], nums[j--]);
    }
    int findLargest(vector<int>& nums, int target){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) return i;
        }
        return -1;
    }
    vector<int> pancakeSort(vector<int>& nums) {
        int k = nums.size();
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++) {
            int index = findLargest(nums, k);
            flip(nums, index);
            flip(nums, k-1);
            ret.push_back(index + 1);
            ret.push_back(k--);
        }
      return ret;
    }
};

/*
Complexity analysis:
Time: O(n^2), where n is the size of the given array.
Space: O(1)
*/
