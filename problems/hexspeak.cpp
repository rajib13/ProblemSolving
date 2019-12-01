class Solution {
public:
    
    
    string longTohex(long num){
        stringstream ss;
        ss<< hex << uppercase << num; //decimal value to uppercase hexadecimal value. 
        return (ss.str());
    }
    
    string toHexspeak(string num) {
        
        long  dec_num = stol(num); // string to long
        
        string hex = longTohex(dec_num);
        
        for(int i = 0 ; i < hex.size(); i++){
            if(hex[i] == '0') hex[i] = 'O';
            if(hex[i] == '1') hex[i] = 'I';
            if(hex[i] > '1' and hex[i] <= '9') return "ERROR";
        }
        
        return hex;
    }
};
