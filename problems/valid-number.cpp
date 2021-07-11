class Solution {
public:
    bool isNumber(string str) {
        int state = 0;
        bool seenDigit = false;
        
        /*                    
         Deterministic Finite Automation (DFA) algorithm. 
        */

        /*First remove the trailling and tailing white spaces. */
        while(' ' == str[0]) str.erase(0, 1);
        while(' ' == str[str.size() - 1]) str.erase(str.size() - 1, 1); // The index of the str should be calculate every time. 

        for(char ch : str){
            if('0' <= ch and ch <= '9'){ // digit check
                seenDigit = true; // flag for exponential because e3 is not valid. So we need to get digits first.
               
                if(state <= 2) state = 2; 
                else state = state <= 5 ? 5 : 7;
            }
            else if('+' == ch or '-' == ch){ 
                if(state == 0 or state == 3) state++; 
                else return false;
            }
            else if('e' == ch){
                
                if(seenDigit and (state == 2 or state == 6 or state == 7)) state = 3;
                else return false;
            }
            else if('.' == ch){
                if(state <= 2) state = 6;
                else return false;
            }
            else return false; 
        }
        return state == 2 or state == 5 or (seenDigit and state == 6) or state == 7; // Any of the four final cases are fine. 
    }
};
