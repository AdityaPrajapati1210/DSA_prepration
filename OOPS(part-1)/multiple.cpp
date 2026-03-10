#include<iostream>
using namespace std;

class Animal {
    public:
    void eat(){
        cout << "Eats..."<<endl;
    }
};

class Fish {
    public:
    void swim(){
        cout << "swim.."<<endl;
    }
};

class Whale : public Fish , public Animal{   //multiple inheritance
    public:
    void size(){
        cout << "Big"<<endl;
    }
};


int main(){
    Whale a;
    a.swim();
    a.size();
    a.eat();
}