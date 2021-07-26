class Solution {
    public boolean areOccurrencesEqual(String s) {
        int[] freq = new int[26];
        for(char ch : s.toCharArray()) freq[ch - 'a']++;
        int count = freq[s.charAt(0) - 'a'];
        
        for(int f : freq){
            if(f > 0 && count != f) return false;
        }
        return true;
    }
}

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string, as we need to scan all chars of the given string at once.
    Space: O(1), since we the `freq` vector does not depend on the given string length, it has always the length 26.
*/
