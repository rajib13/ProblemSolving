class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0; 
        int j = s.size()-1;
        
        while(i < j){
            if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else if(tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string, as we need to scan all chars of the given string at once.
    Space: O(1), since we do not use any extra space. 
*/
