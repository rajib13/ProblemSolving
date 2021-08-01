class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        int count = 0;
        for(int i = 0; i < n - 2; i++){ //  first pointer, a
            int left = i + 1; // second pointer, b 
            int right = n - 1; // third pointer, c
             while (left < right){
                    if(nums[left]  + nums[right] > nums[i]){ // a + b > c
                        count += (right - left); // as the array is sorted so, all elements from the second to third pointer will make a valid triangle.
                        
                        left++;
                    }
                    else right--;
                }
        }
        return count;
    }
};

/*
   Complexity analysis:
   Time: O(n^2), where `n` is the length of the given nums, as the inner and outer loops iterate through `n` times.
   Space: O(logn) to O(n), depending on the implementation of the sorting function.
*/
