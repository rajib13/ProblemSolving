class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ret(S.size(), INT_MAX);
        int last  = INT_MAX;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == C){ 
                ret[i] = 0; 
                last = i; 
            }
            else ret[i] = min(ret[i], abs(i-last)); 
        }
        last  = INT_MAX;
        for(int i = S.size() - 1; i >= 0; i--) {
            if(S[i] == C) last = i; 
            ret[i] = min(ret[i], abs(i-last)); 
        }
        
        return ret; 
    }
};

/*
    Complexity analysis: 
    Time : O(n), where `n` is the length of the given string, as we scan all characters of the strin `S` at least once.
    Space: O(n), since we use an extra vector of size of the given string.
*/
