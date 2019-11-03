
/*

Given an initial array arr, every day you produce a new array using the array of the previous day.

On the i-th day, you do the following operations on the array of day i-1 to produce the array of day i:

	1. If an element is smaller than both its left neighbor and its right neighbor, then this element is incremented.
	2. If an element is bigger than both its left neighbor and its right neighbor, then this element is decremented.
	3. The first and last elements never change.
After some days, the array does not change. Return that final array.

*/


class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        vector<int> ret = arr;
    
        while(1){
            int count = 0;
            for(int i = 1; i < arr.size() - 1; i++){
                if(arr[i] < arr[i-1] and arr[i] < arr[i+1]){ ret[i]++; count++;}
                else if(arr[i] > arr[i-1] and arr[i] > arr[i+1]) {ret[i]--; count++;}
               
            }
            if(count == 0) break;
            arr = ret;
            
        }
    return ret;
        
        
    }
};
