class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        vector<pair<int, int>> vec;
        
        for(int num : nums)
            ump[num]++;
        
        for(auto it : ump){
            vec.push_back(make_pair(it.second, it.first));
        }
        sort(vec.begin(), vec.end());
        int count = 0;
        int sz = vec.size();
        for(int i = 0; i < sz ; i++){
            if(vec[i].first <= k){
                k -= vec[i].first;
                count++;
            }
            else break;
        }
        return sz - count;
    }
};

/*
Complexity analysis: 
Time: O(n logn), as we sorted the frequency of the given array elements. 
Space: O(n), since we used hashmap to store the frequency. 
*/
