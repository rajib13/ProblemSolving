class Solution {
public:
    set<int> seen;
    bool canReach(vector<int>& arr, int start) {
        if(start >= arr.size() or start < 0 or seen.find(start) != seen.end()) return false; // Boundary cases
        seen.insert(start); // populate the seen container
        
        if(arr[start] == 0) return true; // success case
        return canReach(arr, start + arr[start]) or canReach(arr, start - arr[start]); // recursive call for two scenarios.
    }
};

/*
    Complexity analysis:
    Time: O(n), at best we we will visit an element twice.
    Space: O(n), since we need to keep track of the seen values.
*/
