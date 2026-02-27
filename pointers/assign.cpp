#include<iostream>
using namespace std;
void mul2(int a,int b,int c){
    a*=2;b*=2;c*=2;
}


int main(){

    // int x;
    // int *ptr;
    // x =7;
    // ptr = &x;
    // cout << *ptr<<endl;

    // int x =1,y=2,z=3;
    // mul2(x,y,z);
    // cout << x<<y<<z<<endl;

    int a = 32;
    int *ptr = &a;

    char ch = 'A';
    char &cho = ch;

    cho += a;
    *ptr += ch;
    cout << a << ", "<< ch << endl;


}