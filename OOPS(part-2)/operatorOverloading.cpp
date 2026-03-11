#include<iostream>
using namespace std;

class Complex {
    int real;
    int img;
    public:

    Complex(int r ,int i){
        real = r;
        img = i;
    }

    void show(){
        cout << real <<" + "<<img<<"i"<<endl;
    }
    // Operator Overloading...................................................
    void operator + (Complex &c2){
        int realnum = this->real + c2.real;
        int imgnum = this->img + c2.img;
        
        Complex c3(realnum,imgnum);
        cout <<"Sum : ";
        c3.show();
    }
};

int main(){
    Complex c1(1 ,3);
    Complex c2(5 ,2);
    c1.show();
    c2.show();
    c1 + c2;
}