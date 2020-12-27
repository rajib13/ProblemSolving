class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int j = 0;
        for(int i = 1; i  <= n; i++){
            if(j == target.size()) break;
            ret.push_back("Push");
            if(target[j] == i) j++;
            else ret.push_back("Pop");
        }
        return ret;
    }
};

/*
    Complexity Analysis:
    Time: O(n), where n is the given integer.
    Space: O(1), as we did not use any extra space. 
*/
