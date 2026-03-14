#include<iostream>
using namespace std;

int powerx(int x , int n){
    if(n == 0) return 1;
    if(n%2 == 0){
        return powerx(x , n/2) * powerx(x ,n/2);
    }else{
        return x * powerx(x ,n/2) * powerx(x,n/2);
    }
}


int main(){
    cout << powerx(2,8) << endl;
}   