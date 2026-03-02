#include<iostream>
using namespace std;

int main(){
    int arr[] = {5,4,2,56,2,56,8,7,6,5,};
    int n = sizeof(arr)/sizeof(arr[0]);

    int freq[100000]; //freq count

    int minVal = INT_FAST16_MAX;
    int maxVal =INT_FAST16_MIN;

    for(int i=0;i<n;i++){
        minVal = min(arr[i] , minVal);
        maxVal = max(arr[i] , maxVal);
    }

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i= minVal,j=0;i<=maxVal;i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;

        }
    }

    // print array
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}