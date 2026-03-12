#include<iostream>
using namespace std;

class Parent {
    public:
    void show(){
        cout <<"Parent's shows..."<<endl;
    }

    virtual void hello(){
        cout << "Parent"<<endl;
    }
};
class Child :public Parent {
    public:
    void show(){
        cout <<"Child's shows..."<<endl;
    }

    void hello(){
        cout<<"child"<<endl;
    }
};

int main(){
    Child child1;
    child1.show();
    child1.hello();

    Parent *ptr;
    ptr = &child1;
    ptr->hello();
}