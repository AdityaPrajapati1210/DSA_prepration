#include<iostream>
using namespace std;

bool isprime( int n){
    if(n == 1) return false;

    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    bool ans = isprime(22);
    cout << ans <<endl;
}