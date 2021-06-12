class Solution {
public:
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1; 
        int high = 1e6;
        
        while(low <= high){
            int mid = (low + high)/2;
            
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
    Time: O(nlogn), where `n` is the length of the given nums, as we need to scan all elements once every time after discarding the half of the inputs.
    Space: O(1), since we do not use any extra space.
*/
