class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size(); // determine the size of the given string.
        if(length > 0){ // crucial because of the empty string.
            for(int i = 0; i <= length/2; i++){ // As we are going to use two pointers from the beginning and the end, it is sufficient to check untill half of the string length.
                swap(s[i], s[length-i-1]); // length-- is not work, becuase in for loop we determine the limit i every time.  
            }
        }

    }
};
