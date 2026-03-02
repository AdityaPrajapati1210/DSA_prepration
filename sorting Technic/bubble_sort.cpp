#include<iostream>
using namespace std;

int main(){
    int arr[] = {5,4,2,56,2,56,8,7,6,5,};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
    // print array
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}