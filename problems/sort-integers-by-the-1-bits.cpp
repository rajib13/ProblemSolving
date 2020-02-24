class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ret; 
        multiset<pair<int, int>> s;
        for(int i = 0; i < arr.size(); i++){
            bitset<32> n = bitset<32> (arr[i]);
            int tmp = n.count();
            s.insert(make_pair(tmp, arr[i]));
        }
        for(auto elem : s){
            ret.push_back(elem.second);
        }
        return ret;
        
    }
};
