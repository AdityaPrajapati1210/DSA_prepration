#include<iostream>
using namespace std;

int main(){
    int arr[] = {2,2,1,1,1,1,1,2,2,3,2,1,2,4,6,1,2,4,2,66,2,1,2};
    int n = sizeof(arr) / sizeof(int);

    int count = 0;
    int majority;

    for(int i = 0; i < n; i++){
        if(count == 0){
            majority = arr[i];
        }

        if(arr[i] == majority){
            count++;
        }else{
            count--;
        }
    }

    cout << majority << endl;
}