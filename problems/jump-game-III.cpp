class Solution {
public:
    set<int> seen; // To track the visited node so that we do not fall in loop or TLE. 
    
    bool canReach(vector<int>& arr, int start) {
        if(start >= arr.size() or start < 0 or seen.find(start) != seen.end()) return false; // Boundary cases
        seen.insert(start); // populate the seen container
        
        if(arr[start] == 0) return true; // success case
        eturn canReach(arr, start + arr[start]) or canReach(arr, start - arr[start]); // recursive call for two scenarios.
    }
        
};

