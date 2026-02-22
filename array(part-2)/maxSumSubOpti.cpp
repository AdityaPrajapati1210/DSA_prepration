#include<iostream>
using namespace std;

int main(){
    int arr[] = {1 ,5, -2 ,3 ,3,-4};
    int n = sizeof(arr)/sizeof(int);
    int currSum = 0;
    int maxSum = INT16_MIN;
    for(int i=0;i<n;i++){
        currSum = max(currSum+arr[i], arr[i]);
        maxSum = max(currSum ,maxSum);
    }
    cout << maxSum << endl;
}