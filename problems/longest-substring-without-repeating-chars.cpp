class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        /*Approach: Two pointers search. second pointer will always increase by 1 and the first pointer will 
        increase by the position we have seen the char before. As array starts with 0, we need to add extra one.*/
        if(s.size() < 2) return s.size();
        
        unordered_map<char, int> chars;
        
        int maxx = INT_MIN;
        int i = 0; // first pointer
        for(int j = 0; j < s.size(); j++){ // j = 2nd pointer
            if(chars.count(s[j])){
                i = max(i, chars[s[j]] + 1);
            }
            maxx = max(maxx, j - i + 1);
            cout << maxx << " " << i << endl;
            chars[s[j]] = j;
        }
        
        return maxx;
        
    }
};

/*
"abcabcbb"
"pwwkew"
"bbbbb"
"        "
" "
"dvdf"
"abccbabacd"
*/
