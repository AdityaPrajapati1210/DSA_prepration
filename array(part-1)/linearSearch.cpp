#include<iostream>
using namespace std;
 
int main(){
    int arr[] = {1 ,6,2,3,3,4,4,5,5,4,1,2,5,5,5,5,52,7,6,2,5,565};
    int n = sizeof(arr)/sizeof(int);
    int target = 455;
    bool found = false;
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            cout << i <<endl;
            found = true;
            break;
        }

    }
    if(!found){
        cout <<"not found"<<endl;
    }
    return 0;


}