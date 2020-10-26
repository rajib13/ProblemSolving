class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxx = 0; 
        for(int i = 1; i < prices.size(); i ++){
            if(prices[i] > prices[i - 1]) maxx += prices[i] - prices[i-1];
        }
        return maxx; 
    }
};
/*
    Complexity Analysis:
    Time: O(n), since we need to scan all prices once.
    Space: O(1), as we did not use any extra space throughout the entrire program.
*/

/*  
Approach 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0; 
        int maxx = 0; 
        int buy = prices[0];
        for(int i = 1; i < prices.size(); i ++){
            if(buy > prices[i]) buy = prices[i];
            else {
                maxx += prices[i] - buy; 
                buy = prices[i]; 
            } 
        }
        return maxx; 
    }
};

*/
