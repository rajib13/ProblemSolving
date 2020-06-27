class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        int minn = INT_MAX, maxx = INT_MIN;
        for(int sal : salary){
            sum += sal;
            minn = min(minn, sal);
            maxx = max(maxx, sal);
        }
        return (sum-minn-maxx)/(salary.size()-2);
    }
};

/*Complexity analysis:
Time: O(n), as we need to scan all elements once.
Space: O(1), since we did not use any extra space.*/
