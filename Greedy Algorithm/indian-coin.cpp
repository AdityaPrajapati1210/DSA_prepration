#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[] = {1,2,5,10,20,50,100,500,2000};
    int i = 9-1;
    int v = 2678;
    int ans = 0;
    while(v != 0){
        if(arr[i] <= v){
            ans++;
            v= v-arr[i];
        }else{
            i--;
        }
    }
    cout << ans <<endl;
}