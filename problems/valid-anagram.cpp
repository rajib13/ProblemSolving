class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> ump;
        for(char ch : s)
            ump[ch]++;
        
        for(char ch : t){
            if(ump.find(ch) == ump.end() or ump[ch]-- <= 0) return false;
        }
        return true;
    }
};

/*
   Complexity analysis:
   Time: O(m + n), where `m` and `n` is the length of the st
*/
