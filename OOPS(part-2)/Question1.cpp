#include<iostream>
using namespace std;\

class Complex{
    int real;
    int img;
public:
    Complex(int real ,int img){
        this->real = real;
        this->img = img;
    }

    void show(){
        cout <<real<<" + "<<img<<"i"<<endl;
    }

    // operator overloading
    void operator - (Complex &c2){
        int realnum =  this->real - c2.real;
        int ingnum = this->real - c2.real;
        Complex c3(realnum,ingnum);
        c3.show();
    }
};


int main(){
    Complex c1(1,2);
    Complex c2(3,4);

    c1 - c2;
}
