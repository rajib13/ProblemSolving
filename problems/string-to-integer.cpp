class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        int state = 0; 
        bool sign = false;
        
        for(char ch : str){
            
            if(state < 2 and ch == ' ') state = 1;
            else if(state < 2 and (ch == '-' or ch == '+')){
                if(ch == '-') sign = true;
                state = 2;
            }
            else if(ch >= '0' and ch <= '9') {
                long tmp = long(ret) * 10;
                tmp += sign ? '0' - ch : ch - '0'; 
        
                if(tmp >= INT_MAX) return INT_MAX;
                else if(tmp <= INT_MIN) return INT_MIN;
                else ret = tmp;
                state = 2; 
            }
            else {
               break; // state 3, terminating state. 
            }
        }
        
        return ret; 
    }
};

/*

"42"
"   -42"
"4193 with words"
"words and 987"
"-91283472332"
""
"+"
"-"
"--123"
"+-123"
"- 123"
"+ words"
"- words"
"12-23"
"-12-23"
"123 456"
"-+1"
"2147483646"
"-2147483648"
"-2147483649"
"-2147483647"
"2147483647"
"2147483648"
*/
