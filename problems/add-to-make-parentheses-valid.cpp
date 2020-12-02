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

/*
    Complexity analysis:
    Time: O(n), where n is the length of the given string.
    space: O(1), since we did not use any extra space;
*/
