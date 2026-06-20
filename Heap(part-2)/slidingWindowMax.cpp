#include<iostream>
#include<queue>
#include<vector>
using namespace std;


struct compare{
    bool operator()(pair<int,int> &a, pair<int ,int> &b){
        return a.first < b.first;
    }
};


vector<int> maxSlide(vector<int>nums,int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
    vector<int>ans;

    for(int i=0;i<k;i++){
        pq.push(make_pair(nums[i] ,i));
    }
    ans.push_back(pq.top().first);

    for(int i=k;i<nums.size();i++){
        while(pq.top().second <= i-k){
            pq.pop();
        }
        pq.push(make_pair(nums[i] ,i));
        ans.push_back(pq.top().first);
    }
    return ans;

}


int main(){
    vector<int>nums = { 1,3,-1,-3,5,2,5,3,1,5,8,-1};
    int k = 3;
    vector<int>ans = maxSlide(nums,k);
    

    // print the vector

    int sum  =0;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
        sum += ans[i];
    }
    cout<<endl<<sum<<endl;
}