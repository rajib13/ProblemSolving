class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<int> trusts(N+1, 0);
        vector<int> trustee(N+1, 0);
        
        for(int i = 0; i < trust.size(); i++){
            trustee[trust[i][0]]++;
            trusts[trust[i][1]]++;
        }
        
        for(int i = 1; i <= N; i++){
            if(trusts[i] == N - 1 and trustee[i] == 0) return i;
        }
        return -1;
        
    }
};
