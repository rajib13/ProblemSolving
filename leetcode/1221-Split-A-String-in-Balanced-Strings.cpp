class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int sum = 0;
        for(char ch : s){
            sum += ch == 'R' ? 1 : -1;
            if(sum == 0) count++;
        }
        return count; 
    }
};
