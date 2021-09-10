class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long shift = 0;
        
        for(int i = shifts.size() - 1; i >= 0; i--){
            shift += shifts[i];
            int tmp  = (shift + s[i] - 'a') % 26;
            s[i] = (tmp + 'a');
            
        }
        return s;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the shifts, as we need to scan every element.
    Space: O(1), since we do not use any extra space.
*/
