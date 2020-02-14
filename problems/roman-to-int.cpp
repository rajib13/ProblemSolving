class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> exchange; // To map the map and integer number. 
        exchange['I'] = 1;
        exchange['V'] = 5;
        exchange['X'] = 10;
        exchange['L'] = 50;
        exchange['C'] = 100;
        exchange['D'] = 500;
        exchange['M'] = 1000;
        
        int ret = 0;
        for(int i = 0 ; i  < s.size(); i++){

            if(i+1 < s.size() and exchange[s[i]] < exchange[s[i+1]]) ret -= exchange[s[i]];
            else ret += exchange[s[i]];
    
        }
        return ret;
    }
};
