#include <iostream>
using namespace std;

// Function to clear the i-th bit (make it 0)
int clearBit(int num, int i) {
    int bitMask = ~(1 << i);
    return (num & bitMask);
}

// Function to set the i-th bit (make it 1)
int setBit(int num, int i) {
    int bitMask = 1 << i;
    return (num | bitMask);
}

int main() {

    int a = 4;   // number
    int i = 2;   // bit position
    int val = 0; // choose operation

    if(val == 0) {
        cout << "Set bit result: " << setBit(a, i) << endl;
    }
    else {
        cout << "Clear bit result: " << clearBit(a, i) << endl;
    }

    return 0;
}