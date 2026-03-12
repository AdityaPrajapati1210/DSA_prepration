#include<iostream>
using namespace std;

// void counter(){
//     int count = 0;
//     count++;
//     cout << count <<endl;
// }


void counter(){
    static int count = 0;  //static variablre create once in a program.
    count++;
    cout << count <<endl;
}

int main(){
    counter();
    counter();
    counter();

    return 0;
}