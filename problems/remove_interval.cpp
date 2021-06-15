class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& in, vector<int>& t) {
        vector<vector<int>>  ret;
        for(int i = 0; i < in.size(); i++){
            if(in[i][0] < t[0]){
                ret.push_back({in[i][0], min(in[i][1], t[0])});
                if(in[i][1] > t[1]){
                    ret.push_back({t[1], in[i][1]});
                }
            } 
            else{
                if(in[i][0] > t[1]){
                    ret.push_back({in[i][0], in[i][1]});
                    
                }
                else{
                    if(in[i][1] > t[1]){
                        ret.push_back({t[1], in[i][1]});
                    }
                }
            }
            
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given intervals, as we need to scan every interval once.
    Space: O(1), since we do not use any additional space. 
*/
