#include<iostream>
using namespace std;

void getBits(int num , int i){
    int bitMask = 1 << i;

    if((num & bitMask) == 0){
        cout << 0 << endl;
    }else{
        cout << 1 <<endl;
    }
}

int main(){
    int a = 4;
    getBits(a ,1);
}