class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ret;
        if(A.size() == 0 or B.size() == 0) return ret;
        int i = 0, j = 0;
        int m = A.size(), n = B.size();
        
        while(i < m and j < n){
            int aStart = A[i][0], aEnd = A[i][1];
            int bStart = B[j][0], bEnd = B[j][1];
            
            int start = max(aStart, bStart);
            int end = min(aEnd, bEnd);
            if(start <= end) ret.push_back({start, end});
            
            if(aEnd  < bEnd) i++;
            else j++;
        }
        
        return ret;
    }
};

/*
    Complexity Analysis:
    Time: O(n), where `n` is the smallest list size between the given A and B.
    Space: O(1), as we did not use any extra space.
*/
