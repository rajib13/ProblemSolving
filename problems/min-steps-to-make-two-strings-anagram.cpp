class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> freq(26, 0);
        
        for(char ch : s)
            freq[ch - 'a']++;
        
        for(int ch : t)
            freq[ch-'a']--;  
        
        
        int count = 0;
        for(int i = 0; i < 26; i++)
            if(freq[i] > 0) count += freq[i];
        
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the string, as we need to scan every char of both of the string.
    Space: O(1), since we do not use any extra space.
*/
