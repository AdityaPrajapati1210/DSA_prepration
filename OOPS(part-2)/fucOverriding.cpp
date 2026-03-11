#include<iostream>
using namespace std;

class Parent {
    public:
    void show(){
        cout <<"Parent's shows..."<<endl;
    }
};
class Child :public Parent {
    public:
    void show(){
        cout <<"Child's shows..."<<endl;
    }
};

int main(){
    Child child1;
    child1.show();
}