#include<iostream>
using namespace std;

void trapWater(int *arr,int n){

    if(n == 1){
        cout << "Meow" <<endl;
        return;
    }
    int currArea;
    int maxArea = INT16_MIN;
    int left = 0;
    int right = n-1;
    while(left < right){
        currArea = min(arr[left] ,arr[right])*(right-left);
        maxArea = max(currArea , maxArea);

        if(arr[left] > arr[right]){
            right--;
        }else{
            left++;
        }
    }
    cout << "Maximum area of trap water is "<<maxArea<<endl;
}

int main(){
    int arr[] = {1,4,3,2,5,2,5,3,1,9};
    int n = sizeof(arr)/sizeof(int);
    
    trapWater(arr ,n);
}