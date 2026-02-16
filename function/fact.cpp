#include<iostream>
using namespace std;

int fact(int n){
    int  ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    cout << ans << endl;
}
int main(){
    fact(6);
}