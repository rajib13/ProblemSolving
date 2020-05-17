class Solution {
public:
    int maxPower(string s) {
        int maxx = 1;
        int count = 1; 
        for(int i = 0; i  < s.size()-1; i++){
            count = s[i] == s[i+1] ?  ++count : 1;
            maxx = max(count, maxx);
        }
        return maxx;
    }
};
