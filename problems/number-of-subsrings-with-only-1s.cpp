
#define MOD 1e9+7
class Solution {
public:
    int numSub(string s) {
        int count = 0; 
        int res = 0;
        int mod = 1e9+7;
        for(char ch : s){
            count = ch == '1' ? count + 1 : 0;
            
            res = (res + count) % mod;
        }
        return res;
    }
};

/*
    Complexity analysis:
    Time: O(n), as we scan all characters of the given string once.
    Space: O(1), as we do not use any extra space.
*/
