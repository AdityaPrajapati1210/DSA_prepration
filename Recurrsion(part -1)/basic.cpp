#include<iostream>
using namespace std;

void print(int *arr ,int n){
    static int i=0;
    if(i >= n) return;
    cout<<arr[i++]<<" ";
    print(arr,n);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,0};

    print(arr,10);

}