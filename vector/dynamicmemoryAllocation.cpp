#include<iostream>
using namespace std;

void funInt(){
    int *ptr = new int;
    *ptr = 5;
    cout << *ptr <<endl;
    delete ptr;
}

void funArr(){
    int size;
    cin >>size;

    int *arr = new int[size];

    int x =1;
    for(int i=0;i<size;i++){
        arr[i] = x;
        cout << x << " ";
        x++;
    }
    delete [] arr;
}

int main(){
    funArr();
    funInt();
    
}