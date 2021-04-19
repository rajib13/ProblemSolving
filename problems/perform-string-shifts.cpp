class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shifts) {
        
        int count = 0; 
        for(vector<int> shift : shifts){
            count += shift[0] ? -shift[1] : shift[1];
        }
        count  %= int (s.size());
        if(count > 0){
            rotate(s.begin(), next(s.begin(), count), s.end());
        }
        else {
            rotate(s.rbegin(), next(s.rbegin(), -count), s.rend());
        }
        
        return s;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the size of the given shifts, as we need to scan every shift once.
    Space: O(1), as we do not use any extra space.
*/
