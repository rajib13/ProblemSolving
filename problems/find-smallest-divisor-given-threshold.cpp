class Solution {
public:
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1; 
        int high = 1e6; // maximum possible length
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int sum = 0;
            for(int i = 0; i < nums.size(); i++){
                sum += nums[i]/mid;
                if(nums[i] % mid) sum++;
            }
            if(sum <= threshold)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return low;
    }
};

/*
    Complexity analysis:
    Time: O(logn), where `n` is the maximum possible length, as in every iteration we discard half of the length.
    Space: O(1), since we do not use any extra space.
*/
