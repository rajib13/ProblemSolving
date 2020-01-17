class Solution {
public:
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1; 
        int high = 1e6; // maximum possible length
        
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


/*Solution 1:
The obvious solution is, we choose divisor starting from 1 and when first time we will get sum <= t, we return the divisor. The runtime is O(n^2) but the nums.size() > 10^4
So, it will not be accepted.

idea: As in worst case the nums length could be more than 10^4, so if we can reduce it to 10^3 then we can use O(n^2) solution. We increase our divisor by 100. Whenever we get 
sum <= t, we start calculating sum for last 100 divisor like egg dropping problem. 

class Solution {
public:
    int helper(int l, int h, int d, vector<int>& nums, int t){
        int i;
        for( i = l; l < h; i+=d){
            int sum = 0; 
            for(int j = 0; j < nums.size(); j++){
                int temp = nums[j]/i;
                sum += temp*i == nums[j] ? temp : temp + 1;
                if(sum > t) break;
            }
            if(sum <= t) return i;
        }
        return i;
    }
    
    int smallestDivisor(vector<int>& nums, int t) {
        
        int temp = helper(1, INT_MAX, 100, nums, t); 

        return temp < 100 ? temp : helper(temp - 100, temp+1, 1, nums, t);
    }
};

*/
