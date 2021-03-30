class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& a) {
        sort(target.begin(), target.end());
        sort(a.begin(), a.end());
        
        return target == a; 
    }
};

/*
    Complexity analysis:
    Time:  O(nlogn), where `n` is the length of the given arrays.
    Space: O(1), since we do not use any extra space.
*/
