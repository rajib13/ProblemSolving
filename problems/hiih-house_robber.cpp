class Solution {
public:
    int rob(vector<int>& nums) {
        int ptr1 = 0, ptr2 = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            int curr = max(ptr1 + nums[i], ptr2);
            ptr1 = ptr2;
            ptr2 = curr;
        }
        return ptr2;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the array, as we need to iterate over the entire array.
    Space: O(1), since we do not use any extra space;
*/
