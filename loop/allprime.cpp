#include<iostream>
using namespace std;

 bool isprime(int n){
    int count= 0;
    for(int i=2;i<n/2;i++){
        if(n%i == 0){
            count++;
        }
    }
    if(count >= 1){
        return false;
    }else{
        return true;
    }
 }

int main(){
    int n;
    cout << "Enter a number :";
    cin >> n;

    for(int i=2;i<n;i++){
        if(isprime(i)){
            cout << i <<  endl;
        }
    }


}