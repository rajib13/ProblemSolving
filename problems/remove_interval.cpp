class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& in, vector<int>& t) {
        
        vector<vector<int>>  ret;
        for(int i = 0; i<in.size(); i++){
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
Test Cases:
[[0,2],[3,4],[5,7]]
[1,6]
[[0,5]]
[2,3]
[[0,5]]
[0,0]
[[0,5],[6,7],[8,10]]
[5,10]
[[0,5]]
[0,5]
[[8,9]]
[0,4]
[[-5,-4],[-3,-2],[1,2],[3,5],[8,9]]
[-1,4]
*/
