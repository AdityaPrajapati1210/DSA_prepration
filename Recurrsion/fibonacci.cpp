#include<iostream>
using namespace std;

int fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    // cout << fibo(n)<<endl;
    return fibo(n-1) + fibo(n-2);
}

int main(){

    for(int i=0;i<8;i++){
        cout << fibo(i) << " ";

    }
}