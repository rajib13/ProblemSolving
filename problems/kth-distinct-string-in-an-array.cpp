class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        
        for(auto str : arr) map[str]++;
        
        for(auto str : arr){
            if(map[str] == 1 and --k == 0) return str;
        }
        return "";
    }
};


/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string array, as we need to scan every string.
    Space: O(n), since we store the count of every string in the map.
*/
