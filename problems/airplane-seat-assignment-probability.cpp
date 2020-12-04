class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1.0 : 0.5;
    }
};

/*
    Complexity analysis:
    Time: O(1), since the result does not depend on how big the n is!
    Space: O(1), as we did not use any extra space.
*/
