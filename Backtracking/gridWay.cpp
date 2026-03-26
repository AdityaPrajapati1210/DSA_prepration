#include<iostream>
using namespace std;

int ways(int r , int c,int n, int m){
    if(r == n-1 && c == m-1){
        return 1;
    }
    if(r >= n || c >= m){
        return 0;
    }

    return ways(r , c+1,n, m) + ways(r+1, c,n, m);
}

int main(){
    int n = 4, m = 4;
    cout << ways(0,0,n, m) << endl;
}