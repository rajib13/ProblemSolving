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
}

