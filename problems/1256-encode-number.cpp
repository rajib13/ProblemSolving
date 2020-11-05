class Solution {
public:
    string encode(int n) {
        string ret = "";
        
        string binaryString = "10"; 
        int num = n; // store the given 'n' for the later use.
        while(num > 0){ // decimal to binary conversion.
            ret +=  binaryString[num % 2];
            num = (num - 1) /2;
        }
        reverse(ret.begin(), ret.end());
        return n == 0 ? "" : ret;
    }
};

