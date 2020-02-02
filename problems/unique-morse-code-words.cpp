class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> ret;
        for(string word: words){
            string code = "";
            for(char ch : word){
                code += morse[ch - 'a'];
            }
            ret.insert(code);
        }
        return ret.size();
    }
};
