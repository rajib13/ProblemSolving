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

/*
    Complexity analysis: 
    Time: O(m*n), where `m` and `n` are the number of words and the length of the longest word, respectively, 
          as we need scan every character of every given word.
    Space: O(1), since we do not use any extra space
*/
