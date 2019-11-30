class Solution {
public:
    int minAddToMakeValid(string str) {
                            
        int close = 0;  
        int open = 0; 
        for(char ch : str){
            if(ch == '(')
                open++;
            else{
                if(open == 0) close++; 
                else open--;
            }
        }
        return close + open;
        
    }
};
