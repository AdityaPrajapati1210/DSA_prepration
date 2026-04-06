#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

int maximumAmount(vector<int>value,vector<int>weight,int w){
    vector<pair<int,float>>ratioSort(value.size());
    for(int i=0;i<value.size();i++){
        ratioSort[i].first = i;
        ratioSort[i].second = (float)value[i]/weight[i];
    }
    

    sort(ratioSort.begin(),ratioSort.end(),[](auto &a ,auto &b){
        return a.second > b.second;
    });

    int amount = 0;

    for(int i=0;i<value.size();i++){
        if(weight[ratioSort[i].first] <= w){
            amount += value[ratioSort[i].first];
            w = w - weight[ratioSort[i].first];
        }else{
            amount += w * ratioSort[i].second;
            return amount;
        }
    }

    return amount; 
}

int main(){
    vector<int>value = {100 , 100, 120};
    vector<int>weight = {20 , 10, 30};
    int w = 50;
    cout<<maximumAmount(value,weight,w)<<endl;
}