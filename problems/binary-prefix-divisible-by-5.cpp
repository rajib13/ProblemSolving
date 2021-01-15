class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        int dec = 0;
        for(int i = 0 ; i < A.size(); i++){
            dec = (dec * 2 + A[i]) % 5;
            bool toPush = dec == 0 ? true : false;
            ret.push_back(toPush);
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), as we need to scan all elements in the given array.
    Space: O(1), since we did not use any extra space;
*/
