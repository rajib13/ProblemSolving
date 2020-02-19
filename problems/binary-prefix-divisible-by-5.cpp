class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        
        vector<bool> ret;
        int dec = 0;
        for(int i = 0 ; i < A.size(); i++){
            dec = (dec * 2 + A[i]) % 5;
            cout << dec <<" ";
            if(dec == 0) ret.push_back(true);
            else ret.push_back(false);
        }
        return ret;
    }
};
