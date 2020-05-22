class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int q) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]<= q and e[i] >= q) count++;
        }
        return count;
    }
};

/*
Complexity Analysis:
Time: O(n), where n is the length of the given vectors.
Space: O(1), as we are not using any extra space.
*/
