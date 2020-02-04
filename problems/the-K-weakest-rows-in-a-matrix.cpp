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
