class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; 
        int j = 0;
        
        while(j < t.size() and i < s.size()){
            if(t[j] == s[i]) i++;
            j++;
        }
        return i == s.size();
    }
};

/*
    Complexity Analysis:
    Time: O(n), where `n` is the lengtth of the logest string.
    Space: O(1), since we do not use any extra space.
*/
