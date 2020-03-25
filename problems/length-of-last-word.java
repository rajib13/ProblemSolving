class Solution {
    public int lengthOfLastWord(String s) {
        // As we are asked to find out the length of the last word, so it is best to iterate in reverse.
        int len = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s.charAt(i) == ' '){
                if(len != 0) return len; // to check the case when s =  "a "
            }
            else len++;
        }
        return len;
    }
}


