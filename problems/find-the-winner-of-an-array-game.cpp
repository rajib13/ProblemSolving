class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int count = 0;
        int curr = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > curr){
                count = 0;
                curr = arr[i];
            }
            if(++count == k) break;
        }
        return curr;
        
    }
};


/*
Complexity analysis:
Time: O(n), as we need to scan all elements of the given array once.
Space: O(1), since we did not use any extra space throughout the entire program.
*/
