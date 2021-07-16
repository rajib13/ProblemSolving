class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ret;
        for(int i = 1; i < arr.size(); i++) {
            arr[i] = arr[i-1] ^ arr[i];
        }
        
        for(int i = 0 ; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            
            int val = left == 0 ? arr[right] : arr[left-1] ^ arr[right];
            ret.push_back(val);
        }
        
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(m + n), where `m` and `n` are the length of the given `arr` and `queries`, respectively. 
    Space: O(1), since we do not use any extra space.
*/
