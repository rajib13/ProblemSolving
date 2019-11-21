class Solution {
public:
/*Approach 2 : Simplified version of the approach 1.*/
    string encode(int n) {
        string ret = "";
        
        string binaryString = "10"; 
        int num = n; // store the given n for the later use.
        while(num > 0){ // decimal to binary conversion.
            ret +=  binaryString[num%2];
            num = (num - 1) /2;
        }
        reverse(ret.begin(), ret.end());
        return n == 0 ? "" : ret;
        
    }
};

/*
Approach 1: General intuition. 100% and 100%
class Solution {
public:

    string encode(int num) {
        if(num == 0) return ""; // edge case
        string ret = "";
        
        int digit = log10(num)/log10(2); // find out the digits in binary of the num
        if(num == pow(2,digit+1) - 1){ // special case, 7 == 000
            for(int i = 0 ; i < digit+1; i++){
                ret+= "0";
            }
            return ret;
        }
        
        num = num - pow(2,digit) + 1; // Get the number that needs to be converted into binary.
        
        string convertString = "01"; 
        while(num > 0){
            ret +=  convertString[num%2];
            num = num /2;
        }
        if(ret.size() != digit){
            for(int i = ret.size(); i < digit;i++){
                ret+= "0";
            }
        }
        reverse(ret.begin(), ret.end()); // Finally reverse the string to get the actual 
        return ret;
        
    }
};


*/
