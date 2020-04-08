class Solution {
public:
    int countElements(vector<int>& arr) {
        
        unordered_map<int, int> freq;
        int ret = 0;
        for(int num : arr){
            if(freq.count(num+1)) ret++; // general case
            if (!freq.count(num) and freq.count(num-1)) ret += freq[num-1]; // if num presents, then we counted num-1. 
            freq[num]++; // always add the num into the map.
        }
        
        return ret;
        
    }
};

/*
    Complexity Analysis:
    Time: O(n), as we need to go through all of the elements of the given array.
    Space: O(n), as we need to store all elements into the map.
*/


/*

Approach : Two pass solution.

class Solution {
public:
    int countElements(vector<int>& arr) {
        
        vector<int> freq(1001, 0);
        int maxx = 0;
        int ret = 0; 
        for(int i = 0; i < arr.size(); i++){
            freq[arr[i]]++;
            maxx = max(arr[i], maxx);
        }
        
        for(int i = 0; i < maxx; i++){
            if(freq[i]  > 0 and freq[i+1] > 0)
                ret += freq[i];
        }
        return ret;
        
    }
};*/
