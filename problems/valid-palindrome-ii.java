class Solution {
    public boolean isPalindrome(String s, int count, int p1, int p2){
        while(p1 < p2){
            if(s.charAt(p1) != s.charAt(p2)){
                if(count  > 0) return false;
                return isPalindrome(s, count + 1, p1, p2-1) || isPalindrome(s, count + 1, p1+1, p2);
            }
            p1++; p2--;
        }
      return true;
    }
    
    public boolean validPalindrome(String s) {
        int p1 = 0; 
        int p2 = s.length() - 1;
        
        return isPalindrome(s, 0, p1, p2);
    }
}

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string, as we need to scan every character of the string.
    Space: O1n), since we do not use any extra space.
*/
