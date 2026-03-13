#include<iostream>
using namespace std;

class Parent{
    int Secret = 21;

    friend void show(Parent &obj);
    friend class abc;
};

class abc{
    public:
    void secret(Parent obj){
        cout << obj.Secret << endl;
    }
};

void show(Parent &obj){
    cout << obj.Secret <<endl;
};


int main(){
    abc o;
    Parent O;
    show(O);
    o.secret(O);
}