class Solution {
public:
    int maxPower(string s) {
        int maxx = 1;
        int count = 1; 
        for(int i = 0; i  < s.size() - 1; i++){
            count = s[i] == s[i+1] ?  ++count : 1;
            maxx = max(count, maxx);
        }
        return maxx;
    }
};

/*
    Complexity analysis:
    Time: O(n), where 'n' is the length of the given string, as we need to scan every char of the string 's';
    Space: O(1), since we do not use any extra space;
*/
