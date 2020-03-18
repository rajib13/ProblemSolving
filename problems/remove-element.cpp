class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int elementCount =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[elementCount++] = nums[i];
            }
        }
        return elementCount;
    }
};


/* Approach 2:  

    The key point here is "It doesn't matter what you leave beyond the new length." 
    that means you do not need to remove any element but just shift when you find an element
    equals to given value. 
    
    idea: count the element that are equals to val and then shifts non equals value by (i-valCount)
    and every time you see a non equals element count it as elementCount and finally return elementCount. 

    int removeElement(vector<int>& nums, int val) {
        
        int valCount = 0;
        int elementCount = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                valCount++;
            }
            else{
                if(valCount > 0){
                    nums[i-valCount] = nums[i];
                }
                elementCount++;
                
            }
        }
        return elementCount; 
    }

*/
