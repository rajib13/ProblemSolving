class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last1 = m - 1;
        int last2 = n - 1; 
        int finalSize = m + n - 1; 
        
        while(last2 >= 0){
            if(last1 >= 0 && nums1[last1] > nums2[last2]){
                nums1[finalSize--] = nums1[last1--];
            }
            else{
                nums1[finalSize--] =  nums2[last2--];
            }
            
        }
    }
};

/*
    Complexity Analysis:
    Time: O(m), where `m` is the size of nums1.
    Space: O(1), as we do not use any extra space.
*/

