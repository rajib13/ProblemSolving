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
            else arr = ret;
        }
        return ret;
    }
};

/*
	Complexity analysis:
	Time: O(n^2), since we need to traverse the arry multiple times.
	Space: O(n), as we need to use an auxilary vector.

*/
