class Solution {
public:
    int minFlips(string t) {
      int count = t[0] - '0';
      for(int i = 1; i< t.size(); i++){
          if(t[i-1] != t[i]) count++;
      }
        return count;
    }
};


/*
Complexity analysis:
Time: O(n), as we need to scan all characters once.
Space: O(1), since we do not use any extra space.
*/
