class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(char ch : s){
            if(ch == '(') brackets.push(')');
            else if(ch == '{') brackets.push('}');
            else if(ch == '[') brackets.push(']');
            else if(brackets.empty() or brackets.top() != ch) return false;
            else brackets.pop();
        }
        return brackets.empty();
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string, as we need to scan every character of the string.
    Space: O(n), in worst case we need to store all characters in the stack. 
*/
