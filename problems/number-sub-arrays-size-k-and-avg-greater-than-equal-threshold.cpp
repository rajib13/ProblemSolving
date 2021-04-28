class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        /* Approach: Sliding window (a and b) algorithm. 
         Although it was not mentioned explicitly, by sub-array it means the continouous subarray. */
        
        int a = 0,  b = 0;
        int sum = 0, count = 0;
        int n = arr.size();
        
        while(i <= n - k){
            sum += arr[j++];
            if(j >= k){
                int avg = sum/k;
                if(avg >= threshold) count++;
                sum -= arr[i++];
            }
        }
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the size of the given arry, as we need to scan every element of the array.
    Space: O(1), as we do not use any extra space.
*/
