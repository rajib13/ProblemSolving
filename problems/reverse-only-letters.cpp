class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0; 
        int j = s.size() - 1;
        
        while(i < j){
            while(i < j and !isalpha(s[i])) i++;
            while(i < j and !isalpha(s[j])) j--;
            swap(s[i++], s[j--]);
        }
        
        return s;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the string, as we need to scan every character of the string.
    Space: O(1), since we do not use any extra space.
*/
