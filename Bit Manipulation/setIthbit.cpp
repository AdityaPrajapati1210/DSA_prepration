#include<iostream>
using namespace std;

int setBits(int num , int i){
    int bitMask = 1 << i;

    return (num | bitMask);
}

int main(){
    int a = 4;
    cout << setBits(a ,1) << endl;
}