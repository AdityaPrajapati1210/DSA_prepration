#include<iostream>
using namespace std;

int main(){
    int arr[] = {5,4,2,56,2,56,8,7,6,5,};
    int n = sizeof(arr)/sizeof(arr[0]);

    int minn = INT_FAST16_MAX;
    for(int i=0;i<n;i++){
        int minInd= i;
        for(int j=i;j<n;j++){
            if(arr[j] < arr[minInd]){
                minInd = j;
            }
        }
        swap(arr[i] ,arr[minInd]);
    }
    // print array
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}