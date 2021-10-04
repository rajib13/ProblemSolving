class Solution {
public:
    int minimumMoves(string s) {
        int count = 0;
        int i = 0;
        
        while(i < s.size()){
            if(s[i] == 'O') i++;
            else {
                count++;
                i += 3;
            }
        }
        return count;
    }
};


/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string, as we need to scan every element.
    Space: O(1), since we do not use any extra space. 
*/
