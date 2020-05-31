class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& a) {
        
        sort(target.begin(), target.end());
        sort(a.begin(), a.end());
        
        
        
        return target == a; 
    }
};
