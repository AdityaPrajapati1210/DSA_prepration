#include<iostream>
using namespace std;
void sortt(int *arr,int n){
    for(int i=0;i<n-1;i++){
       for(int j=i+1;j<n;j++){
        if(arr[i] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
       }
    }
}
int main(){
    int arr[] = {11,2,3,4,3};
    int n = sizeof(arr)/sizeof(int);
    sortt(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout <<endl;
}