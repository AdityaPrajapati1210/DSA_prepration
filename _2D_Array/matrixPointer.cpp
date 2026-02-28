#include<iostream>
using namespace std;

int main(){
    int m=3,n=3;
    int arr[m][n] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };


    cout << arr <<endl;    //that store the first row address   {1,2,3}
    cout << arr+1 << " != " << &arr[0][1] <<endl;    //that store the first row address   {1,2,3}
    cout << *(*(arr+1)+1) << " == " << arr[1][1] <<endl;    //dereference * use forr value
            //         |
              // ths is column number   'j'
}