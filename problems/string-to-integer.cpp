class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        int state = 0; 
        bool sign = false;
	/*Approach: DFA, similar to 65. Valid number.*/
        
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
