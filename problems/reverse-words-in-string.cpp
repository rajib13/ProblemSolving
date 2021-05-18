class Solution {
public:
    string reverseWords(string str) {
        string ret = "";
        string word = "";
        for(int i = str.size() - 1; i >= 0; i--){
            if(str[i] == ' '){
                if(word.size()){
                    reverse(word.begin(), word.end());
                    ret += word;
                    ret += " ";
                    word = "";
                }
            }
            else word += str[i];
        }
        reverse(word.begin(), word.end());
        if(word.size()) ret += word;
        if(ret[ret.size() - 1] == ' ')
            ret.erase(ret.size()-1);
    
        return ret; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string, since we traverse every char of the string from both side. 
    Space: O(n), as we need to use an auxilary space for the intermediate words. 
*/
