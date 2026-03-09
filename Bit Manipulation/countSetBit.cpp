#include<iostream>
using namespace std;


int count(int num){
    int count = 0;;
    while(num > 0){

        int lastDigit = num & 1;
    
        count += lastDigit;
        num = num >> 1;
    }

    return count;
}

int main(){
    int a = 7;
    cout << count(a) <<endl;
}