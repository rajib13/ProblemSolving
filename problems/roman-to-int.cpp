class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> exchange; // To map the roman and integer number. 
        exchange['I'] = 1;
        exchange['V'] = 5;
        exchange['X'] = 10;
        exchange['L'] = 50;
        exchange['C'] = 100;
        exchange['D'] = 500;
        exchange['M'] = 1000;
        
        int ret = 0;
        for(int i = 0 ; i  < s.size() - 1; i++){
            if(i+1 < s.size() and exchange[s[i]] < exchange[s[i+1]]) ret -= exchange[s[i]]; // Only if the next number is greater than the current number then we need to deduct it from the sum.
            else ret += exchange[s[i]];
    
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string, as we need scan every element of the nums once.
    Space: o(1), since we used only a vector of size 26.
*/
