#include<iostream>
using namespace std;

int main(){
    int m=4,n=4,sum =0;
    int arr[m][n] = {
        {1,2,3,4},
        {4,5,6,4},
        {7,8,9,4},
        {7,8,9,4}
    };

    if(m == n){
        for(int i=0;i<n;i++){
            sum+=arr[i][i];
            if(i != n-i-1){
                sum+=arr[i][n-i-1];
            }
        }
        cout << sum <<endl;
    }else{
        cout <<"!square."<<endl;
    }

    


}