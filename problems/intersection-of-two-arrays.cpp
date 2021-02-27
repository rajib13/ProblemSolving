class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> ret;
        
        for(int num : nums2){
            if(set.erase(num) > 0){ // find and erase in combine, returns 1 if the num could be deleted.
                ret.push_back(num);
            }
        }
        return ret;
    }
};

/*
    Time Complexity:
    Time: O(n), where `n` is the size of the largest length of two given arrays.
    Space: O(n), since we store the `nums1` into to the set.
*/
