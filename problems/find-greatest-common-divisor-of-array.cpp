class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m = INT_MAX, n = INT_MIN;
        for(int num : nums)
        {
            m = min(m, num);
            n = max(n, num);
        }
        
        return __gcd(m,n);
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given nums, as we need to scan every element to find the maximum and minimum. 
    Space: O(1), since we do not use and extra space.
*/
