class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ret;
        int p1 = 0; 
        int p2 = 0; 
        while(p1 < nums1.size() and p2 < nums2.size()){
            if(nums1[p1] == nums2[p2] and (ret.empty() or ret.back() != nums1[p1])){
                ret.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if(nums1[p1] > nums2[p2]) p2++;
            else p1++;
        }
        return ret;
        
    }
};
