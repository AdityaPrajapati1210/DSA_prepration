#include<iostream>
using namespace std;

int main(){
    char arr[] = {'f','b','a','e','c','d'};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<n;i++){
       int curr = arr[i];
       int prev = i-1;
       while(prev >= 0 && arr[prev] < arr[prev +1]){
            swap(arr[prev] , arr[prev +1]);
            prev--;
       }
       curr = arr[prev+1];
    }
    // print array
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}