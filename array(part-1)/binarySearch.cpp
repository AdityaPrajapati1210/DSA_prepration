#include<iostream>
using namespace std;
 
int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(int);

    int left = 0;
    int right = n-1;
    int target = 8;
    int mid;
    bool found = false;
    while(left < right){
        mid = left + (right - left)/2;
        if(arr[mid] == target){
            cout << mid <<endl;
            found = true;
            break;
        }else if(arr[mid] >= target){
            right = mid-1;

        }else{
            left = mid+1;
        }
    }
    if(!found){
        cout <<"not found"<<endl;
    }
}