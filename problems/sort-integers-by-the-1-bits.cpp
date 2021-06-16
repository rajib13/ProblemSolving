class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ret; 
        multiset<pair<int, int>> mset;
        for(int i = 0; i < arr.size(); i++){
            bitset<32> n = bitset<32> (arr[i]);
            int tmp = n.count();
            mset.insert(make_pair(tmp, arr[i]));
        }
        for(auto elem : mset){
            ret.push_back(elem.second);
        }
        return ret;
        
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given `arr`, as we traverse the entire array once.
    Space: O(n), since we use the multiset to store the bit count as an additional space. 
*/
