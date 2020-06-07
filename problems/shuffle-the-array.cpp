class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret;
        for(int i = 0; i < n; i++){
            ret.push_back(nums[i]):
	    ret.push_back(num[i+n]);
        }
        return ret;
    }
};

/*Complexity Analysis:
Time : O(n), where n is the number of elements in the given array.
Space: O(1), since we did not use any extra space.
*/
