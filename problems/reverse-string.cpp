class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j)
            swap(s[i++], s[j--]);
    }
};

/*Complexity Analysis:
Time: O(n), where n is the length of the given string.
Space: O(1), we reversed the string in place.*/
