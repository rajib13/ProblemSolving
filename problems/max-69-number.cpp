class Solution {
public:
    int maximum69Number (int num) {
        
        string str = to_string(num);
        int ret = 0; 
        bool flag = true;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '6' and flag == true){
                str[i] = '9';
            }
            ret = ret * 10 + str[i]-'0';
        }
        return ret; 
    }
};
