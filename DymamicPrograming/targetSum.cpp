#include<iostream>
#include<vector>
using namespace std;


bool targetSum(vector<int>nums,int n, int target){
    if(n >=  nums.size()){
        return false;
    }
    

    if(target == nums[n]) return true;
    if(target > nums[n]){
        if(targetSum(nums,n+1,target-nums[n])){
            return true;
        }
        if(targetSum(nums,n+1,target)){
            return true;
        }
    }else{
        if(targetSum(nums,n+1,target)){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int>nums= {2,3,7,8,10};
    int target = 11;

    cout << targetSum(nums,0,target);
}