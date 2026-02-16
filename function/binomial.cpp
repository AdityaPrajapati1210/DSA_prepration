#include<iostream>
using namespace std;

int fact(int n){
    int  ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}


int binomial(int n,int r){
    return fact(n)/(fact(r)*fact(n-r));
    
}
int main(){
    cout << binomial(13,5) <<endl;
}