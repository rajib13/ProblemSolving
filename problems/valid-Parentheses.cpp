class Solution {
public:
    bool isValid(string s) {
        
        stack<char> openBrackets;
        
        for(char ch : s){
            switch (ch) {
                case '(': 
                case '{': 
                case '[': openBrackets.push(ch); break;
                case ')': if(openBrackets.empty() || openBrackets.top() != '(') return false; else openBrackets.pop(); break;
                case '}': if(openBrackets.empty() || openBrackets.top() != '{') return false; else openBrackets.pop(); break;
                case ']': if(openBrackets.empty() || openBrackets.top() != '[') return false; else openBrackets.pop(); break;
            default: ;
            }
        }
        
        return openBrackets.empty();
        
    }
};
