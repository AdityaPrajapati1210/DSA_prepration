#include<iostream>
using namespace std;

int main(){
    int m=3,n=3,target =6;
    int arr[m][n] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int low = 0;
    int high = n*m-1;

    while(low <= high){
        int mid = low + (high - low)/2;

        int row = mid/m;
        int col = mid%n;

        if(arr[row][col] == target){
            cout << row << " : "<< col<<endl;
            return 0;
        }else if(arr[row][col] > target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << "!Present"<<endl;

    


}