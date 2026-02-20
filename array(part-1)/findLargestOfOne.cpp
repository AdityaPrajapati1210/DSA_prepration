#include<iostream>
using namespace std;

int main(){
    int arr[] = { 4 ,484,13,4, 55 ,5654,1,64,9,1,4};
    int ans = -9999999;
    int n =sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        ans = max(arr[i] ,ans);
    }
    cout << ans <<endl;
}