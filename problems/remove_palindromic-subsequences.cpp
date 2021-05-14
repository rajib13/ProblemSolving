class Solution {
public:
    int removePalindromeSub(string str) {
        if(str.size() == 0) return 0;
        // idea: if the given string is already palindrome then we can delete it in 1 step. 
        // If it is not palindrome, and as we are given there will be only two characters, that means
        // in first iteration, we can delete all 'a's and in second step we will delete all 'b's, because 
        // we need to delete subsequence not the substrings. 
        string temp = str;
        reverse(str.begin(), str.end());
        return temp == str ? 1 : 2;
        
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given `str`, as we need to reverse the string.
    Space: O(1), since we do not use any extra space.
*/
