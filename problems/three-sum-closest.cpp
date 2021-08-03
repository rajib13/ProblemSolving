class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        
        long closest = INT_MAX; 
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int left = i+1; 
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return sum;
                if(abs(sum-target) < abs(target-closest)) {
                     closest = sum;
                }
                else if(sum > target) right--;
                else left++;
            }
        }
        return closest;
    }
};

/*
    Complexity analysis:
    Time: O(n^2), where `n` is the number of elements in the given array, as we have outer and inner loops, and each going through n elements.
    Space: O(logn) to O(n), depending on the implementation of the sorting alroithm.
*/
