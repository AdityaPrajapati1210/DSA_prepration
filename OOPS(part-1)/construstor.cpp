#include<iostream>
using namespace std;

class Car {
    string model;
    string color;
    public:

    // constructor which called automatically when object is created.
    Car(){
        cout << "Object is created" << endl;
    }
};

int main(){
    Car c1;
}