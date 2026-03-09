#include<iostream>
using namespace std;

void powerTwo(int num){
    int bitMask = num & num-1;

    if((bitMask) == 0){
        cout << "Powew of two" << endl;
    }else{
        cout << "No....Try another number" <<endl;
    }
}

int main(){
    int a = 5;
    powerTwo(a);
}