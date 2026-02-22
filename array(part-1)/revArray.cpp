#include<iostream>
using namespace std;
 
int main(){
    int arr[] = {1 ,6,2,3,4};
    int n = sizeof(arr)/sizeof(int);

    int left = 0;
    int right = n-1;

    while(left < right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}