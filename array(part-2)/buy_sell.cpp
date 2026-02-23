#include<iostream>
using namespace std;

void buy_sell(int *prices,int n){
    int buy = 0;
    int profit;
    int maxProfit = INT16_MIN;
    int daybuy;
    int daysell;
    for(int sell = 1;sell<n;sell++){
        profit = prices[sell] - prices[buy];
        if(profit > maxProfit){
            maxProfit = profit;;
            daybuy = buy;
            daysell = sell;
        }


        if(prices[buy] > prices[sell]){
            buy = sell;
        }

    }

    cout <<"Day buy : " <<daybuy+1<<endl<<"Day Sell : "<<daysell+1 <<endl;
}

int main(){
    int prices[] = {4 , 4,5,3,7,9,1,9,3,2,1,5,7,13};
    int n = sizeof(prices)/sizeof(int);

    buy_sell(prices,n);
}