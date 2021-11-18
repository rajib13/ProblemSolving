class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        
        for(int i = 0; i < nums.size(); i++){
            int j = abs(nums[i]) - 1;
            if(nums[j] > 0){
                nums[j] *= -1;
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) ret.push_back(i + 1);
        }
        
        return ret;
    }
};


/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the array, as we need to scan every element.
    Space: O(1), since we do not use any extra space. 
*/
