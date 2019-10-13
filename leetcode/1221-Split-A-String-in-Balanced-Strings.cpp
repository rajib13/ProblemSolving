class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int sum = 0;
        for(char ch : s){
            if(ch == 'R') sum++;
            else sum--;
            if(sum == 0) count++;
        }
        return count; 
    }
};
