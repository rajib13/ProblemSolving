class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int R = 0;
        for(char ch : s){
            if(ch == 'R') R++;
            else R--;
            if(R == 0) count++;
        }
        return count; 
    }
};
