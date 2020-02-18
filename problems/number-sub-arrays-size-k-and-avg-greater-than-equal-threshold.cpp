class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        /* Approach: Sliding window (a and b) algorithm. 
         Although it was not mentioned explicitly, by sub-array it means the continouous subarray. */
        
        int a = 0;
        int b = 0;
        int sum = 0;
        int count = 0;
        int n = arr.size();
        
        while(a <= n - k){
            sum += arr[b++];
            if(b >= k){
                int avg = sum/k;
                if(avg >= threshold) count++;
                sum -= arr[a++];
            }
        }
        return count;
    }
};
