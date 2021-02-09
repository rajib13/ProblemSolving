class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int j = arr.size()  * 0.25;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == arr[i+j]) return arr[i];
        }
        return 0;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, since we need to scan 74% of elements in worst case.
    Space: O(1), as we do not use any extra space.
*/
