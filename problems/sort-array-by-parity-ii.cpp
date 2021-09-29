class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 0;
        int n = nums.size();
        // First, transfer all odd numbers in the left side.
        for(int i = 0; i < n; i++){
            if(odd >= n) break;
            if(nums[i] % 2){
                swap(nums[i], nums[odd++]);
            }
        }
        // Now, just swap between sides every other element
        int i = 0; 
        int j = n - 1;
        while(i < j){
            swap(nums[i], nums[j]);
            i += 2;
            j -= 2;
        }
        return nums;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as we need to scan every element at least once.
    Space: O(1), since we do not use any extra space. 
*/
