class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0;
        int sell = 0;
        int maxProfit = 0;
        while(sell < n){
            if((prices[sell] - prices[buy]) > 0){
                maxProfit += (prices[sell] - prices[buy]);
            }

            buy = sell;
            sell++;
        }
        return maxProfit;
    }
};