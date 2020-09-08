class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '?'){
                s[i] = 'a';
                if(i-1 >= 0 and s[i-1] == s[i]) s[i] = 'b';
                if(i+1 < s.size() and s[i+1] == s[i]) s[i] = 'c';
                }               
        }
        return s;
    }
};

/*
Complexity analysis:
Time:  O(n), as we scan all the chars once.
Space: O(1), since we did not use any extra space throughout the entire algorithm.
*/
