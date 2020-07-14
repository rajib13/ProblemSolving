class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int count = 0;
        unordered_map<int, int> ump;
        for(int num : nums){
            //cout << num <<" " << tmp << endl;
            count += ump[num]++;
        }
        return count;
    }
};

/*
Complexity Analysis:
Time: O(n), as we need to scan all array elements once.
Space: O(n), since we used map to store the frequence of every number. 
*/
