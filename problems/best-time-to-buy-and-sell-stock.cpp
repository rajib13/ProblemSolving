class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int maxProfit = 0;
        int buy =  prices[0];
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            else{
                maxProfit = max(maxProfit, prices[i] - buy);
            }
        }
        return maxProfit; 
        
    }
};

/*
Complexity Analysis:
Time: O(n), where 'n' is the number of elements of the given array.
Space: O(1), as we do not use any extra space.
*/
