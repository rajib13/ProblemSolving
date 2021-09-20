class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        
        for(int num : nums){
            int diff1 = num - k;
            int diff2 = k + num;
            if(map.find(diff1) != map.end()) {
                count += map[diff1];
            }
            if(map.find(diff2) != map.end()) {
                count += map[diff2];
            }
            map[num]++;
        }
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given nums, as we need to scan every element of the array.
    Space: O(n), since we need to store the element in the map.
*/
