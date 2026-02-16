#include<iostream>
using namespace std;

bool isEven(int n){
    if(n%2 == 0){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;

    }
}
int main(){
    isEven(12);
}