class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        /*Approach 1: Same idea of approach 1 but one pass solution*/
        int count = 0; 
        for(int i = 1; i  < nums.size(); i++){
            if(nums[i-1] > nums[i]){
                if (count) return false;
                count++;
                if(i-2 < 0 or nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        
        return count <= 1; 
    }
};


/*
Approach 1 : two pass algorithm

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    
        int count = 0; 
        for(int i = 1; i  < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                if(count) return false;
                count++;
                if(nums[i-1] > nums[i+1]) nums[i+1] = nums[i];
                else nums[i] = nums[i+1];
            }
        }
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1] and count == 1) return false;
        }

        return true; 
    }
};

*/



/*

[4,2,3]
[3,4,2]
[4,3,2]
[3,2,4]
[2,3,4]
[2,4,3]
[4,2,3]
[1,2,3]
[]
[1]
[2,3]
[3,2]
[3,4,2,3]
[-1,4,2,3]
[2,3,3,2,4]
*/
