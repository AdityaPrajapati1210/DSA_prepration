#include<iostream>
using namespace std;

void print(int n , int lastPlace, string ans){
    if(n == 0){ 
        cout<< ans <<endl;
        return;
    }
    if(lastPlace != 1){
        print(n-1, 0,ans+'0');
        print(n-1, 1,ans+'1');
    }else{
        print(n-1, 0,ans+'0');
    }
}



int main(){
    string ans= "";
    print(3,0,ans);
}