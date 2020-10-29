class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0) return 0;
        int sum = duration; 
        for(int i = 1; i < timeSeries.size(); i++){
            sum += min(timeSeries[i] - timeSeries[i-1], duration);
        }
        return sum;
    }
};

/*
    Complexity analysis:
    Time: O(n), as we need to scan all elements once.
    Space: O(1), since we did not use any extra space.
*/
