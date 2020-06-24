class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> freq(26, 0);
        for(char ch : magazine)
            freq[ch -'a']++;
        for(char ch : ransomNote){
            if(freq[ch-'a']-- < 1) return false;
        }
        return true;
    }
};

/*Complexity Analysis:
Time: O(m+n), where m and n are the length of magazine and ransom note respectively.
Space: o(1), since we used only a vector of size 26.*/
