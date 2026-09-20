class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0;
        int sell = 0;
        int maxProfit = 0;
        while(sell < n){
            int profit = prices[sell] - prices[buy];
            maxProfit = max(profit , maxProfit);
            if(prices[buy] > prices[sell]){
                buy = sell;
            }
            sell++;
        }
        return maxProfit;
    }
};