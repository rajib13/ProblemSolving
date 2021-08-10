class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string ret = "";
        
        while(i >= 0 or j >= 0 or carry){
            int sum = carry;
            if(i >= 0) sum += (num1[i--] - '0');
            if(j >= 0) sum += (num2[j--] - '0');
            ret += to_string(sum % 10);
            carry = sum/10;        
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/*
    Compleixty analysis:
    Time: O(m + n), where `m` and `n` are the length of the given strings, as we need to scan all characters once.
    Space: O(1), since we do not use any extra space.  
*/
