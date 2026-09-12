#include<iostream>
#include<vector>
using namespace std;

int minPartition(vector<int>&nums,int W, int n){
    if(n == 0 || W == 0){
        return 0;
    }

    int take = 0;
    if(nums[n-1] <= W){
        take = nums[n-1] + minPartition(nums,W - nums[n-1], n-1);
    }
    int dontake = minPartition(nums,W,n-1);

    return max(take,dontake);
}


int main(){
    vector<int>nums = {1,6,11,5};
    int totalSum = 0;
    for(int i=0;i<nums.size();i++){
        totalSum+=nums[i];
    }
    int w = totalSum/2;
    // cout<<minPartition(nums,w,4)<<endl;

    int subset1 = minPartition(nums,w,4);
    int subset2 = totalSum - subset1;

    cout <<abs(subset1 - subset2)<<endl;
}