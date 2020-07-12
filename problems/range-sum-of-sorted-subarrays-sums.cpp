#define MOD 1000000007
class Solution {
public:
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> subarray;
        
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                 subarray.push_back(sum);
            }
           
        }
        sort(subarray.begin(), subarray.end());
        int ret = 0;
        for(int i = left-1; i < right; i++){
            ret = (ret + subarray[i]) %  MOD;
        }
        return ret;
    }
};

/*Complexity analysis:
Time: O(n^2 logn), to find out all subarrays the algorithm requires O(n^2) time, and then we need to sort the new array of n^2 elements.
Space: O(n^2), as we need to store n*(n+1)/2 elements
*/
