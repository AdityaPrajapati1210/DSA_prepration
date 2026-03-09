#include <iostream>
using namespace std;

int clearithBit(int num , int i){
    int bitmask = ~0 << i;

    return (num & bitmask);
}

int main() {

    cout << clearithBit(5 , 2) <<endl;
  
}