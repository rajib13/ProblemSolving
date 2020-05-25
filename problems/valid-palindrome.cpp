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
Complexity Analysis:
Time: O(n), as we need to scan all chars of the given string at once.
Space: O(1), as we did not use any extra space. 
*/
