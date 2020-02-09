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
"bab"
"aba"
"family"
"friend"
"leetcode"
"practice"
"anagram"
"mangaar"
"xxyyzz"
"xxyyzz"
"aba"
"bab"
"friend"
"family"
"practice"
"leetcode"
"mangaar"
"anagram"
"xxyyzz"
"xxyyzz"

*/
