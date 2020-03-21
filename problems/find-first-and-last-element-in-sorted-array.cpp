class Solution {
public:
    
    int binSearch(vector<int>& nums, int target, bool left){
        int low = 0; 
        int high = nums.size();
        
        while(low < high){
            int mid = low+(high -low)/2;
            
            if(nums[mid] > target || (left && nums[mid] == target)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
    
    /*Approach 2: Binary search*/
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret={-1, -1};
        
        int startTarget = binSearch(nums, target, true);
        
        if(startTarget == nums.size() || nums[startTarget] != target){
            return ret;
        }
        else{
            ret[0] = startTarget;
            ret[1] = binSearch(nums, target, false) - 1;
        }
        

        
        return ret;
    }
   
};


/*
Approach 1: The obvious O(n) solution

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret={-1, -1};
        
        for(int i=0; i<nums.size(); i++){
            if(target == nums[i]){
               if(ret[0] < 0 ){
                   ret[0] = i;
                } 
                ret[1] = i; // edge case: [7] and target =7 should return [0,0] not [0, -1] that is why we update ret[1] every time once we found one. 
            }
        }
        
        return ret;
    }

*/
