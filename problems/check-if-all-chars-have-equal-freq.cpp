class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> freq(26);
        
        for(char ch : s) freq[ch - 'a']++;
        int count = freq[s[0] - 'a'];
        
        for(int i : freq) {
            if(i > 0 and count != i) return false;
        }
        return true;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string, as we need to scan all chars of the given string at once.
    Space: O(1), since we the `freq` vector does not depend on the given string length, it has always the length 26.
*/
