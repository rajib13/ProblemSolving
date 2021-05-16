class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j)
            swap(s[i++], s[j--]);
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given string, since we traverse every char of the string from both side. 
    Space: O(1), as we reversed the string in place.
*/
