#include<iostream>
using namespace std;

int* funInt(){
    int *ptr = new int;
    *ptr = 5;
    cout << *ptr << endl;

    return ptr;
}

int main(){
    int *x = funInt();
    cout << *x <<endl;

}