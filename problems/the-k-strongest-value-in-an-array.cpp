class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> ret;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n-1)/2];
        
        int i = 0; 
        int j = n - 1;
        while(--k >= 0){
            int left = abs(arr[i] - m);
            int right = abs(arr[j] - m);
            
            if(left <= right) ret.push_back(arr[j--]);
            else ret.push_back(arr[i++]);
        }
        
        return ret;
    }
};

/*Complexity Analysis: 
Time: O(n logn), where n is the total elements in the given array.
Space: O(logn), for the sorting algorithm.*/
