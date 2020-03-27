class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*Approach 2: one liner using unique built in function*/
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};


/* Approach 1: brute force. O(n) time and O(1) space. 
        if(nums.size() == 0) return 0;
        
        int count = 1; 
        for(int i=1; i< nums.size(); i++){
            if(nums[i-1] != nums[i]){
                nums[count++] = nums[i];
            }
        }
        
     return count; 

*/
