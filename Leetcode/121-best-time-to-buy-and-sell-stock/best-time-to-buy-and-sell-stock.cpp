class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        if(n <= 1){
            return 0;
        }
        int maxProfit = 0;
        int buy = 0;
        int sell  =1;

        while (sell < n){
            maxProfit = max(maxProfit,(prices[sell] - prices[buy]));

            if(prices[buy] > prices[sell]){
                buy = sell;
            }

            sell++;
        }

        return maxProfit;
    }
};