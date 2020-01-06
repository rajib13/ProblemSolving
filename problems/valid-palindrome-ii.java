class Solution {
    public boolean isPalindrome(String s, int count, int p1, int p2){
        /*Approach : For any mismatch, we should delete either p1 or p2. As a result we get two substrings and 
        it is enough to check whether either of these is palindrom or not. MOMENT OF PROUD.*/
        
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

"aba"
"abda"
"abcda"
"abcd"
"abcdcaa"
"deeee"
"dedee"
"eeeed"
"eeeeedd"
*/
