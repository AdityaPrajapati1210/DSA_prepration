#include<iostream>
using namespace std;

class Shape {
    public:
    virtual void draw() = 0; //pure virtual function or abstract func

};

class circle : public Shape{
    public:
    void draw(){
        cout << "Circle"<<endl;
    }
};

class Sqr : public Shape{
    public:
    void draw(){
        cout << "Sqr"<<endl;
    }
};


int main(){
    Shape *ptr;
    circle c;
    ptr = &c;
    ptr->draw();
    
    Sqr s;
    ptr = &s;
    ptr->draw();
}



