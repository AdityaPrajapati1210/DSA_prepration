#include<iostream>
using namespace std;

class Print{
    public:

    void show(int data){
        cout<<"Integer : ";
        cout << data <<endl;
    }


    void show(double data){
        cout<<"Decimal : ";
        cout << data <<endl;
    }
};

int main(){
    Print obj;
    obj.show(10);
    obj.show(10.2628);
}
