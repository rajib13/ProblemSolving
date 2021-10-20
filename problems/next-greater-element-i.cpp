class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        unordered_map<int, int> umap;
        for(int i = 0 ; i < nums2.size(); i++){
            while(!stack.empty() and nums2[i]  > stack.top()){
                umap[stack.top()] = nums2[i]; stack.pop(); // store the values of nums2 into map
            }
            stack.push(nums2[i]);
        }
        for(int i = 0 ; i < nums1.size(); i++){
            nums1[i] = umap[nums1[i]] == 0 ? -1 : umap[nums1[i]]; // we do not need another vector, we can reuse nums1. 
        }
    
        return nums1; 
    }
};

/*
    Complexity analysis:
    Time: O(m + n), where `m` and `n` are the length of the given arrays, as we need to scan every element of both arrays.
    Space: O(n), since we use stack and map to hold some information for later use.
*/
