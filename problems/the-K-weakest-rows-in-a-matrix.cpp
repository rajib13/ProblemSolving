class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ret;
        set<pair<int, int>>set;
        
        for(int i = 0; i < mat.size(); i++){
            int soldiers = accumulate(mat[i].begin(), mat[i].end(), 0);
            set.insert({soldiers, i});
        }
        for (auto &elem : set){
            if(k-- == 0) break;
            ret.push_back(elem.second);
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(mn), where `m` and `n` are the number of rows and columns in the given matrix, as we need to iterate through tall of the rows.
    Space: O(n), since we use a set as an auxiliary space to store the sum of row.
*/
