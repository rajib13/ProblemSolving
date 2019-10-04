
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
Test Cases: 

[2,0,0,0,0,0]
1
[1]
1
[1,2,3,0,0,0]
3
[2,5,6]
3
[1]
1
[]
0
[0]
0
[1]
1
[0,0,0,0,0]
0
[1,2,3,4,5]
5
[0,0,3,0,0,0,0,0,0]
3
[-1,1,1,1,2,3]
6
[0,0,3,0,0]
3
[-100,2]
2

*/
