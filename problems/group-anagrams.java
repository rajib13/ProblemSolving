class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        
        for(String str : strs){
            String curr = str;
            str = sortString(str);
            List<String> list = map.getOrDefault(str, new ArrayList<>());
            list.add(curr);
            map.put(str, list);
        }
        
        return new ArrayList<>(map.values());
    }
    
    private String sortString(String str){
        char[] freq = new char[26];
        for(char ch : str.toCharArray()){
            freq[ch - 'a']++;
        }
        String ret = String.valueOf(freq);
        return ret;
    }
}

/*
   Complexity analysis:
   Time: O(nk), where `n` is the length of the given `strs` and `k` is the maximum length of a string in `strs`.
   Space: O(nk), since we all strings in the `map`. 
*/
