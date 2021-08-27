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
   Time: O(m + n), where `m` and `n` are the length of the first and second string lengths.
   Space: O(1), in worst case the hashmap will contain 26 keys.
*/
