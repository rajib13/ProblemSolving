class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sump;
        unordered_map<char, char> tump;
        char ch = 'a';
        for(int i = 0; i < s.size(); i++){
            if(sump.find(s[i]) != sump.end()){
                if(tump.find(t[i]) == tump.end()) 
                    return false; 
                else {
                    s[i] = sump[s[i]];
                    t[i] = tump[t[i]];
                }
            } else {
                if(tump.find(t[i]) != tump.end()) return false;
                sump[s[i]] = ch;
                tump[t[i]] = ch;
                s[i] = ch;
                t[i] = ch++;
            }
            
        }
        
        return s == t;
    }
};


/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given strings, as we need to scan every char of the two strings.
    Space: O(1), since in worst case the the maps will hold 26 characters each.
*/
