// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0; 
        int high = n;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isBadVersion(mid)) high = mid;
            else low = mid + 1;
        }
        return low; 
    }
};

/* 
    Complexity analysis: 
    Time: O(logn), as we reduce the search space by half every time.
    Space: O(1), as we do not use any extra space.
*/
