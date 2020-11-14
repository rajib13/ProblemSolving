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
    Time: O(n), where n is the length of the given string.
    Space: O(1), since we did not use any extra space. 
*/
