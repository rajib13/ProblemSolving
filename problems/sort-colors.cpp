class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Approach: 2 pointer search.
        int redPointer = 0; 
        int bluePointer = nums.size() - 1; 
        
        
        for(int i = 0; i <= bluePointer; i++){
            if(nums[i] == 0){
                swap(nums[redPointer++], nums[i]);
            }
            else if(nums[i] == 2){
                swap(nums[bluePointer--], nums[i--]); // Be careful about i--. Think about it, the answer is nice. See the note. 
                
            }
        }
        
    }
};

/*

[2,0,2,1,1,0]
[0,0,1,1,2,2]
[0,1,2]
[2,0,1]
[0]
[1]
[2]
[0,0,0,0,0]
[2,2,2,2,0,0,0]
[1,1,1,1,1,0,0,0,0,2,2,2,2]
[1,2,0]
[2,1,2]

*/
