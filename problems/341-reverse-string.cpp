class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        if(length > 0){
            for(int i = 0; i <= length/2; i++){
                swap(s[i], s[length-i-1]); 
            }
        }

    }
};
