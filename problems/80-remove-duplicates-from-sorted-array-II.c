
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0; 
        for(int num : nums){
            if(count < 2 || num > nums[count-2]) nums[count++] = num;
        }
        return count;
    }
};

/*
Approach 2: 
int removeDuplicates(int* nums, int numsSize){
    int prev = -100, count = 0, occur = 0;
    for(int i = 0; i < numsSize; i++){
        if((nums[i] != prev) || occur < 2 ){
            nums[count++] = nums[i];
            occur  = prev != nums[i] ? 1 : 2;
            prev = nums[i];
        }
           
    }
return count; 
}*/

