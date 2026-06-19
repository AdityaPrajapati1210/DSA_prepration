// // Connect N rope with min cost ,cost of 2 rope = sum of their length
// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

//     int minCost(vector<int>& arr) {
//         // code here
//         priority_queue<int,vector<int>,greater<int>>pq;
        
//         for(int i=0;i<arr.size();i++){
//             pq.push(arr[i]);
//         }
        
//         //
//         int cost = 0;
//         while(pq.size() > 1){
//             int temp1 = pq.top();
//             pq.pop();
//             int temp2 = pq.top();
//             pq.pop();
//             cost += temp1 + temp2;
//             pq.push(temp1+temp2);
//         }
        
//         return cost;
        
//     }

// int main(){
//     vector<int>ropelength = {4,3,2,6};

//     cout << minCost(ropelength)<<endl;


// }


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minCost(vector<int>vec){
    int n = vec.size();

    priority_queue<int ,vector<int>, greater<int>>pq;

    for(int i=0;i<n;i++){
        pq.push(vec[i]);
    }

    int cost = 0;
    while(pq.size() > 1){
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();
        pq.push(temp1 + temp2);
        cost +=  temp1+temp2;
    }

    return cost;


};

int main(){
    vector<int>ropelength = {4,3,2,6};

    cout << minCost(ropelength)<<endl;


}