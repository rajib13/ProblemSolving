class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        
        vector<char> freq(54,0); // 0-25 is for lowercase and >= 26 is for uppercase letters.
        
        for(char ch : J){
            if(ch - 'a' < 0) freq[26 + ch-'A']++;
            else freq[ch - 'a']++;
        }
        
        int stones = 0;
        for(char ch : S){
            if(ch -'a' < 0){
                stones += freq[26 + ch-'A'];
            } 
            else{
                stones += freq[ch-'a'];
            }
        }
        return stones; 
        
    }
};

/*
Complexity Analysis:
Time: O(m+n), where m and n are the size of the jewels and stones, respectively.
Space: O(1), as our freq vector does not depend on the input size.
*/
