#include<iostream>
using namespace std;

void palindrome( int n){
    int copy=n;
    int rev = 0;
    while(n>0){
        int rem = n%10;
        rev = rev*10+rem;
        n/=10;
    }
    if(copy == rev){
       cout <<"True"<<endl;
    }else{
       cout <<"False"<<endl;
    }
}
int main(){
   palindrome(121);
}