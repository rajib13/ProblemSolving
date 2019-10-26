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
