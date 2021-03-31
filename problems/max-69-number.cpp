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

/*
    Complexity analysis:
    Time: O(1), as the given number is an integer, the maximum length of the string could be 10.
    Space: O(1), since we do not use any extra space.
*/
