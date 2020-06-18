class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single_number = 0;
        for(int i=0; i<nums.size(); i++){
            single_number ^= nums[i]; 
        }
        return single_number;
        
    }
};

/*Complexity Analysis:
Time: O(n), as we need to scan all elements once.
Space: O(1), since we did not use any extra space.*/
