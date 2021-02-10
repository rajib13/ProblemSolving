class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        
        for(string token : tokens){
            if(token.size()  > 1  or isdigit(token[0])){
			numbers.push(stoi(token));
            } else {
                int oprnd1 = numbers.top(); numbers.pop();
                int oprnd2 = numbers.top(); numbers.pop();
                if("+" == token) numbers.push(oprnd1 + oprnd2);
                else if("-" == token) numbers.push(oprnd2 - oprnd1);
                else if("/" == token) numbers.push(oprnd2 / oprnd1);
                else numbers.push(oprnd2  * oprnd1);
            }
        }
        return numbers.top();
    }
};

/*
	Complexity analysis:
	Time: O(n), as we need to scan all tokens.
	Space: O(n), since we store the numbers in the stack.
*/
