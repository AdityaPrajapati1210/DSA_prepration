//Question1:Print the number of all 7’s that are in the 2d array.
// Example:Input-int arr[][]={{4,7,8},{8,8,7}};n=2,m=3
// Output-2

#include<iostream>
using namespace std;


int main(){
    int m = 2, n = 3;
    int arr[m][n]={{4,7,8},{2,7,7}};
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 7){
                count++;
            }
        }
    }

    cout <<  count <<endl;
}