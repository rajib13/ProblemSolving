class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        int charCount = INT_MAX;
        int i, j; 
        for(i = 0; i < strs.size() - 1; i++){
            for( j = 0; j < strs[i].size(); j++){
                if(strs[i][j] != strs[i+1][j]){
                    break;
                }
            }
            charCount = min(charCount, j);
        }
        
        return strs[0].substr(0, charCount); 
    }
};

/*
    Complexity analysis:
    Time: O(mn), where `m` is the array size and `n` is the longest word size.
    Space: O(1), since we do not use any extra space.
*/


        
