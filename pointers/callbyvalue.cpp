#include<iostream>
using namespace std;

void changeA(int a){
    a = 20;
    cout << a <<endl;
}

int main(){

    int a  = 10;
    changeA(a);
    cout << a << endl;

    // output
    // 20
    // 10
    // two differnet result are show.


}