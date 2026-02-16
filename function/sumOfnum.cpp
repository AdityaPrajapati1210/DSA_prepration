#include<iostream>
using namespace std;

void palindrome( int n){
    int copy=n;
    int sum = 0;
    while(n>0){
        int rem = n%10;
        sum +=rem;
        n/=10;
    }
    cout << sum <<endl;
}
int main(){
   palindrome(651);
}