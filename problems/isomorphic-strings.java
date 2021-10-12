class Solution {
    public boolean isIsomorphic(String s, String t) {
        int n = s.length();
        int[] map1 = new int[256];
        int[] map2 = new int[256];
        
        Arrays.fill(map1, -1);
        Arrays.fill(map2, -1);
        
        for(int i = 0; i < n; i++){
            char chs = s.charAt(i);
            char cht = t.charAt(i);
            if(map1[chs] != map2[cht]) return false;
            
            map1[chs] = map2[cht] = i;
        }
        
        return true;
    }
}


/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given strings, as we need to scan every char of the two strings.
    Space: O(1), since in worst case the the maps will hold 26 characters each.
*/
