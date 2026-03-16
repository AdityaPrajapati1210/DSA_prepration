#include<iostream>
#include<vector>
using namespace std;

void occur(int *arr,int n, int key,vector<int>ans){
    // base case
    if(n < 0){
        for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
        }
        return;
    }


    if(arr[n] == key){
        ans.insert(ans.begin(), n); 
        occur(arr , n-1,key,ans);
    }else{
        occur(arr , n-1,key,ans);
    }
}

int main(){
    int arr[] = {3 ,2,5,6,8,4,0,2,4,9,4,6,2,4,22,4,22,2,2,2};
    int key = 2;
    int n = sizeof(arr)/sizeof(int);
    vector<int>ans;
    occur(arr,n,key,ans);
    

    
}