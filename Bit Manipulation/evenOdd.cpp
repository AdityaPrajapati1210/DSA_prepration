#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int lastbit = a & 1;     //check the last bit , if it is 1 the it is a odd number other vise even.
    if(lastbit) cout << "ODD " <<endl;
    else cout << "EVEN" <<endl;
}