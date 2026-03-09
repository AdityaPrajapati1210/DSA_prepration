#include<iostream>
using namespace std;

int clearBit(int num , int i){
    int bitMask = ~(1 << i);

    return (num & bitMask);
}


int zeroToOne(int num , int i){
    int bitMask = 1 << i;

    return (num | bitMask);
}
int main(){
    int a = 4, val = 0,i = 2;

    if(val == 0){
        cout << zeroToOne(a,i) << endl;
    }
    else{
        cout << clearBit(a,i) << endl;
    }
}