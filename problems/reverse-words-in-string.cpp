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
Test Cases: 

"the sky is blue"
"  hello world!  "
"asdfasdfa"
"   asdfas"
""
"12347891273412743"
"!@#$%^&*("

*/
