class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest = INT_MIN;
        int secondBiggest = INT_MIN;
        
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > biggest){
                secondBiggest = biggest; 
                biggest = nums[i];
            }
            else if(nums[i] > secondBiggest) secondBiggest = nums[i]; 
        }
        return (biggest-1)*(secondBiggest-1);
    }
};

/*
    Complexity Analysis:
    Time: O(n), as we need to scan all elements once. 
    Space: O(1), since we do not extra space.
*/
