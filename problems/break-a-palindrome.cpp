class Solution {
public:
    
    string breakPalindrome(string palindrome) {
        if(palindrome.size() < 2) return "";
       
        for(int i = 0; i < palindrome.size()/2; i++){
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    }
};

/*
    Complexity analysis:
    Time: O(n), where n is the length of the given `palindrome` string, as we need to scan n/2 characters.
    Space: O(1), since we do not use any extra space.
*/
